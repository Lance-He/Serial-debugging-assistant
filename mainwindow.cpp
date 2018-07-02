#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setMaximumSize(501, 359); //设置窗口固定大小
    //查找可用的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Com Name: " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());
            serial.close();
        }
    }

    //循环检测串口定时器
    Timer_loop = new QTimer(this); //开启循环检测串时器
    connect(Timer_loop, SIGNAL(timeout()), this, SLOT(Loop_search()));
    Timer_loop->start(200);

    //设置波特率下拉菜单默认显示第三项
    ui->BaudBox->setCurrentIndex(2);
    //关闭发送按钮的使能
    ui->sendButton->setEnabled(false);

}
void MainWindow::Loop_search() //刷新串口显示函数 //坑爹的玩意，改了好多种方法可算实现无需任何动作,串口热插拔可以自动识别出来
{
    static int num=0;
    static QString change_flag;
    if(ui->PortBox->count() != num) //判断系统检测到串口数量是否与ComboBox下拉列表数量不同
    {
        ui->PortBox->clear();//检测到不同，清除combox内所有数据
    }
    num=0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) //循环检测串口
    {
        num++; //累加串口数量
        if( ui->PortBox->findText(info.portName()) == -1 ) //返回当前com口在下拉框内的索引，没有则返回 -1 并显示com口
             ui->PortBox->addItem(info.portName());
        if((info.portName() == ui->PortBox->currentText()) && (change_flag != ui->PortBox->currentText()))
        {
            ui->textBrowser->clear();
            ui->textBrowser->append("Name："+info.portName());
            ui->textBrowser->append("Description："+info.description());
            ui->textBrowser->append("Manufacturer："+info.manufacturer());

            change_flag=ui->PortBox->currentText();
        }
    }
    if(num == 0) //无串口数据时
        ui->textBrowser->clear(); //清除串口信息内数据


}

MainWindow::~MainWindow()
{
    delete ui;
}

//清空接受窗口
void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

//发送数据
void MainWindow::on_sendButton_clicked()
{
    serial->write(ui->textEdit_2->toPlainText().toLatin1());
}

//读取接收到的数据
void MainWindow::Read_Data()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        QString str = ui->textEdit->toPlainText();
        str+=tr(buf);
        ui->textEdit->clear();
        ui->textEdit->append(str);
    }
    buf.clear();
}

void MainWindow::on_openButton_clicked()
{
    bool isOpenSucc;
    if(ui->openButton->text()==tr("打开串口"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->PortBox->currentText());
        //打开串口
        isOpenSucc=serial->open(QIODevice::ReadWrite);
        if(isOpenSucc==true)
        {
            //设置波特率
            serial->setBaudRate(ui->BaudBox->currentText().toInt());
            //设置数据位数
            switch(ui->BitNumBox->currentIndex())
            {
                case 8: serial->setDataBits(QSerialPort::Data8); break;
                case 7: serial->setDataBits(QSerialPort::Data7); break;
                case 6: serial->setDataBits(QSerialPort::Data6); break;
                case 5: serial->setDataBits(QSerialPort::Data5); break;
                default: break;
            }
            //设置奇偶校验
            if(ui->ParityBox->currentText() == tr("无校验"))
                serial->setParity(QSerialPort::NoParity);
            else if(ui->ParityBox->currentText() == tr("偶校验"))
                serial->setParity(QSerialPort::EvenParity);
            else if(ui->ParityBox->currentText() == tr("奇校验"))
                serial->setParity(QSerialPort::OddParity);
            /*switch(ui->ParityBox->currentIndex())
            {
                case 0: serial->setParity(QSerialPort::NoParity); break;
                default: break;
            }
            */

            //设置停止位
            switch(ui->StopBox->currentIndex())
            {
                case 1: serial->setStopBits(QSerialPort::OneStop); break;
                case 2: serial->setStopBits(QSerialPort::TwoStop); break;
                default: break;
            }
            if(ui->StopBox->currentText() == tr("1.5"))
                serial->setStopBits(QSerialPort::OneAndHalfStop);

            //设置流控制
            serial->setFlowControl(QSerialPort::NoFlowControl);

            //关闭设置菜单使能
            Timer_loop->stop(); //关闭循环检测串口定时器
            ui->PortBox->setEnabled(false);
            ui->BaudBox->setEnabled(false);
            ui->BitNumBox->setEnabled(false);
            ui->ParityBox->setEnabled(false);
            ui->StopBox->setEnabled(false);
            ui->openButton->setText(tr("关闭串口"));
            ui->sendButton->setEnabled(true);

            //连接信号槽
            QObject::connect(serial, &QSerialPort::readyRead, this, &MainWindow::Read_Data);
        }
        else
        {
             QMessageBox::warning(this, tr("Warning"), tr("打开串口失败！"));
        }
    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        //恢复设置使能
        Timer_loop->start(200); //开启循环检测串口定时器
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitNumBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->openButton->setText(tr("打开串口"));
        ui->sendButton->setEnabled(false);
    }
}

void sleep(unsigned int msec) //毫秒级延迟函数

{

QTime dieTime = QTime::currentTime().addMSecs(msec);

while( QTime::currentTime() < dieTime )

QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
