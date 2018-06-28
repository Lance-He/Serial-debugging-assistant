#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //查找可用的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());
            serial.close();
        }
    }

    //循环检测串口定时器  This function will not
    Timer_loop = new QTimer(this); //开启循环检测串时器
    connect(Timer_loop, SIGNAL(timeout()), this, SLOT(Loop_search()));
    Timer_loop->start(700);

    //设置波特率下拉菜单默认显示第三项
    ui->BaudBox->setCurrentIndex(3);
    //关闭发送按钮的使能
    ui->sendButton->setEnabled(false);

}
void MainWindow::Loop_search() //刷新串口显示函数
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if( ui->PortBox->findText(info.portName()) == -1 ) //返回当前com口在下拉框内的索引，没有则返回 -1 并显示com口
             ui->PortBox->addItem(info.portName());
    }
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
            default: break;
            }
            //设置奇偶校验
            switch(ui->ParityBox->currentIndex())
            {
            case 0: serial->setParity(QSerialPort::NoParity); break;
            default: break;
            }
            //设置停止位
            switch(ui->StopBox->currentIndex())
            {
            case 1: serial->setStopBits(QSerialPort::OneStop); break;
            case 2: serial->setStopBits(QSerialPort::TwoStop); break;
            default: break;
            }
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
             ui->PortBox->clear();//清除combox内所有数据
             Loop_search();
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
        Timer_loop->start(700); //开启循环检测串口定时器
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitNumBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->openButton->setText(tr("打开串口"));
        ui->sendButton->setEnabled(false);
    }
}

/*
void MainWindow::showEvent(QShowEvent *event) //重写QComboBox事件
{
    ui->PortBox->clear();//清除combox内所有数据
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if( ui->PortBox->findText(info.portName()) == -1 ) //返回当前com口在下拉框内的索引，没有则返回 -1 并显示com口
                 ui->PortBox->addItem(info.portName());
        }

    QComboBox::showEvent(event);   //交给QComboBox显示
}
*/
