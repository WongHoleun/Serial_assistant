/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Hr;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QTextEdit *txtHR;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Spo2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *txtSpo2;
    QGridLayout *gridLayout_10;
    QLabel *label_Bv;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_11;
    QTextEdit *txtDBP;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_14;
    QTextEdit *txtSBP;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Bf;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_12;
    QTextEdit *txtBF;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Mh;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_13;
    QTextEdit *txtMH;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *txtRec;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QPlainTextEdit *txtSend;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QCheckBox *chkSend;
    QPushButton *btnSaveEig;
    QPushButton *btnClearSend;
    QPushButton *pushButton;
    QFrame *frame_4;
    QGridLayout *gridLayout_8;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *lblStop;
    QLabel *lblCheck;
    QComboBox *cmbCheck;
    QComboBox *cmbData;
    QPushButton *btnSwitch;
    QLabel *lblData;
    QComboBox *cmbStop;
    QLabel *lblSwitch;
    QComboBox *cmbBaudRate;
    QLabel *lblBaudRate;
    myComboBox *cmbSerialPort;
    QLabel *lblSerialPort;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QPushButton *btnClearRec;
    QCheckBox *chkRec;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QPushButton *btnSend;
    QCheckBox *chkTimSend;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSendMs;
    QLabel *lblMs;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(839, 710);
        MainWindow->setMinimumSize(QSize(800, 700));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_Hr = new QLabel(widget);
        label_Hr->setObjectName(QString::fromUtf8("label_Hr"));
        label_Hr->setMinimumSize(QSize(40, 60));
        label_Hr->setMaximumSize(QSize(60, 80));

        horizontalLayout_4->addWidget(label_Hr);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(120, 80));
        groupBox->setMaximumSize(QSize(120, 80));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        txtHR = new QTextEdit(groupBox);
        txtHR->setObjectName(QString::fromUtf8("txtHR"));
        txtHR->setMinimumSize(QSize(100, 40));
        txtHR->setMaximumSize(QSize(100, 60));
        QFont font;
        font.setPointSize(20);
        txtHR->setFont(font);
        txtHR->setLayoutDirection(Qt::LeftToRight);

        gridLayout_9->addWidget(txtHR, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_Spo2 = new QLabel(widget);
        label_Spo2->setObjectName(QString::fromUtf8("label_Spo2"));
        label_Spo2->setMinimumSize(QSize(40, 60));
        label_Spo2->setMaximumSize(QSize(60, 80));

        horizontalLayout_3->addWidget(label_Spo2);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(120, 80));
        groupBox_2->setMaximumSize(QSize(120, 80));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtSpo2 = new QTextEdit(groupBox_2);
        txtSpo2->setObjectName(QString::fromUtf8("txtSpo2"));
        txtSpo2->setMinimumSize(QSize(100, 40));
        txtSpo2->setMaximumSize(QSize(100, 60));
        txtSpo2->setFont(font);

        gridLayout_2->addWidget(txtSpo2, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_Bv = new QLabel(widget);
        label_Bv->setObjectName(QString::fromUtf8("label_Bv"));
        label_Bv->setMinimumSize(QSize(40, 120));
        label_Bv->setMaximumSize(QSize(60, 160));

        gridLayout_10->addWidget(label_Bv, 0, 0, 2, 1);

        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(120, 80));
        groupBox_5->setMaximumSize(QSize(120, 80));
        gridLayout_11 = new QGridLayout(groupBox_5);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        txtDBP = new QTextEdit(groupBox_5);
        txtDBP->setObjectName(QString::fromUtf8("txtDBP"));
        txtDBP->setMinimumSize(QSize(100, 40));
        txtDBP->setMaximumSize(QSize(100, 60));
        txtDBP->setFont(font);

        gridLayout_11->addWidget(txtDBP, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 1, 1, 1);

        groupBox_8 = new QGroupBox(widget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setMinimumSize(QSize(120, 80));
        groupBox_8->setMaximumSize(QSize(120, 80));
        gridLayout_14 = new QGridLayout(groupBox_8);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        txtSBP = new QTextEdit(groupBox_8);
        txtSBP->setObjectName(QString::fromUtf8("txtSBP"));
        txtSBP->setMinimumSize(QSize(100, 40));
        txtSBP->setMaximumSize(QSize(100, 60));
        txtSBP->setFont(font);

        gridLayout_14->addWidget(txtSBP, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_8, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_Bf = new QLabel(widget);
        label_Bf->setObjectName(QString::fromUtf8("label_Bf"));
        label_Bf->setMinimumSize(QSize(40, 60));
        label_Bf->setMaximumSize(QSize(60, 80));

        horizontalLayout_5->addWidget(label_Bf);

        groupBox_6 = new QGroupBox(widget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(120, 80));
        groupBox_6->setMaximumSize(QSize(120, 80));
        gridLayout_12 = new QGridLayout(groupBox_6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        txtBF = new QTextEdit(groupBox_6);
        txtBF->setObjectName(QString::fromUtf8("txtBF"));
        txtBF->setMinimumSize(QSize(100, 40));
        txtBF->setMaximumSize(QSize(100, 60));
        txtBF->setFont(font);

        gridLayout_12->addWidget(txtBF, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_Mh = new QLabel(widget);
        label_Mh->setObjectName(QString::fromUtf8("label_Mh"));
        label_Mh->setMinimumSize(QSize(40, 60));
        label_Mh->setMaximumSize(QSize(60, 80));

        horizontalLayout_6->addWidget(label_Mh);

        groupBox_7 = new QGroupBox(widget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(120, 80));
        groupBox_7->setMaximumSize(QSize(120, 80));
        gridLayout_13 = new QGridLayout(groupBox_7);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        txtMH = new QTextEdit(groupBox_7);
        txtMH->setObjectName(QString::fromUtf8("txtMH"));
        txtMH->setMinimumSize(QSize(100, 40));
        txtMH->setMaximumSize(QSize(100, 60));
        txtMH->setFont(font);

        gridLayout_13->addWidget(txtMH, 1, 0, 1, 1);


        horizontalLayout_6->addWidget(groupBox_7);


        verticalLayout->addLayout(horizontalLayout_6);


        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, -1, 0, -1);
        txtRec = new QPlainTextEdit(groupBox_3);
        txtRec->setObjectName(QString::fromUtf8("txtRec"));
        txtRec->setReadOnly(true);

        gridLayout_6->addWidget(txtRec, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 100));
        groupBox_4->setMaximumSize(QSize(16777215, 100));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, -1, 0, -1);
        txtSend = new QPlainTextEdit(groupBox_4);
        txtSend->setObjectName(QString::fromUtf8("txtSend"));
        txtSend->setMinimumSize(QSize(0, 0));
        txtSend->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_7->addWidget(txtSend, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 1, 0, 1, 2);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(240, 0));
        frame->setMaximumSize(QSize(240, 16777215));
        frame->setFocusPolicy(Qt::NoFocus);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        chkSend = new QCheckBox(frame);
        chkSend->setObjectName(QString::fromUtf8("chkSend"));
        chkSend->setMinimumSize(QSize(100, 0));
        chkSend->setChecked(true);

        gridLayout_3->addWidget(chkSend, 7, 2, 1, 1);

        btnSaveEig = new QPushButton(frame);
        btnSaveEig->setObjectName(QString::fromUtf8("btnSaveEig"));

        gridLayout_3->addWidget(btnSaveEig, 4, 0, 1, 3);

        btnClearSend = new QPushButton(frame);
        btnClearSend->setObjectName(QString::fromUtf8("btnClearSend"));

        gridLayout_3->addWidget(btnClearSend, 6, 2, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 5, 0, 1, 3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(0, 220));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        gridLayout_8 = new QGridLayout(frame_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        widget_2 = new QWidget(frame_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblStop = new QLabel(widget_2);
        lblStop->setObjectName(QString::fromUtf8("lblStop"));

        gridLayout->addWidget(lblStop, 1, 0, 1, 1);

        lblCheck = new QLabel(widget_2);
        lblCheck->setObjectName(QString::fromUtf8("lblCheck"));

        gridLayout->addWidget(lblCheck, 3, 0, 1, 1);

        cmbCheck = new QComboBox(widget_2);
        cmbCheck->addItem(QString());
        cmbCheck->addItem(QString());
        cmbCheck->addItem(QString());
        cmbCheck->setObjectName(QString::fromUtf8("cmbCheck"));

        gridLayout->addWidget(cmbCheck, 3, 1, 1, 1);

        cmbData = new QComboBox(widget_2);
        cmbData->addItem(QString());
        cmbData->addItem(QString());
        cmbData->addItem(QString());
        cmbData->addItem(QString());
        cmbData->setObjectName(QString::fromUtf8("cmbData"));

        gridLayout->addWidget(cmbData, 2, 1, 1, 1);

        btnSwitch = new QPushButton(widget_2);
        btnSwitch->setObjectName(QString::fromUtf8("btnSwitch"));

        gridLayout->addWidget(btnSwitch, 4, 1, 1, 1);

        lblData = new QLabel(widget_2);
        lblData->setObjectName(QString::fromUtf8("lblData"));

        gridLayout->addWidget(lblData, 2, 0, 1, 1);

        cmbStop = new QComboBox(widget_2);
        cmbStop->addItem(QString());
        cmbStop->addItem(QString());
        cmbStop->addItem(QString());
        cmbStop->setObjectName(QString::fromUtf8("cmbStop"));

        gridLayout->addWidget(cmbStop, 1, 1, 1, 1);

        lblSwitch = new QLabel(widget_2);
        lblSwitch->setObjectName(QString::fromUtf8("lblSwitch"));

        gridLayout->addWidget(lblSwitch, 4, 0, 1, 1);

        cmbBaudRate = new QComboBox(widget_2);
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->addItem(QString());
        cmbBaudRate->setObjectName(QString::fromUtf8("cmbBaudRate"));
        cmbBaudRate->setEditable(true);
        cmbBaudRate->setMaxVisibleItems(20);

        gridLayout->addWidget(cmbBaudRate, 0, 1, 1, 1);

        lblBaudRate = new QLabel(widget_2);
        lblBaudRate->setObjectName(QString::fromUtf8("lblBaudRate"));

        gridLayout->addWidget(lblBaudRate, 0, 0, 1, 1);


        gridLayout_8->addWidget(widget_2, 2, 0, 1, 1);

        cmbSerialPort = new myComboBox(frame_4);
        cmbSerialPort->setObjectName(QString::fromUtf8("cmbSerialPort"));

        gridLayout_8->addWidget(cmbSerialPort, 1, 0, 1, 1);

        lblSerialPort = new QLabel(frame_4);
        lblSerialPort->setObjectName(QString::fromUtf8("lblSerialPort"));

        gridLayout_8->addWidget(lblSerialPort, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_4, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 80));
        label->setMaximumSize(QSize(80, 80));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Sun_Yat-sen_University_Logo.png);"));

        gridLayout_3->addWidget(label, 1, 1, 1, 1);

        btnClearRec = new QPushButton(frame);
        btnClearRec->setObjectName(QString::fromUtf8("btnClearRec"));

        gridLayout_3->addWidget(btnClearRec, 6, 0, 1, 2);

        chkRec = new QCheckBox(frame);
        chkRec->setObjectName(QString::fromUtf8("chkRec"));
        chkRec->setEnabled(true);
        chkRec->setMaximumSize(QSize(100, 16777215));
        chkRec->setChecked(true);

        gridLayout_3->addWidget(chkRec, 7, 0, 1, 2);


        gridLayout_4->addWidget(frame, 0, 2, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(240, 100));
        frame_2->setMaximumSize(QSize(240, 100));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        btnSend = new QPushButton(frame_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setMinimumSize(QSize(0, 60));
        btnSend->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(btnSend, 0, 0, 2, 1);

        chkTimSend = new QCheckBox(frame_2);
        chkTimSend->setObjectName(QString::fromUtf8("chkTimSend"));
        chkTimSend->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(chkTimSend, 1, 1, 1, 1);

        widget_4 = new QWidget(frame_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 50));
        widget_4->setMaximumSize(QSize(100, 16777215));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        txtSendMs = new QLineEdit(widget_4);
        txtSendMs->setObjectName(QString::fromUtf8("txtSendMs"));
        txtSendMs->setMinimumSize(QSize(40, 0));
        txtSendMs->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(txtSendMs);

        lblMs = new QLabel(widget_4);
        lblMs->setObjectName(QString::fromUtf8("lblMs"));
        lblMs->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setPointSize(12);
        lblMs->setFont(font1);

        horizontalLayout->addWidget(lblMs);


        gridLayout_5->addWidget(widget_4, 0, 1, 1, 1);


        gridLayout_4->addWidget(frame_2, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 839, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setMinimumSize(QSize(0, 22));
        statusbar->setMaximumSize(QSize(16777215, 22));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        cmbData->setCurrentIndex(3);
        cmbBaudRate->setCurrentIndex(10);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        label_Hr->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\204\211\346\220\217", nullptr));
        txtHR->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:24pt;\"><br /></p></body></html>", nullptr));
        label_Spo2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\241\200\346\260\247", nullptr));
        txtSpo2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:24pt;\"><br /></p></body></html>", nullptr));
        label_Bv->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\350\210\222\345\274\240\345\216\213", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\346\224\266\347\274\251\345\216\213", nullptr));
        label_Bf->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\350\241\200\346\265\201", nullptr));
        label_Mh->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\344\273\243\350\260\242\347\203\255", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\225\260\346\215\256 - \346\216\245\346\224\266\345\214\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\225\260\346\215\256 - \345\217\221\351\200\201\345\214\272", nullptr));
        txtSend->setPlainText(QCoreApplication::translate("MainWindow", "AA", nullptr));
        chkSend->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        btnSaveEig->setText(QCoreApplication::translate("MainWindow", "\347\211\271\345\276\201\345\200\274\344\277\235\345\255\230", nullptr));
        btnClearSend->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\263\242\345\275\242\347\225\214\351\235\242", nullptr));
        lblStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        lblCheck->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        cmbCheck->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        cmbCheck->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        cmbCheck->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        cmbData->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        cmbData->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        cmbData->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        cmbData->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        btnSwitch->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        lblData->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        cmbStop->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmbStop->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        cmbStop->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        lblSwitch->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
        cmbBaudRate->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        cmbBaudRate->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        cmbBaudRate->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        cmbBaudRate->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cmbBaudRate->setItemText(4, QCoreApplication::translate("MainWindow", "14400", nullptr));
        cmbBaudRate->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cmbBaudRate->setItemText(6, QCoreApplication::translate("MainWindow", "38400", nullptr));
        cmbBaudRate->setItemText(7, QCoreApplication::translate("MainWindow", "43000", nullptr));
        cmbBaudRate->setItemText(8, QCoreApplication::translate("MainWindow", "57600", nullptr));
        cmbBaudRate->setItemText(9, QCoreApplication::translate("MainWindow", "76800", nullptr));
        cmbBaudRate->setItemText(10, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cmbBaudRate->setItemText(11, QCoreApplication::translate("MainWindow", "128000", nullptr));
        cmbBaudRate->setItemText(12, QCoreApplication::translate("MainWindow", "230400", nullptr));
        cmbBaudRate->setItemText(13, QCoreApplication::translate("MainWindow", "256000", nullptr));
        cmbBaudRate->setItemText(14, QCoreApplication::translate("MainWindow", "460800", nullptr));
        cmbBaudRate->setItemText(15, QCoreApplication::translate("MainWindow", "921600", nullptr));
        cmbBaudRate->setItemText(16, QCoreApplication::translate("MainWindow", "1382400", nullptr));

        lblBaudRate->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        lblSerialPort->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        label->setText(QString());
        btnClearRec->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266/\347\273\237\350\256\241", nullptr));
#if QT_CONFIG(accessibility)
        chkRec->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        chkRec->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        chkTimSend->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        txtSendMs->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        lblMs->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
