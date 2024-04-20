/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_H
#define UI_PLOT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Plot
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QCustomPlot *winPlot;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QToolBox *toolBox;
    QWidget *page_1;
    QVBoxLayout *verticalLayout;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *chkVisibleCurve1;
    QPushButton *btnColourCurve1;
    QRadioButton *rdoBoldCurve1;
    QLineEdit *txtValueCurve1;
    QComboBox *cmbLineStyle1;
    QComboBox *cmbScatterStyle1;
    QFrame *line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *chkVisibleCurve2;
    QPushButton *btnColourCurve2;
    QRadioButton *rdoBoldCurve2;
    QLineEdit *txtValueCurve2;
    QComboBox *cmbLineStyle2;
    QComboBox *cmbScatterStyle2;
    QFrame *line_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *chkVisibleCurve3;
    QPushButton *btnColourCurve3;
    QRadioButton *rdoBoldCurve3;
    QLineEdit *txtValueCurve3;
    QComboBox *cmbLineStyle3;
    QComboBox *cmbScatterStyle3;
    QFrame *line_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chkVisibleCurve4;
    QPushButton *btnColourCurve4;
    QRadioButton *rdoBoldCurve4;
    QLineEdit *txtValueCurve4;
    QComboBox *cmbLineStyle4;
    QComboBox *cmbScatterStyle4;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *chkShowLegend;
    QPushButton *btnSaveData;
    QPushButton *btnColourBack;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *txtMainScaleNumY;
    QPushButton *btnResetSettings;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *txtMainScaleNumX;
    QPushButton *btnClearGraphs;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QCheckBox *chkTrackX;
    QFrame *FramePagePoint;
    QGridLayout *gridLayout_2;
    QLabel *lblPointOrigin;
    QLabel *lblPointCount;
    QLabel *lblPointCountX;
    QLineEdit *txtPointOriginX;
    QLineEdit *txtPointCountX;
    QLabel *lblPointCountY;
    QLineEdit *txtPointOriginY;
    QLineEdit *txtPointCountY;
    QCheckBox *chkAdjustY;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Plot)
    {
        if (Plot->objectName().isEmpty())
            Plot->setObjectName(QString::fromUtf8("Plot"));
        Plot->resize(1215, 683);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Plot->sizePolicy().hasHeightForWidth());
        Plot->setSizePolicy(sizePolicy);
        Plot->setMinimumSize(QSize(1215, 683));
        Plot->setMaximumSize(QSize(12150, 6830));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Plot->setWindowIcon(icon);
        centralwidget = new QWidget(Plot);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        winPlot = new QCustomPlot(centralwidget);
        winPlot->setObjectName(QString::fromUtf8("winPlot"));
        winPlot->setMinimumSize(QSize(700, 600));
        winPlot->setMaximumSize(QSize(700, 600));

        gridLayout->addWidget(winPlot, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(480, 600));
        frame_2->setMaximumSize(QSize(480, 600));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        toolBox = new QToolBox(frame_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        toolBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBox->setStyleSheet(QString::fromUtf8(""));
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setFrameShadow(QFrame::Sunken);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 0, 446, 401));
        verticalLayout = new QVBoxLayout(page_1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_1 = new QWidget(page_1);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(420, 22));
        widget_1->setMaximumSize(QSize(420, 16777215));
        horizontalLayout_3 = new QHBoxLayout(widget_1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        chkVisibleCurve1 = new QCheckBox(widget_1);
        chkVisibleCurve1->setObjectName(QString::fromUtf8("chkVisibleCurve1"));
        chkVisibleCurve1->setChecked(true);

        horizontalLayout_3->addWidget(chkVisibleCurve1);

        btnColourCurve1 = new QPushButton(widget_1);
        btnColourCurve1->setObjectName(QString::fromUtf8("btnColourCurve1"));

        horizontalLayout_3->addWidget(btnColourCurve1);

        rdoBoldCurve1 = new QRadioButton(widget_1);
        rdoBoldCurve1->setObjectName(QString::fromUtf8("rdoBoldCurve1"));
        rdoBoldCurve1->setChecked(false);

        horizontalLayout_3->addWidget(rdoBoldCurve1);

        txtValueCurve1 = new QLineEdit(widget_1);
        txtValueCurve1->setObjectName(QString::fromUtf8("txtValueCurve1"));
        txtValueCurve1->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(txtValueCurve1);

        cmbLineStyle1 = new QComboBox(widget_1);
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->addItem(QString());
        cmbLineStyle1->setObjectName(QString::fromUtf8("cmbLineStyle1"));

        horizontalLayout_3->addWidget(cmbLineStyle1);

        cmbScatterStyle1 = new QComboBox(widget_1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/ssNone.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/ssCross.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/ssPlus.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/ssCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/pic/ssDisc.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/pic/ssSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/pic/ssDiamond.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/pic/ssStar.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/pic/ssTriangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/pic/ssTriangleInverted.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/pic/ssCrossSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon11, QString());
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/pic/ssPlusSquare.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon12, QString());
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/pic/ssCrossCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon13, QString());
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/pic/ssPlusCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon14, QString());
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/pic/ssPeace.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmbScatterStyle1->addItem(icon15, QString());
        cmbScatterStyle1->setObjectName(QString::fromUtf8("cmbScatterStyle1"));
        cmbScatterStyle1->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle1->setMaxVisibleItems(20);

        horizontalLayout_3->addWidget(cmbScatterStyle1);


        verticalLayout->addWidget(widget_1);

        line = new QFrame(page_1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget_2 = new QWidget(page_1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(420, 22));
        widget_2->setMaximumSize(QSize(420, 16777215));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        chkVisibleCurve2 = new QCheckBox(widget_2);
        chkVisibleCurve2->setObjectName(QString::fromUtf8("chkVisibleCurve2"));
        chkVisibleCurve2->setChecked(true);

        horizontalLayout_4->addWidget(chkVisibleCurve2);

        btnColourCurve2 = new QPushButton(widget_2);
        btnColourCurve2->setObjectName(QString::fromUtf8("btnColourCurve2"));

        horizontalLayout_4->addWidget(btnColourCurve2);

        rdoBoldCurve2 = new QRadioButton(widget_2);
        rdoBoldCurve2->setObjectName(QString::fromUtf8("rdoBoldCurve2"));
        rdoBoldCurve2->setChecked(false);

        horizontalLayout_4->addWidget(rdoBoldCurve2);

        txtValueCurve2 = new QLineEdit(widget_2);
        txtValueCurve2->setObjectName(QString::fromUtf8("txtValueCurve2"));
        txtValueCurve2->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(txtValueCurve2);

        cmbLineStyle2 = new QComboBox(widget_2);
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->addItem(QString());
        cmbLineStyle2->setObjectName(QString::fromUtf8("cmbLineStyle2"));

        horizontalLayout_4->addWidget(cmbLineStyle2);

        cmbScatterStyle2 = new QComboBox(widget_2);
        cmbScatterStyle2->addItem(icon1, QString());
        cmbScatterStyle2->addItem(icon2, QString());
        cmbScatterStyle2->addItem(icon3, QString());
        cmbScatterStyle2->addItem(icon4, QString());
        cmbScatterStyle2->addItem(icon5, QString());
        cmbScatterStyle2->addItem(icon6, QString());
        cmbScatterStyle2->addItem(icon7, QString());
        cmbScatterStyle2->addItem(icon8, QString());
        cmbScatterStyle2->addItem(icon9, QString());
        cmbScatterStyle2->addItem(icon10, QString());
        cmbScatterStyle2->addItem(icon11, QString());
        cmbScatterStyle2->addItem(icon12, QString());
        cmbScatterStyle2->addItem(icon13, QString());
        cmbScatterStyle2->addItem(icon14, QString());
        cmbScatterStyle2->addItem(icon15, QString());
        cmbScatterStyle2->setObjectName(QString::fromUtf8("cmbScatterStyle2"));
        cmbScatterStyle2->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle2->setMaxVisibleItems(20);

        horizontalLayout_4->addWidget(cmbScatterStyle2);


        verticalLayout->addWidget(widget_2);

        line_2 = new QFrame(page_1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        widget_3 = new QWidget(page_1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(420, 22));
        widget_3->setMaximumSize(QSize(420, 16777215));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        chkVisibleCurve3 = new QCheckBox(widget_3);
        chkVisibleCurve3->setObjectName(QString::fromUtf8("chkVisibleCurve3"));
        chkVisibleCurve3->setChecked(false);

        horizontalLayout_5->addWidget(chkVisibleCurve3);

        btnColourCurve3 = new QPushButton(widget_3);
        btnColourCurve3->setObjectName(QString::fromUtf8("btnColourCurve3"));

        horizontalLayout_5->addWidget(btnColourCurve3);

        rdoBoldCurve3 = new QRadioButton(widget_3);
        rdoBoldCurve3->setObjectName(QString::fromUtf8("rdoBoldCurve3"));
        rdoBoldCurve3->setChecked(false);

        horizontalLayout_5->addWidget(rdoBoldCurve3);

        txtValueCurve3 = new QLineEdit(widget_3);
        txtValueCurve3->setObjectName(QString::fromUtf8("txtValueCurve3"));
        txtValueCurve3->setMinimumSize(QSize(80, 0));

        horizontalLayout_5->addWidget(txtValueCurve3);

        cmbLineStyle3 = new QComboBox(widget_3);
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->addItem(QString());
        cmbLineStyle3->setObjectName(QString::fromUtf8("cmbLineStyle3"));

        horizontalLayout_5->addWidget(cmbLineStyle3);

        cmbScatterStyle3 = new QComboBox(widget_3);
        cmbScatterStyle3->addItem(icon1, QString());
        cmbScatterStyle3->addItem(icon2, QString());
        cmbScatterStyle3->addItem(icon3, QString());
        cmbScatterStyle3->addItem(icon4, QString());
        cmbScatterStyle3->addItem(icon5, QString());
        cmbScatterStyle3->addItem(icon6, QString());
        cmbScatterStyle3->addItem(icon7, QString());
        cmbScatterStyle3->addItem(icon8, QString());
        cmbScatterStyle3->addItem(icon9, QString());
        cmbScatterStyle3->addItem(icon10, QString());
        cmbScatterStyle3->addItem(icon11, QString());
        cmbScatterStyle3->addItem(icon12, QString());
        cmbScatterStyle3->addItem(icon13, QString());
        cmbScatterStyle3->addItem(icon14, QString());
        cmbScatterStyle3->addItem(icon15, QString());
        cmbScatterStyle3->setObjectName(QString::fromUtf8("cmbScatterStyle3"));
        cmbScatterStyle3->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle3->setMaxVisibleItems(20);

        horizontalLayout_5->addWidget(cmbScatterStyle3);


        verticalLayout->addWidget(widget_3);

        line_3 = new QFrame(page_1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        widget_4 = new QWidget(page_1);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(420, 22));
        widget_4->setMaximumSize(QSize(420, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        chkVisibleCurve4 = new QCheckBox(widget_4);
        chkVisibleCurve4->setObjectName(QString::fromUtf8("chkVisibleCurve4"));
        chkVisibleCurve4->setChecked(false);

        horizontalLayout_6->addWidget(chkVisibleCurve4);

        btnColourCurve4 = new QPushButton(widget_4);
        btnColourCurve4->setObjectName(QString::fromUtf8("btnColourCurve4"));

        horizontalLayout_6->addWidget(btnColourCurve4);

        rdoBoldCurve4 = new QRadioButton(widget_4);
        rdoBoldCurve4->setObjectName(QString::fromUtf8("rdoBoldCurve4"));
        rdoBoldCurve4->setChecked(false);

        horizontalLayout_6->addWidget(rdoBoldCurve4);

        txtValueCurve4 = new QLineEdit(widget_4);
        txtValueCurve4->setObjectName(QString::fromUtf8("txtValueCurve4"));
        txtValueCurve4->setMinimumSize(QSize(80, 0));

        horizontalLayout_6->addWidget(txtValueCurve4);

        cmbLineStyle4 = new QComboBox(widget_4);
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->addItem(QString());
        cmbLineStyle4->setObjectName(QString::fromUtf8("cmbLineStyle4"));

        horizontalLayout_6->addWidget(cmbLineStyle4);

        cmbScatterStyle4 = new QComboBox(widget_4);
        cmbScatterStyle4->addItem(icon1, QString());
        cmbScatterStyle4->addItem(icon2, QString());
        cmbScatterStyle4->addItem(icon3, QString());
        cmbScatterStyle4->addItem(icon4, QString());
        cmbScatterStyle4->addItem(icon5, QString());
        cmbScatterStyle4->addItem(icon6, QString());
        cmbScatterStyle4->addItem(icon7, QString());
        cmbScatterStyle4->addItem(icon8, QString());
        cmbScatterStyle4->addItem(icon9, QString());
        cmbScatterStyle4->addItem(icon10, QString());
        cmbScatterStyle4->addItem(icon11, QString());
        cmbScatterStyle4->addItem(icon12, QString());
        cmbScatterStyle4->addItem(icon13, QString());
        cmbScatterStyle4->addItem(icon14, QString());
        cmbScatterStyle4->addItem(icon15, QString());
        cmbScatterStyle4->setObjectName(QString::fromUtf8("cmbScatterStyle4"));
        cmbScatterStyle4->setFocusPolicy(Qt::WheelFocus);
        cmbScatterStyle4->setMaxVisibleItems(20);

        horizontalLayout_6->addWidget(cmbScatterStyle4);


        verticalLayout->addWidget(widget_4);

        line_4 = new QFrame(page_1);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        chkShowLegend = new QCheckBox(page_1);
        chkShowLegend->setObjectName(QString::fromUtf8("chkShowLegend"));
        chkShowLegend->setMinimumSize(QSize(20, 21));
        chkShowLegend->setChecked(true);

        horizontalLayout_8->addWidget(chkShowLegend);

        btnSaveData = new QPushButton(page_1);
        btnSaveData->setObjectName(QString::fromUtf8("btnSaveData"));

        horizontalLayout_8->addWidget(btnSaveData);

        btnColourBack = new QPushButton(page_1);
        btnColourBack->setObjectName(QString::fromUtf8("btnColourBack"));
        btnColourBack->setMinimumSize(QSize(21, 21));
        btnColourBack->setMaximumSize(QSize(21, 21));

        horizontalLayout_8->addWidget(btnColourBack);

        label = new QLabel(page_1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(page_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        txtMainScaleNumY = new QLineEdit(page_1);
        txtMainScaleNumY->setObjectName(QString::fromUtf8("txtMainScaleNumY"));
        txtMainScaleNumY->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_2->addWidget(txtMainScaleNumY);

        btnResetSettings = new QPushButton(page_1);
        btnResetSettings->setObjectName(QString::fromUtf8("btnResetSettings"));

        horizontalLayout_2->addWidget(btnResetSettings);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        label_2 = new QLabel(page_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        txtMainScaleNumX = new QLineEdit(page_1);
        txtMainScaleNumX->setObjectName(QString::fromUtf8("txtMainScaleNumX"));
        txtMainScaleNumX->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(txtMainScaleNumX);

        btnClearGraphs = new QPushButton(page_1);
        btnClearGraphs->setObjectName(QString::fromUtf8("btnClearGraphs"));

        horizontalLayout->addWidget(btnClearGraphs);


        verticalLayout->addLayout(horizontalLayout);

        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/chart_curve_32px_506507_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page_1, icon16, QString::fromUtf8("\346\233\262\347\272\277\350\256\276\347\275\256"));

        verticalLayout_2->addWidget(toolBox);

        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        chkTrackX = new QCheckBox(frame);
        chkTrackX->setObjectName(QString::fromUtf8("chkTrackX"));
        chkTrackX->setChecked(true);

        gridLayout_3->addWidget(chkTrackX, 0, 0, 1, 1);

        FramePagePoint = new QFrame(frame);
        FramePagePoint->setObjectName(QString::fromUtf8("FramePagePoint"));
        FramePagePoint->setMinimumSize(QSize(200, 95));
        FramePagePoint->setMaximumSize(QSize(250, 16777215));
        FramePagePoint->setFrameShape(QFrame::WinPanel);
        FramePagePoint->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(FramePagePoint);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblPointOrigin = new QLabel(FramePagePoint);
        lblPointOrigin->setObjectName(QString::fromUtf8("lblPointOrigin"));

        gridLayout_2->addWidget(lblPointOrigin, 0, 1, 1, 1);

        lblPointCount = new QLabel(FramePagePoint);
        lblPointCount->setObjectName(QString::fromUtf8("lblPointCount"));

        gridLayout_2->addWidget(lblPointCount, 0, 2, 1, 1);

        lblPointCountX = new QLabel(FramePagePoint);
        lblPointCountX->setObjectName(QString::fromUtf8("lblPointCountX"));

        gridLayout_2->addWidget(lblPointCountX, 1, 0, 1, 1);

        txtPointOriginX = new QLineEdit(FramePagePoint);
        txtPointOriginX->setObjectName(QString::fromUtf8("txtPointOriginX"));
        txtPointOriginX->setMinimumSize(QSize(81, 20));
        txtPointOriginX->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointOriginX, 1, 1, 1, 1);

        txtPointCountX = new QLineEdit(FramePagePoint);
        txtPointCountX->setObjectName(QString::fromUtf8("txtPointCountX"));
        txtPointCountX->setMinimumSize(QSize(81, 20));
        txtPointCountX->setMaximumSize(QSize(81, 20));
        txtPointCountX->setFocusPolicy(Qt::StrongFocus);

        gridLayout_2->addWidget(txtPointCountX, 1, 2, 1, 1);

        lblPointCountY = new QLabel(FramePagePoint);
        lblPointCountY->setObjectName(QString::fromUtf8("lblPointCountY"));

        gridLayout_2->addWidget(lblPointCountY, 2, 0, 1, 1);

        txtPointOriginY = new QLineEdit(FramePagePoint);
        txtPointOriginY->setObjectName(QString::fromUtf8("txtPointOriginY"));
        txtPointOriginY->setMinimumSize(QSize(81, 20));
        txtPointOriginY->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointOriginY, 2, 1, 1, 1);

        txtPointCountY = new QLineEdit(FramePagePoint);
        txtPointCountY->setObjectName(QString::fromUtf8("txtPointCountY"));
        txtPointCountY->setMinimumSize(QSize(81, 20));
        txtPointCountY->setMaximumSize(QSize(81, 20));

        gridLayout_2->addWidget(txtPointCountY, 2, 2, 1, 1);


        gridLayout_3->addWidget(FramePagePoint, 0, 1, 2, 1);

        chkAdjustY = new QCheckBox(frame);
        chkAdjustY->setObjectName(QString::fromUtf8("chkAdjustY"));
        chkAdjustY->setChecked(true);

        gridLayout_3->addWidget(chkAdjustY, 1, 0, 1, 1);


        verticalLayout_2->addWidget(frame);


        gridLayout->addWidget(frame_2, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 3, 1, 1);

        Plot->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Plot);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1215, 29));
        Plot->setMenuBar(menubar);
        statusbar = new QStatusBar(Plot);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Plot->setStatusBar(statusbar);

        retranslateUi(Plot);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);
        cmbLineStyle1->setCurrentIndex(1);
        cmbLineStyle2->setCurrentIndex(1);
        cmbLineStyle3->setCurrentIndex(1);
        cmbLineStyle4->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Plot);
    } // setupUi

    void retranslateUi(QMainWindow *Plot)
    {
        Plot->setWindowTitle(QString());
        chkVisibleCurve1->setText(QCoreApplication::translate("Plot", "\346\263\242\345\275\2421", nullptr));
        btnColourCurve1->setText(QString());
        rdoBoldCurve1->setText(QString());
        txtValueCurve1->setText(QString());
        cmbLineStyle1->setItemText(0, QCoreApplication::translate("Plot", "\347\202\271", nullptr));
        cmbLineStyle1->setItemText(1, QCoreApplication::translate("Plot", "\347\272\277", nullptr));
        cmbLineStyle1->setItemText(2, QCoreApplication::translate("Plot", "\345\267\246", nullptr));
        cmbLineStyle1->setItemText(3, QCoreApplication::translate("Plot", "\345\217\263", nullptr));
        cmbLineStyle1->setItemText(4, QCoreApplication::translate("Plot", "\344\270\255", nullptr));
        cmbLineStyle1->setItemText(5, QCoreApplication::translate("Plot", "\347\247\257", nullptr));

        cmbScatterStyle1->setItemText(0, QCoreApplication::translate("Plot", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle1->setItemText(1, QCoreApplication::translate("Plot", "x\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(2, QCoreApplication::translate("Plot", "+\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(3, QCoreApplication::translate("Plot", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(4, QCoreApplication::translate("Plot", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(5, QCoreApplication::translate("Plot", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(6, QCoreApplication::translate("Plot", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(7, QCoreApplication::translate("Plot", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle1->setItemText(8, QCoreApplication::translate("Plot", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle1->setItemText(9, QCoreApplication::translate("Plot", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle1->setItemText(10, QCoreApplication::translate("Plot", "x\346\241\206", nullptr));
        cmbScatterStyle1->setItemText(11, QCoreApplication::translate("Plot", "+\346\241\206", nullptr));
        cmbScatterStyle1->setItemText(12, QCoreApplication::translate("Plot", "x\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(13, QCoreApplication::translate("Plot", "+\345\234\206", nullptr));
        cmbScatterStyle1->setItemText(14, QCoreApplication::translate("Plot", "\345\222\214\345\271\263", nullptr));

        chkVisibleCurve2->setText(QCoreApplication::translate("Plot", "\346\263\242\345\275\2422", nullptr));
        btnColourCurve2->setText(QString());
        rdoBoldCurve2->setText(QString());
        txtValueCurve2->setText(QString());
        cmbLineStyle2->setItemText(0, QCoreApplication::translate("Plot", "\347\202\271", nullptr));
        cmbLineStyle2->setItemText(1, QCoreApplication::translate("Plot", "\347\272\277", nullptr));
        cmbLineStyle2->setItemText(2, QCoreApplication::translate("Plot", "\345\267\246", nullptr));
        cmbLineStyle2->setItemText(3, QCoreApplication::translate("Plot", "\345\217\263", nullptr));
        cmbLineStyle2->setItemText(4, QCoreApplication::translate("Plot", "\344\270\255", nullptr));
        cmbLineStyle2->setItemText(5, QCoreApplication::translate("Plot", "\347\247\257", nullptr));

        cmbScatterStyle2->setItemText(0, QCoreApplication::translate("Plot", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle2->setItemText(1, QCoreApplication::translate("Plot", "x\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(2, QCoreApplication::translate("Plot", "+\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(3, QCoreApplication::translate("Plot", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(4, QCoreApplication::translate("Plot", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(5, QCoreApplication::translate("Plot", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(6, QCoreApplication::translate("Plot", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(7, QCoreApplication::translate("Plot", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle2->setItemText(8, QCoreApplication::translate("Plot", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle2->setItemText(9, QCoreApplication::translate("Plot", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle2->setItemText(10, QCoreApplication::translate("Plot", "x\346\241\206", nullptr));
        cmbScatterStyle2->setItemText(11, QCoreApplication::translate("Plot", "+\346\241\206", nullptr));
        cmbScatterStyle2->setItemText(12, QCoreApplication::translate("Plot", "x\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(13, QCoreApplication::translate("Plot", "+\345\234\206", nullptr));
        cmbScatterStyle2->setItemText(14, QCoreApplication::translate("Plot", "\345\222\214\345\271\263", nullptr));

        chkVisibleCurve3->setText(QCoreApplication::translate("Plot", "\346\263\242\345\275\2423", nullptr));
        btnColourCurve3->setText(QString());
        rdoBoldCurve3->setText(QString());
        txtValueCurve3->setText(QString());
        cmbLineStyle3->setItemText(0, QCoreApplication::translate("Plot", "\347\202\271", nullptr));
        cmbLineStyle3->setItemText(1, QCoreApplication::translate("Plot", "\347\272\277", nullptr));
        cmbLineStyle3->setItemText(2, QCoreApplication::translate("Plot", "\345\267\246", nullptr));
        cmbLineStyle3->setItemText(3, QCoreApplication::translate("Plot", "\345\217\263", nullptr));
        cmbLineStyle3->setItemText(4, QCoreApplication::translate("Plot", "\344\270\255", nullptr));
        cmbLineStyle3->setItemText(5, QCoreApplication::translate("Plot", "\347\247\257", nullptr));

        cmbScatterStyle3->setItemText(0, QCoreApplication::translate("Plot", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle3->setItemText(1, QCoreApplication::translate("Plot", "x\345\275\242", nullptr));
        cmbScatterStyle3->setItemText(2, QCoreApplication::translate("Plot", "+\345\275\242", nullptr));
        cmbScatterStyle3->setItemText(3, QCoreApplication::translate("Plot", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle3->setItemText(4, QCoreApplication::translate("Plot", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle3->setItemText(5, QCoreApplication::translate("Plot", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle3->setItemText(6, QCoreApplication::translate("Plot", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle3->setItemText(7, QCoreApplication::translate("Plot", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle3->setItemText(8, QCoreApplication::translate("Plot", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle3->setItemText(9, QCoreApplication::translate("Plot", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle3->setItemText(10, QCoreApplication::translate("Plot", "x\346\241\206", nullptr));
        cmbScatterStyle3->setItemText(11, QCoreApplication::translate("Plot", "+\346\241\206", nullptr));
        cmbScatterStyle3->setItemText(12, QCoreApplication::translate("Plot", "x\345\234\206", nullptr));
        cmbScatterStyle3->setItemText(13, QCoreApplication::translate("Plot", "+\345\234\206", nullptr));
        cmbScatterStyle3->setItemText(14, QCoreApplication::translate("Plot", "\345\222\214\345\271\263", nullptr));

        chkVisibleCurve4->setText(QCoreApplication::translate("Plot", "\346\263\242\345\275\2424", nullptr));
        btnColourCurve4->setText(QString());
        rdoBoldCurve4->setText(QString());
        txtValueCurve4->setText(QString());
        cmbLineStyle4->setItemText(0, QCoreApplication::translate("Plot", "\347\202\271", nullptr));
        cmbLineStyle4->setItemText(1, QCoreApplication::translate("Plot", "\347\272\277", nullptr));
        cmbLineStyle4->setItemText(2, QCoreApplication::translate("Plot", "\345\267\246", nullptr));
        cmbLineStyle4->setItemText(3, QCoreApplication::translate("Plot", "\345\217\263", nullptr));
        cmbLineStyle4->setItemText(4, QCoreApplication::translate("Plot", "\344\270\255", nullptr));
        cmbLineStyle4->setItemText(5, QCoreApplication::translate("Plot", "\347\247\257", nullptr));

        cmbScatterStyle4->setItemText(0, QCoreApplication::translate("Plot", "\346\227\240\346\225\243\347\202\271", nullptr));
        cmbScatterStyle4->setItemText(1, QCoreApplication::translate("Plot", "x\345\275\242", nullptr));
        cmbScatterStyle4->setItemText(2, QCoreApplication::translate("Plot", "+\345\275\242", nullptr));
        cmbScatterStyle4->setItemText(3, QCoreApplication::translate("Plot", "\347\251\272\345\277\203\345\234\206", nullptr));
        cmbScatterStyle4->setItemText(4, QCoreApplication::translate("Plot", "\345\256\236\345\277\203\345\234\206", nullptr));
        cmbScatterStyle4->setItemText(5, QCoreApplication::translate("Plot", "\347\237\251\345\275\242", nullptr));
        cmbScatterStyle4->setItemText(6, QCoreApplication::translate("Plot", "\350\217\261\345\275\242", nullptr));
        cmbScatterStyle4->setItemText(7, QCoreApplication::translate("Plot", "\346\230\237\345\275\242", nullptr));
        cmbScatterStyle4->setItemText(8, QCoreApplication::translate("Plot", "\346\255\243\344\270\211\350\247\222", nullptr));
        cmbScatterStyle4->setItemText(9, QCoreApplication::translate("Plot", "\345\200\222\344\270\211\350\247\222", nullptr));
        cmbScatterStyle4->setItemText(10, QCoreApplication::translate("Plot", "x\346\241\206", nullptr));
        cmbScatterStyle4->setItemText(11, QCoreApplication::translate("Plot", "+\346\241\206", nullptr));
        cmbScatterStyle4->setItemText(12, QCoreApplication::translate("Plot", "x\345\234\206", nullptr));
        cmbScatterStyle4->setItemText(13, QCoreApplication::translate("Plot", "+\345\234\206", nullptr));
        cmbScatterStyle4->setItemText(14, QCoreApplication::translate("Plot", "\345\222\214\345\271\263", nullptr));

        chkShowLegend->setText(QCoreApplication::translate("Plot", "\346\230\276\347\244\272\345\233\276\344\276\213", nullptr));
        btnSaveData->setText(QCoreApplication::translate("Plot", "\344\277\235\345\255\230\346\263\242\345\275\242\346\225\260\346\215\256", nullptr));
        btnColourBack->setText(QString());
        label->setText(QCoreApplication::translate("Plot", "\347\273\230\345\233\276\345\214\272\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
        label_3->setText(QCoreApplication::translate("Plot", "Y\350\275\264\344\270\273\345\210\273\345\272\246\346\225\260\357\274\232", nullptr));
        txtMainScaleNumY->setText(QCoreApplication::translate("Plot", "11", nullptr));
        btnResetSettings->setText(QCoreApplication::translate("Plot", "\351\207\215\347\275\256\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("Plot", "X\350\275\264\344\270\273\345\210\273\345\272\246\346\225\260\357\274\232", nullptr));
        txtMainScaleNumX->setText(QCoreApplication::translate("Plot", "11", nullptr));
        btnClearGraphs->setText(QCoreApplication::translate("Plot", "\346\270\205\347\251\272\347\273\230\345\233\276", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_1), QCoreApplication::translate("Plot", "\346\233\262\347\272\277\350\256\276\347\275\256", nullptr));
        chkTrackX->setText(QCoreApplication::translate("Plot", "X\350\275\264\350\267\237\351\232\217", nullptr));
        lblPointOrigin->setText(QCoreApplication::translate("Plot", "\345\216\237\347\202\271\344\275\215\347\275\256", nullptr));
        lblPointCount->setText(QCoreApplication::translate("Plot", "\351\241\265\345\271\205\347\202\271\346\225\260", nullptr));
        lblPointCountX->setText(QCoreApplication::translate("Plot", "X\357\274\232", nullptr));
        txtPointOriginX->setText(QCoreApplication::translate("Plot", "0", nullptr));
        txtPointCountX->setText(QCoreApplication::translate("Plot", "1000", nullptr));
        lblPointCountY->setText(QCoreApplication::translate("Plot", "Y\357\274\232", nullptr));
        txtPointOriginY->setText(QCoreApplication::translate("Plot", "0", nullptr));
        txtPointCountY->setText(QCoreApplication::translate("Plot", "1", nullptr));
        chkAdjustY->setText(QCoreApplication::translate("Plot", "Y\350\275\264\350\207\252\351\200\202\345\272\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plot: public Ui_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_H
