#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>

#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_clearButton_clicked();

    void on_sendButton_clicked();

    void on_openButton_clicked();

    void Read_Data();

    void Loop_search();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *Timer_loop;
};

#endif // MAINWINDOW_H
