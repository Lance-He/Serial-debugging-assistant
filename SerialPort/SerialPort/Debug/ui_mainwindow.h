/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *openButton;
    QLabel *label_3;
    QComboBox *PortBox;
    QLabel *label_4;
    QComboBox *BaudBox;
    QLabel *label_5;
    QComboBox *BitNumBox;
    QLabel *label_6;
    QComboBox *ParityBox;
    QLabel *label_7;
    QComboBox *StopBox;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QTextEdit *textEdit;
    QFormLayout *formLayout;
    QLabel *label_2;
    QTextEdit *textEdit_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 313);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 0, 0, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        PortBox = new QComboBox(centralWidget);
        PortBox->setObjectName(QStringLiteral("PortBox"));

        gridLayout->addWidget(PortBox, 1, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        BaudBox = new QComboBox(centralWidget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QStringLiteral("BaudBox"));

        gridLayout->addWidget(BaudBox, 2, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        BitNumBox = new QComboBox(centralWidget);
        BitNumBox->addItem(QString());
        BitNumBox->setObjectName(QStringLiteral("BitNumBox"));

        gridLayout->addWidget(BitNumBox, 3, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        ParityBox = new QComboBox(centralWidget);
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QStringLiteral("ParityBox"));

        gridLayout->addWidget(ParityBox, 4, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        StopBox = new QComboBox(centralWidget);
        StopBox->addItem(QString());
        StopBox->addItem(QString());
        StopBox->setObjectName(QStringLiteral("StopBox"));

        gridLayout->addWidget(StopBox, 5, 1, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 6, 0, 1, 2);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 7, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 2, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_3->addWidget(textEdit, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, textEdit_2);


        gridLayout_2->addLayout(formLayout, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudBox->setItemText(0, QApplication::translate("MainWindow", "1200", nullptr));
        BaudBox->setItemText(1, QApplication::translate("MainWindow", "2400", nullptr));
        BaudBox->setItemText(2, QApplication::translate("MainWindow", "4800", nullptr));
        BaudBox->setItemText(3, QApplication::translate("MainWindow", "9600", nullptr));
        BaudBox->setItemText(4, QApplication::translate("MainWindow", "19200", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        BitNumBox->setItemText(0, QApplication::translate("MainWindow", "8", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        ParityBox->setItemText(0, QApplication::translate("MainWindow", "0", nullptr));

        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        StopBox->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        StopBox->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));

        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
