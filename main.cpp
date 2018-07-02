#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("串口调试助手 v1.3"); //修改标题
    w.show();

    return a.exec();
}
