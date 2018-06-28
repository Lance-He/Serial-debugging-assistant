#ifndef MYBOBOX_H
#define MYBOBOX_H
#include <QComboBox>
#include <QWidget>
#include <QMessageBox>

class myboBox : public QComboBox
{
    Q_OBJECT

public:
    myboBox(QWidget*parent=0);
protected:
    //鼠标移动事件
    void mousePressEvent(QMouseEvent *event);
signals:
    void clicked(bool);


};

#endif // MYBOBOX_H
