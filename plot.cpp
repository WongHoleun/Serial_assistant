#include "plot.h"
#include "ui_plot.h"
#include <stdio.h>

Plot::Plot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Plot)
{
    // 这些初始化和连接操作在用户打开程序窗口时执行一次，并在之后根据用户交互或定时器的触发来更新图表和进行相关操作
    ui->setupUi(this);  // 创建界面
    setWindowTitle("面向代谢热无创血糖监测的多参数集成传感通信系统软件"); // 设置窗口标题

    pPlot1 = ui->winPlot;    // 给widget绘图控件，设置个别名，方便书写
    sBar = statusBar();      // 状态栏指针

    QPlot_init(pPlot1);   // 初始化图表1
    QPlot_widget_init();    // 绘图图表的设置控件初始化，主要用于关联控件的信号槽

    timer = new QTimer(this);       // 创建定时器，用于定时生成曲线坐标点数据
    timer->setInterval(10);         // 每隔 10ms 触发一次槽函数
//    connect(timer,SIGNAL(timeout()),this,SLOT(TimeData_Update()));

    ui->txtPointOriginX->setEnabled(false);    // 关联控件初始化 禁用 txtPointOriginX 的文本输入框控件，即该控件在界面上不可编辑。

    connect(pPlot1,SIGNAL(afterReplot()),this,SLOT(repPlotCoordinate()));    // 图表重绘后，刷新原点坐标和范围

    // 在 Plot 类的构造函数中连接按钮的信号与保存数据的成员函数
//    connect(ui->btnSaveData, &QPushButton::clicked, this, &Plot::saveCurvesToCSV);

}

Plot::~Plot()
{
    delete ui;
}


// 绘图图表初始化
void Plot::QPlot_init(QCustomPlot *customPlot)
{
    // 添加曲线名称
    QStringList lineNames;//设置图例的文本
    lineNames << "波形1" << "波形2" << "波形3" << "波形4" ;

    // 曲线初始颜色
    QColor initColor[4] = {QColor(0,146,152), QColor(162,0,124), QColor(241,175,0), QColor(27,79,147)};//QColor(255,255,255)};//白色

    // 图表添加20条曲线，并设置初始颜色，和图例名称
    for(int i=0; i<4; i++){
        pCurve[i] = customPlot->addGraph();
        pCurve[i]->setPen(QPen(QColor(initColor[i])));
        pCurve[i]->setName(lineNames.at(i));
    }

    // 设置背景颜色
    customPlot->setBackground(QColor(255,255,255));

    // 设置背景选择框颜色
    ui->btnColourBack->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(QColor(255,255,255).name()));

    // 设置坐标轴名称
    customPlot->xAxis->setLabel("X");
    customPlot->yAxis->setLabel("Y");

    // 设置x,y坐标轴显示范围（txtPointCountX * txtPointCountY）
    pointCountX = ui->txtPointCountX->text().toUInt();      // 从ui界面获取设置的x坐标点数 txtPointCountX
    pointCountY = ui->txtPointCountY->text().toUInt();
    customPlot->xAxis->setRange(0,pointCountX); // 设置图页 x轴范围 0~txtPointCountX
    customPlot->yAxis->setRange(pointCountY/2*-1,pointCountY/2);// 设置图页 Y轴对称显示，幅值 pointCountY/2

    // 用户可以通过文本输入框来控制显示在图表中的主刻度的数量，同时自动调整刻度以适应图表的大小
    customPlot->xAxis->ticker()->setTickCount(ui->txtMainScaleNumX->text().toUInt());//11个主刻度
    customPlot->yAxis->ticker()->setTickCount(ui->txtMainScaleNumY->text().toUInt());//11个主刻度
    customPlot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置
    customPlot->yAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置

    customPlot->legend->setVisible(true);    // 显示图表的图例

    // setInteractions 是 QCustomPlot 中用于设置图表交互方式的方法
    // QCP::iRangeDrag：允许拖动图表的可视范围。
    // QCP::iRangeZoom：允许缩放图表的可视范围。
    // QCP::iSelectPlottables：允许选择图表上的可绘制对象（例如，选中单条曲线）。
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);    //允许用户用鼠标拖动轴范围，以鼠标为中心滚轮缩放，点击选择图形:

    // axisRect() 可以获取图表的绘图区域（坐标轴矩形区域）的指针
    // setRangeZoom 方法用于设置绘图区域的范围缩放方向
    customPlot->axisRect()->setRangeZoom(Qt::Vertical); // 设置鼠标滚轮缩放的轴方向，仅设置垂直轴。垂直轴和水平轴全选使用：Qt::Vertical | Qt::Horizontal
}

// 绘图图表的设置控件初始化，主要用于关联控件的信号槽
void Plot::QPlot_widget_init(void)
{
    // 获取控件指针数组，方便设置时编码书写
    pChkVisibleCurve[0] = ui->chkVisibleCurve1; pBtnColourCurve[0] = ui->btnColourCurve1; pTxtValueCurve[0] = ui->txtValueCurve1; pRdoBoldCurve[0] = ui->rdoBoldCurve1;
    pChkVisibleCurve[1] = ui->chkVisibleCurve2; pBtnColourCurve[1] = ui->btnColourCurve2; pTxtValueCurve[1] = ui->txtValueCurve2; pRdoBoldCurve[1] = ui->rdoBoldCurve2;
    pChkVisibleCurve[2] = ui->chkVisibleCurve3; pBtnColourCurve[2] = ui->btnColourCurve3; pTxtValueCurve[2] = ui->txtValueCurve3; pRdoBoldCurve[2] = ui->rdoBoldCurve3;
    pChkVisibleCurve[3] = ui->chkVisibleCurve4; pBtnColourCurve[3] = ui->btnColourCurve4; pTxtValueCurve[3] = ui->txtValueCurve4; pRdoBoldCurve[3] = ui->rdoBoldCurve4;

    pCmbLineStyle[0] = ui->cmbLineStyle1; pCmbScatterStyle[0] = ui->cmbScatterStyle1;
    pCmbLineStyle[1] = ui->cmbLineStyle2; pCmbScatterStyle[1] = ui->cmbScatterStyle2;
    pCmbLineStyle[2] = ui->cmbLineStyle3; pCmbScatterStyle[2] = ui->cmbScatterStyle3;
    pCmbLineStyle[3] = ui->cmbLineStyle4; pCmbScatterStyle[3] = ui->cmbScatterStyle4;


    // 设置颜色选择框的初始背景颜色，与曲线同步颜色
    for(int i=0; i<4; i++){
        // setStyleSheet:用于设置控件的样式表。
        // border:0px solid 表示按钮没有边框
        // 将 QColor对象转换为字符串形式的颜色名称，将其插入样式表字符串的占位符 %1 中
        pBtnColourCurve[i]->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(QColor(pCurve[i]->pen().color()).name()));
    }

    // 可见性选择框关联
    for(int i=0; i<4; i++) //在复选框 pChkVisibleCurve[i] 被点击时，调用 curveSetVisible 函数来控制绘图区 pPlot1 中对应的曲线 pCurve[i] 是否可见。
    {
        // [=]() { ... }: Lambda 表达式，用于定义槽函数。在这里，它被用作连接信号时的槽函数
        connect(pChkVisibleCurve[i], &QCheckBox::clicked, [=](){
            curveSetVisible(pPlot1, pCurve[i], pChkVisibleCurve[i]->checkState());
        });
    }

    // 颜色选择框关联
    for(int i=0; i<4; i++)
    {
        // 当点击一个按钮时，会调用 curveSetColor 函数，该函数会将按钮所代表的颜色应用到绘图区 pPlot1 中对应的曲线 pCurve[i] 上
        connect(pBtnColourCurve[i], &QPushButton::clicked, [=](){
            curveSetColor(pPlot1, pCurve[i], pBtnColourCurve[i]);
        });
    }

    // 加粗显示多选框关联。尽量别用，会导致CPU使用率升高
    for(int i=0; i<4; i++){
        connect(pRdoBoldCurve[i], &QRadioButton::clicked, [=](){
            curveSetBold(pPlot1, pCurve[i], pRdoBoldCurve[i]->isChecked());
        });
    }

    // 曲线样式选择关联
    for(int i=0; i<4; i++)
    {
        // 当用户选择不同的线条样式时，都会调用 curveSetLineStyle 函数，该函数会将选中的样式应用到绘图区 pPlot1 中对应的曲线 pCurve[i] 上
        connect(pCmbLineStyle[i], &QComboBox::currentTextChanged, [=](){
            curveSetLineStyle(pPlot1, pCurve[i], pCmbLineStyle[i]->currentIndex());
        });
    }

    // 散点样式选择关联
    for(int i=0; i<4; i++)
    {
        // 当用户选择不同的散点样式时，都会调用 curveSetScatterStyle 函数，该函数会将选中的样式应用到绘图区 pPlot1 中对应的曲线 pCurve[i] 上
        connect(pCmbScatterStyle[i], &QComboBox::currentTextChanged, [=](){
            curveSetScatterStyle(pPlot1, pCurve[i], pCmbScatterStyle[i]->currentIndex()+1);
        });
    }

    for(int i=0; i<4; i++)
    {
        // setIconSize(QSize(25, 17)): 这是一个 QComboBox 类的成员函数，用于设置选项图标的尺寸 宽 25像素 高 17像素
        pCmbScatterStyle[i]->setIconSize(QSize(25,17)); // 设置图片显示像素大小，不然会默认大小显示会模糊
    }

}

// 用于将绘图数据添加到容器的成员函数：
void Plot::addDataToPlotData(float value[])
{
    plotData.curve1.append(value[0]);
    plotData.curve2.append(value[1]);
    plotData.curve3.append(value[2]);
    plotData.curve4.append(value[3]);
}

// 曲线更新绘图，波形数据绘图
void Plot::ShowPlot_WaveForm(QCustomPlot *customPlot, float value[])
{
    cnt++;

    // 添加数据到容器中
    addDataToPlotData(value);

    // 给曲线添加数据
    for(int i=0; i<4; i++)
    {
        // value[i] 是一个浮点数类型的数据数组，通过 QString::number(value[i]) 将其转换为字符串，并将其作为文本显示在相应的文本框中。
        pTxtValueCurve[i]->setText(QString::number(value[i]));// 显示曲线当前值
        pCurve[i]->addData(cnt, value[i]);// 从原值获取数据：当前的 cnt 和 value[i] 的值作为坐标点添加到相应的曲线上，从而更新绘图区中的曲线。
        // 因为20条线重叠在一起，所以QCustomPlot输入为0时看起来像不显示，隐藏其他后观察单条曲线是可以看到显示的
    }

    // 设置x坐标轴显示范围，使其自适应缩放x轴
    if(ui->chkTrackX->checkState())
    {
        // 复选框的状态可以是选中（Qt::Checked）、未选中（Qt::Unchecked），或者半选中（Qt::PartiallyChecked）
        setAutoTrackX(customPlot);  // 当复选框chkTrackX（X轴跟随）被选中时，x 轴的显示范围将根据绘图数据动态调整，确保 x 轴上显示的数据点数量最多为 pointCountX 个点
    }

    // 设置y坐标轴显示范围，使其自适应（chkAdjustY）曲线缩放
    if(ui->chkAdjustY->checkState())
    {
        setAutoTrackY(customPlot);
    }

    // 更新绘图，这种方式在高填充下太浪费资源。有另一种方式rpQueuedReplot，可避免重复绘图。
    // 最好的方法还是将数据填充、和更新绘图分隔开。将更新绘图单独用定时器更新。例程数据量较少没用单独定时器更新，实际工程中建议大家加上。
    // replot(): 这是对 customPlot 对象调用的一个函数。它触发自定义绘图区的重新绘制
    customPlot->replot(QCustomPlot::rpQueuedReplot);    // QCustomPlot::rpQueuedReplot 表示重新绘制将被排队 确保了自定义绘图区根据最新的数据和设置进行更新

    // 通过 QElapsedTimer 计时器来测量经过的时间，并将时间以秒为单位保存在 key 变量中
    static QElapsedTimer timer;
    if (!timer.isValid())   // QElapsedTimer::isValid() 函数返回 true 如果计时器已启动，返回 false 如果计时器未启动或被重置。
    {
        timer.start();  // 如果 timer 未启动（无效），那么这行代码会启动计时器。
    }
    double key = timer.elapsed() / 1000.0;  // elapsed() 获取从 timer 启动到现在经过的时间，单位为毫秒（ms）,除以 1000.0，将时间转换为秒

    // 计算每秒的帧率（FPS）和绘图中的数据点总数
    static double lastFpsKey;   // 存储上一次计算帧率的时间点。
    static int frameCount;  // 用于计算每秒的帧数（帧率）。
    ++frameCount;   // : 每次执行这段代码时，帧数增加 1，用于统计过去的一秒内绘制的帧数。
    if (key-lastFpsKey > 1) // 检查从上次计算帧率到现在的时间间隔是否超过 1 秒。
    {
        // 每1秒求一次平均值 帧数除以时间间隔frameCount / (key - lastFpsKey)
        //  0 表示使用最小宽度 'f' 表示以浮点数格式输出 最后一个0 表示精度，表示浮点数输出的小数部分位数。
        // 状态栏显示帧数和数据总数
        ui->statusbar->showMessage(
            QString("%1 FPS, Total Data points: %2")
            .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
            .arg(customPlot->graph(0)->data()->size()+customPlot->graph(1)->data()->size())
            , 0);
        lastFpsKey = key;
        frameCount = 0;
    }

}

/* 功能：隐藏/显示曲线n
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线的可见性，>0可见，0不可见
 * */
void Plot::curveSetVisible(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    if(arg1)
    {
        pCurve->setVisible(true);
    }
    else
    {
        pCurve->setVisible(false);
    }

    pPlot->replot(QCustomPlot::rpQueuedReplot); // 绘图区会进行排队重绘，即实际的绘制重绘将延迟到事件循环中进行，以避免冗余的重复绘制并提高性能。
}

/* 功能：弹出颜色对话框，设置曲线n的颜色
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * QPushButton *btn：曲线颜色选择框的按键，与曲线的颜色同步
 * */
void Plot::curveSetColor(QCustomPlot *pPlot, QCPGraph *pCurve, QPushButton *btn)
{

    QColor bgColor(0,0,0);  // 获取当前颜色 定义了一个 QColor 对象 bgColor，并将其初始化为黑色（默认颜色）

    bgColor = pCurve->pen().color();// 获取曲线 pCurve 的画笔颜色，并将该颜色赋值给 bgColor

    // 以当前颜色打开调色板，父对象，标题，颜色对话框设置项（显示Alpha透明度通道）
    // Alpha 透明度通道决定了一个颜色的不透明程度。当 Alpha 透明度分量为 0 时，表示完全透明，颜色不可见；当 Alpha 透明度分量为 255（或 1.0）时，表示完全不透明，颜色完全可见
    // bgColor 对话框的初始颜色
    // this 父对象指针，用于指定颜色对话框的父对象，指定为当前窗口
    // tr("颜色对话框"): 颜色对话框的标题，显示在对话框的标题栏
    QColor color = QColorDialog::getColor(bgColor, this,
                                     tr("颜色对话框"),
                                     QColorDialog::ShowAlphaChannel);

    // 判断返回的颜色是否合法。若点击x关闭颜色对话框，会返回QColor(Invalid)无效值，直接使用会导致变为黑色。
    if(color.isValid())
    {
        // 设置选择框颜色
        btn->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(color.name()));

        // 设置曲线颜色
        // QPen 是一个绘制曲线、图形和边框的类，它包含了绘制线条的颜色、样式和宽度等属性。
        QPen pen = pCurve->pen();   // 码创建一个 QPen 对象 pen，使用 pCurve 曲线的当前画笔属性进行初始化
        pen.setBrush(color);    // 设置 pen 对象的画刷（QBrush）画刷用于填充闭合区域，在设置曲线颜色时，它通常用于指定线条的颜色。
        pCurve->setPen(pen);    // 曲线的颜色被设置为用户在颜色对话框中所选择的新颜色
    }

    pPlot->replot(QCustomPlot::rpQueuedReplot);    // 更新绘图
}

/* 功能：加粗显示曲线n
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线的粗细，>0粗，0细
 * */
void Plot::curveSetBold(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    QPen pen = pCurve->pen();    // 预先读取曲线的颜色

    if(arg1)
    {
        pen.setWidth(3);
        pCurve->setPen(pen);
    }
    else
    {
        pen.setWidth(1);
        pCurve->setPen(pen);
    }
    pPlot->replot(QCustomPlot::rpQueuedReplot);
}

/* 功能：选择曲线样式（线，点，积）
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：曲线样式（线，点，积）
 * */
void Plot::curveSetLineStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    // 设置曲线样式
    // 将 arg1（枚举值）转换为 QCPGraph::LineStyle 类型后，使用 pCurve->setLineStyle() 函数将曲线的线条样式设置为相应的值
    pCurve->setLineStyle((QCPGraph::LineStyle)arg1);

    pPlot->replot(QCustomPlot::rpQueuedReplot); // 重绘
}

/* 功能：选择散点样式（空心圆、实心圆、正三角、倒三角）
 * QCustomPlot *pPlot：父控件，绘图图表
 * QCPGraph *pCurve：图表的曲线
 * int arg1：散点样式（空心圆、实心圆、正三角、倒三角）
 * */
void Plot::curveSetScatterStyle(QCustomPlot *pPlot, QCPGraph *pCurve, int arg1)
{
    // 设置散点样式
    if(arg1 <= 10)
    {
        // QCPScatterStyle: 这是一个用于设置散点样式的类，它可以设置散点的形状、大小、颜色等属性
        // QCPScatterStyle::ScatterShape)arg1: 这部分代码将整数值 arg1 转换为 QCPScatterStyle::ScatterShape 枚举类型用于指定散点的形状
        pCurve->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)arg1, 5)); // 在绘图区中显示的散点的大小为 5 个像素
    }
    else
    {
        // 后面的散点图形略复杂，太小会看不清
        pCurve->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)arg1, 8)); // 在绘图区中显示的散点的大小为 8 个像素
    }

    pPlot->replot(QCustomPlot::rpQueuedReplot); // 重绘
}

// 图例显示与否
void Plot::on_chkShowLegend_stateChanged(int arg1)
{
    if(arg1)
    {
        // 显示图表的图例
        pPlot1->legend->setVisible(true);
    }
    else
    {
        // 不显示图表的图例
        pPlot1->legend->setVisible(false);
    }

    pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 重绘
}

// 绘图演示-曲线
//void Plot::on_chkDrawDemo_stateChanged(int arg1)
//{
//    if(arg1)
//    {
//        timer->start(10);
//    }
//    else
//    {
//        timer->stop();
//    }
//}

// 设置曲线x轴自动跟随
// void Plot::setAutoTrackX(QCustomPlot *pPlot): 这是一个名为 setAutoTrackX 的函数，属于 Plot 类。
// 它用于设置曲线的 x 轴自动跟随功能，并接受一个指向 QCustomPlot 绘图区的指针 pPlot 作为参数
void Plot::setAutoTrackX(QCustomPlot *pPlot)
{
    // 从用户界面中的文本输入框 txtPointCountX 获取文本内容，设置 x 轴上显示的最大数据点数量
    pointCountX = ui->txtPointCountX->text().toUInt();

    if(pCurve[0]->dataCount() < pointCountX)
    {
        // 用户设置的最大数据点数量 pointCountX大于检查曲线 pCurve[0] 的数据点数量
        pPlot->xAxis->setRange(0,pointCountX);  // 将 x 轴的显示范围设置为从 0 到 pointCountX
    }
    else
    {
        // 用户设置的最大数据点数量 pointCountX小于检查曲线 pCurve[0] 的数据点数量
        // 根据曲线 pCurve[0] 的数据点数量和 pointCountX 的值，计算 x 轴的显示范围。
        // 如果曲线的数据点数量大于 pointCountX，则 x 轴的范围为从（数据点数量 - pointCountX）到数据点数量；
        // 否则，x 轴的范围从 0 到数据点数量。这样，x 轴将始终显示最近的 pointCountX 个数据点，实现了自动跟随的效果。
        pPlot->xAxis->setRange((pCurve[0]->dataCount()>pointCountX)?(pCurve[0]->dataCount()-pointCountX):0, pCurve[0]->dataCount());
    }
}


// 设置曲线x轴手动设置范围（依照右下角输入框）
// void Plot::setManualSettingX(QCustomPlot *pPlot): 这是一个名为 setManualSettingX 的函数，属于 Plot 类。
// 它用于设置曲线的 x 轴手动设置范围，并接受一个指向 QCustomPlot 绘图区的指针 pPlot 作为参数。
void Plot::setManualSettingX(QCustomPlot *pPlot)
{
    pointOriginX = ui->txtPointOriginX->text().toInt();
    pointCountX = ui->txtPointCountX->text().toUInt();

    pPlot->xAxis->setRange(pointOriginX, pointOriginX+pointCountX); // 设置 x 轴的显示范围
}

// 设置Y轴自适应
// void Plot::setAutoTrackY(QCustomPlot *pPlot): 这是一个名为 setAutoTrackY 的函数，属于 Plot 类。
// 它用于设置曲线的 Y 轴自适应功能，并接受一个指向 QCustomPlot 绘图区的指针 pPlot 作为参数
void Plot::setAutoTrackY(QCustomPlot *pPlot)
{
    // 调用 pPlot 绘图区的第一个图形（曲线）的 rescaleValueAxis() 函数，以使 Y 轴自适应
    pPlot->graph(0)->rescaleValueAxis();// 这个函数会自动调整 Y 轴的范围，使得曲线上的所有数据点都能在 Y 轴上完整显示，可放大或缩小 Y 轴的范围。

    for(int i=1; i<4; i++)
    {
        // 在循环中，对每个曲线都调用 rescaleValueAxis(true) 函数。
        // 这个函数会自动调整 Y 轴的范围，但只能放大 Y 轴的范围，用于确保每个曲线都能在 Y 轴上完整显示
        pPlot->graph(i)->rescaleValueAxis(true);// y轴自适应，只能放大
    }
}

// 重新设置X轴显示的点数，在用户在界面中输入回车键时触发。
void Plot::on_txtPointCountX_returnPressed()
{
    if(ui->chkTrackX->checkState()) // checkState() 函数用于获取复选框的状态，如果复选框被选中，返回 Qt::Checked（代表选中状态）
    {
        setAutoTrackX(pPlot1);  // 调用 setAutoTrackX 函数设置曲线的 x 轴自动跟随功能
    }
    else
    {
        // chkTrackX 未被选中 设置曲线的 x 轴手动设置范围
        setManualSettingX(pPlot1);
    }

    pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 重绘
}

// 重新设置Y轴显示的点数，在用户在界面中输入回车键时触发。
void Plot::on_txtPointCountY_returnPressed()
{
    pointCountY = ui->txtPointCountY->text().toUInt();
    pPlot1->yAxis->setRange(pointCountY/2*-1,pointCountY/2);
    ui->txtPointOriginY->setText(QString::number(pointCountY/2*-1));
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

// 在用户点击 "btnColourBack" 按钮后触发的处理操作，用于设置绘图区（pPlot1）的背景颜色
void Plot::on_btnColourBack_clicked()
{
    // 获取当前颜色
    QColor bgColor(0,0,0);  // 创建一个 QColor 对象 bgColor，并将其初始化为黑色 (R=0, G=0, B=0)

    bgColor = ui->btnColourBack->palette().color(QPalette::Background);// 通过获取按钮 "btnColourBack" 的背景色，将 bgColor 更新为按钮当前的背景颜色

    // 以当前颜色打开调色板，父对象，标题，颜色对话框设置项（显示Alpha透明度通道）
    // 打开颜色对话框，并将初始颜色设置为 bgColor。ShowAlphaChannel 参数使得颜色对话框显示 Alpha 透明度通道，以允许用户选择带有透明度的颜色
    QColor color = QColorDialog::getColor(bgColor, this,
                                     tr("颜色对话框"),
                                     QColorDialog::ShowAlphaChannel);

    // 判断返回的颜色是否合法。若点击x关闭颜色对话框，会返回QColor(Invalid)无效值，直接使用会导致变为黑色。
    if(color.isValid())
    {
        pPlot1->setBackground(color);   //         // 设置背景颜色

        ui->btnColourBack->setStyleSheet(QString("border:0px solid;background-color: %1;").arg(color.name()));      // 设置背景选择框颜色
    }

    pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 更新绘图
}

// 在用户在界面中输入特定数值时触发的处理操作
void Plot::on_txtPointOriginX_returnPressed()
{
    setManualSettingX(pPlot1);  // 用于设置曲线的 x 轴手动设置范围，依据用户在右下角输入框中设置的点原点和点数量。
    pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 触发绘图区 pPlot1 的排队重绘
}

// 在复选框 chkTrackX 的状态改变时触发，参数 arg1 表示复选框的新状态
// （arg1 值为 1 代表选中，0 代表未选中）
void Plot::on_chkTrackX_stateChanged(int arg1)
{
    if(arg1)
    {
        // chkTrackX 被选中（新状态为 1），则禁用输入框 txtPointOriginX
        // 当 x 轴自动跟随时，不需要手动设置 x 轴的起始点。
        ui->txtPointOriginX->setEnabled(false);

        setAutoTrackX(pPlot1);  // 设置曲线的 x 轴自动跟随功能
        pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 触发绘图区 pPlot1 的排队重绘，
    }
    else
    {
        // chkTrackX 未被选中（新状态为 0）
        ui->txtPointOriginX->setEnabled(true);      // 启用输入框 txtPointOriginX，用户可以手动设置 x 轴的起始点。
    }
}

// 复选框 chkAdjustY 的状态改变时触发，参数 arg1 表示复选框的新状态
// arg1 值为 1 代表选中，0 代表未选中
void Plot::on_chkAdjustY_stateChanged(int arg1)
{
    if(arg1)
    {
        // 复选框 chkAdjustY 被选中（新状态为 1），则禁用输入框 txtPointOriginY 和 txtPointCountY
        ui->txtPointOriginY->setEnabled(false);
        ui->txtPointCountY->setEnabled(false);

        setAutoTrackY(pPlot1);  // 设置曲线的 y 轴自适应功能
        pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 触发绘图区 pPlot1 的排队重绘
    }
    else
    {
        // 复选框 chkAdjustY 未被选中（新状态为 0），启用输入框 txtPointOriginY 和txtPointCountY
        ui->txtPointOriginY->setEnabled(true);
        ui->txtPointCountY->setEnabled(true);
    }
}


// 在界面中输入特定数值后触发的处理操作，用于设置 y 轴的手动设置范围
void Plot::on_txtPointOriginY_returnPressed()
{
    pointOriginY = ui->txtPointOriginY->text().toInt(); // 从用户界面中的文本输入框 txtPointOriginY 获取文本内容，并将其转换为整数类型用于设置 y 轴的起始点
    pointCountY = ui->txtPointCountY->text().toUInt();  // 从用户界面中的文本输入框 txtPointCountY 获取文本内容，并将其转换为无符号整类型用于设置 y 轴上显示的点数量
    pPlot1->yAxis->setRange(pointOriginY, pointOriginY+pointCountY);    // 置 y 轴的显示范围
    pPlot1->replot(QCustomPlot::rpQueuedReplot);    // 触发绘图区 pPlot1 的排队重绘
}

// 每次图表重绘后，都会更新当前显示的原点坐标与范围。与上次不同时才会更新显示，解决有曲线数据时无法输入y的参数的问题
void Plot::repPlotCoordinate()
{
    static int xOrigin, yOrigin, yCount;    // 记录绘图区当前的 x 轴起始点、y 轴起始点和 y 轴上显示的点数量。
    static int xOriginLast, yOriginLast, yCountLast;    // 记录上一次更新界面时的 x 轴起始点、y 轴起始点和 y 轴上显示的点数量。

    xOrigin = pPlot1->xAxis->range().lower; //  获取绘图区 pPlot1 当前的 x 轴起始点。
    yOrigin = pPlot1->yAxis->range().lower; //  获取绘图区 pPlot1 当前的 y 轴起始点。
    yCount = pPlot1->yAxis->range().size(); //  获取绘图区 pPlot1 当前的 y 轴上显示的点数量。

    // 如果当前的 x 轴起始点与上次更新时的值不相同，说明 x 轴的范围发生了改变。
    if(xOriginLast != xOrigin)
    {
        ui->txtPointOriginX->setText(QString::number(xOrigin)); // 将界面中输入框 txtPointOriginX 的显示值更新为当前的 x 轴起始点。
    }
    // 如果当前的 y 轴起始点与上次更新时的值不相同，说明 y 轴的范围发生了改变。
    if(yOriginLast != yOrigin)
    {
        ui->txtPointOriginY->setText(QString::number(yOrigin)); //  将界面中输入框 txtPointOriginY 的显示值更新为当前的 y 轴起始点。
    }
    // 如果当前的 y 轴上显示的点数量与上次更新时的值不相同，说明 y 轴上的点数量发生了改变
    if(yCountLast != yCount)
    {
        ui->txtPointCountY->setText(QString::number(yCount));   // 将界面中输入框 txtPointCountY 的显示值更新为当前的 y 轴上显示的点数量。
    }

    // 记录历史值
    xOriginLast = xOrigin;  //  更新 x 轴起始点的历史记录，以备下次更新时比较
    yOriginLast = yOrigin;
    yCountLast = yCount;
}

// 清空绘图
void Plot::on_btnClearGraphs_clicked()
{
    for(int i=0; i<4; i++)
    {
        pPlot1->graph(i)->data().data()->clear(); // 仅仅清除曲线的数据
    }
    cnt = 0;
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

// 设置X轴主刻度个数 在用户在界面中输入特定数值后触发的处理操作
void Plot::on_txtMainScaleNumX_returnPressed()
{
    // 刻度生成器（Ticker）是负责确定轴上刻度位置的组件，它根据轴的范围、大小和显示需求来计算刻度的位置和标签
    pPlot1->xAxis->ticker()->setTickCount(ui->txtMainScaleNumX->text().toUInt());   // 通过 setTickCount 函数设置 x 轴主刻度数为用户指定的值。
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}

// 设置Y轴主刻度个数 在用户在界面中输入特定数值后触发的处理操作
void Plot::on_txtMainScaleNumY_returnPressed()
{
    pPlot1->yAxis->ticker()->setTickCount(ui->txtMainScaleNumY->text().toUInt());
    pPlot1->replot(QCustomPlot::rpQueuedReplot);
}



//void Plot::saveCurvesToCSV(const QString &fileName)
void Plot::on_btnSaveData_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存CSV文件"), "", tr("CSV文件 (*.csv);;所有文件 (*)"));
    if (fileName.isEmpty()) {
        return;  // 用户取消了对话框
    }

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("错误"), tr("无法打开文件进行写入。"));
        return;
    }

    QTextStream out(&file);

    // 写入表头
    out << "数据点编号,曲线1,曲线2,曲线3,曲线4\n";

    int numPoints = qMax(qMax(plotData.curve1.size(), plotData.curve2.size()), qMax(plotData.curve3.size(), plotData.curve4.size()));

    for (int i = 0; i < numPoints; i++) {
        out << i + 1 << ",";
        if (i < plotData.curve1.size())
            out << plotData.curve1[i] << ",";
        else
            out << ",";

        if (i < plotData.curve2.size())
            out << plotData.curve2[i] << ",";
        else
            out << ",";

        if (i < plotData.curve3.size())
            out << plotData.curve3[i] << ",";
        else
            out << ",";

        if (i < plotData.curve4.size())
            out << plotData.curve4[i];
        out << "\n";
    }

    file.close();
}

