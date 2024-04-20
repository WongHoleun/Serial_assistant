#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("面向代谢热无创血糖监测的多参数集成传感通信系统软件");

    // 状态栏
    QStatusBar *sBar = statusBar();

    // 状态栏的收、发计数标签
    lblSendNum = new QLabel(this);
    lblRecvNum = new QLabel(this);
    lblSendRate = new QLabel(this);
    lblRecvRate = new QLabel(this);

    // 设置标签最小大小
    lblSendNum->setMinimumSize(100, 20);
    lblRecvNum->setMinimumSize(100, 20);
    lblSendRate->setMinimumSize(100, 20);
    lblRecvRate->setMinimumSize(100, 20);

    // 状态栏显示计数值
    setNumOnLabel(lblSendNum, "S: ", sendNum);
    setNumOnLabel(lblRecvNum, "R: ", recvNum);
    setNumOnLabel(lblSendRate, "Byte/s: ", 0);
    setNumOnLabel(lblRecvRate, "Byte/s: ", 0);

    // 从右往左依次添加
    sBar->addPermanentWidget(lblSendNum);
    sBar->addPermanentWidget(lblSendRate);
    sBar->addPermanentWidget(lblRecvNum);
    sBar->addPermanentWidget(lblRecvRate);

    lblRecvFrameNum = new QLabel(this);
    lblFrameRate = new QLabel(this);
    lblRecvFrameNum->setMinimumSize(100, 20);
    lblFrameRate->setMinimumSize(80, 20);
    setNumOnLabel(lblRecvFrameNum, "FNum: ", recvFrameNum);
    setNumOnLabel(lblFrameRate, "FPS: ", recvFrameRate);

    // 从右往左依次添加
    sBar->addPermanentWidget(lblRecvFrameNum);
    sBar->addPermanentWidget(lblFrameRate);

    // 定时发送-定时器
    timSend = new QTimer;
    timSend->setInterval(1000);// 设置默认定时时长1000ms
    connect(timSend, &QTimer::timeout, this, [=](){
        on_btnSend_clicked();
    });

    // 发送速率、接收速率统计-定时器
    timRate = new QTimer;
    timRate->start(1000);   // 以1秒（1000毫秒）的间隔启动该定时器
    connect(timRate, &QTimer::timeout, this, [=](){
        dataRateCalculate();
    });

    // 新建一串口对象
    mySerialPort = new QSerialPort(this);

    // 串口接收，信号槽关联 可以在serialPortRead_Slot()函数中处理串口接收到的数据。
    connect(mySerialPort, SIGNAL(readyRead()), this, SLOT(serialPortRead_Slot()));

    // 隐藏高级收码显示区域
//    ui->widget_5->hide();
//    ui->frame_3->hide();

    // 显示图片
    QPixmap originalPixmap1("://HR.svg"); // 加载原始图片
    QPixmap originalPixmap2("://SPO2.svg"); // 加载原始图片
    QPixmap originalPixmap3("://BV.svg"); // 加载原始图片
    QPixmap originalPixmap4("://BF.svg"); // 加载原始图片
    QPixmap originalPixmap5("://MH.svg"); // 加载原始图片

    // ui->label_Hr->size() 返回标签的大小，
    // Qt::KeepAspectRatio 保持宽高比例，
    // Qt::SmoothTransformation 则应用平滑的图像缩放。这将确保图片按比例缩放到适应标签的大小，并在标签内完整显示。
    QPixmap scaledPixmap1 = originalPixmap1.scaled(ui->label_Hr->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Hr->setPixmap(scaledPixmap1);
    QPixmap scaledPixmap2 = originalPixmap2.scaled(ui->label_Spo2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Spo2->setPixmap(scaledPixmap2);
    QPixmap scaledPixmap3 = originalPixmap3.scaled(ui->label_Bv->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Bv->setPixmap(scaledPixmap3);
    QPixmap scaledPixmap4 = originalPixmap4.scaled(ui->label_Bf->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Bf->setPixmap(scaledPixmap4);
    QPixmap scaledPixmap5 = originalPixmap5.scaled(ui->label_Mh->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Mh->setPixmap(scaledPixmap5);

    // 新建波形显示界面
    plot = new Plot;
}

MainWindow::~MainWindow()
{
    delete plot;
    delete ui;
}

// 绘图事件虚函数 用于ui的绘制，会在多种情况下被其他函数自动调用
// 当窗口需要绘制的时候，这个函数会被自动调用，允许你在窗口中绘制自定义内容。
void MainWindow::paintEvent(QPaintEvent *)
{
    // 绘图 在窗口的底部绘制一条带有特定线条风格的线
    QPainter painter(this);    // 实例化画家对象，this指定绘图设备
    QPen pen(QColor(0,0,0));    // 创建画笔，设置画笔颜色黑色（RGB值0, 0, 0）  brush() 笔刷 pen()钢笔
    pen.setWidth(1);    // 设置画笔线宽为1（只对点线圆起作用，对文字不起作用）

    // 设置画笔线条风格，默认是SolidLine实线
    // DashLine虚线，DotLine点线，DashDotLine、DashDotDotLine点划线
    pen.setStyle(Qt::DashDotDotLine);

    painter.setPen(pen);    // 让画家使用这个画笔

    // 绘制一条水平线，连接了状态栏（ui->statusbar）的左侧和主窗口的右侧
    // 起点：ui->statusbar->x()给出了状态栏部件的左上角的x坐标，而ui->statusbar->y()-2减去2是为了使线条稍微上移一点，使其不与状态栏精确对齐。
    // 终点：this->width()给出了主窗口的宽度，ui->statusbar->y()-2是为了与起点的y坐标保持一致
    painter.drawLine(QPoint(ui->statusbar->x(), ui->statusbar->y()-2), QPoint(this->width(), ui->statusbar->y()-2));
}

// 串口接收显示，槽函数
void MainWindow::serialPortRead_Slot()
{
//    QByteArray recBuf;
    QByteArray newData = mySerialPort->readAll();   // 保存最新接收到的数据
    recBuf += newData;              // 将新数据添加到缓冲区
//    recBuf = mySerialPort->readAll();
//    recvNum += recBuf.size();    // 接收字节计数
    recvNum += newData.size();    // 更新接收字节计数
    setNumOnLabel(lblRecvNum, "R: ", recvNum);// 状态栏显示计数值

    if (recBuf.contains("end")) {
        // 检查是否收到"end"，如果是，则调用功能提取函数
        feature_extraction();
    }else{
        /* 帧过滤部分代码 */
        float wmValue[4] = {0}; // 最多4条曲线
        xFrameDataFilter(&recBuf, wmValue);
    }

    // 判断是否为16进制接收（chkRec），将以后接收的数据全部转换为16进制显示（先前接收的部分在多选框槽函数中进行转换。最好多选框和接收区组成一个自定义控件，方便以后调用）
    if(ui->chkRec->checkState() == false)
    {
        // 16进制显示复选框未选中，GB2312编码输入
        QString strb = QString::fromLocal8Bit(recBuf);//QString::fromUtf8(recBuf);//QString::fromLatin1(recBuf);

        // 在当前位置插入文本，不会发生换行。如果没有移动光标到文件结尾，会导致文件超出当前界面显示范围，界面也不会向下滚动。
        ui->txtRec->insertPlainText(strb);
    }
    else
    {
        // 16进制显示复选框被选中
        // recBuf.toHex() 将字节数组转换为一个十六进制字符串，每个字节都被转换为两位十六进制表示
        // .toUpper() 将十六进制字符串中的所有字符转换为大写形式
        QString str1 = recBuf.toHex().toUpper();

        // 添加空格
        QString str2;
        for(int i = 0; i<str1.length (); i+=2)
        {
            str2 += str1.mid (i,2);
            str2 += " ";
        }
        ui->txtRec->insertPlainText(str2);
    }

    // 移动光标到文本结尾
    ui->txtRec->moveCursor(QTextCursor::End);
}

// 打开/关闭串口 槽函数
void MainWindow::on_btnSwitch_clicked()
{

    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity   checkBits;

    baudRate = (QSerialPort::BaudRate)ui->cmbBaudRate->currentText().toUInt();    // 获取串口波特率
    dataBits = (QSerialPort::DataBits)ui->cmbData->currentText().toUInt();    // 获取串口数据位

    // 获取串口停止位
    if(ui->cmbStop->currentText() == "1")
    {
        stopBits = QSerialPort::OneStop;
    }
    else if(ui->cmbStop->currentText() == "1.5")
    {
        stopBits = QSerialPort::OneAndHalfStop;
    }
    else if(ui->cmbStop->currentText() == "2")
    {
        stopBits = QSerialPort::TwoStop;
    }else{
        stopBits = QSerialPort::OneStop;
    }

    // 获取串口奇偶校验位
    if(ui->cmbCheck->currentText() == "无")
    {
        checkBits = QSerialPort::NoParity;
    }
    else if(ui->cmbCheck->currentText() == "奇校验")
    {
        checkBits = QSerialPort::OddParity;
    }
    else if(ui->cmbCheck->currentText() == "偶校验")
    {
        checkBits = QSerialPort::EvenParity;
    }
    else
    {
        checkBits = QSerialPort::NoParity;
    }

    // 想想用 substr strchr怎么从带有信息的字符串中提前串口号字符串
    // 初始化串口属性，设置 端口号、波特率、数据位、停止位、奇偶校验位数
    mySerialPort->setBaudRate(baudRate);
    mySerialPort->setDataBits(dataBits);
    mySerialPort->setStopBits(stopBits);
    mySerialPort->setParity(checkBits);

    // 匹配带有串口设备信息的文本
    // 如 "COM1: Some Description" 的字符串，其中 "COM1" 是串口名称，后面的部分是串口的描述
    QString spTxt = ui->cmbSerialPort->currentText();   // 首先从下拉框（ComboBox）中获取当前选中的串口名称，然后提取出有效的串口名称。
    spTxt = spTxt.section(':', 0, 0);   // section() 函数，将字符串按照 ":" 字符进行分隔，索引从0开始提取出第 0 段，也就是 ":" 之前的部分，即串口名称部分。
    mySerialPort->setPortName(spTxt);   // 将提取出的串口名称（存储在 spTxt 中）设置为 mySerialPort 串口对象的名称

    // 根据初始化好的串口属性，打开串口
    // 如果打开成功，反转打开按钮显示和功能。打开失败，无变化，并且弹出错误对话框。
    if(ui->btnSwitch->text() == "打开串口")
    {
        if(mySerialPort->open(QIODevice::ReadWrite) == true)
        {
            // 打开成功 QMessageBox::
            ui->btnSwitch->setText("关闭串口");

            // 让端口号下拉框不可选，避免误操作（选择功能不可用，控件背景为灰色）
            ui->cmbSerialPort->setEnabled(false);
            ui->cmbBaudRate->setEnabled(false);
            ui->cmbStop->setEnabled(false);
            ui->cmbData->setEnabled(false);
            ui->cmbCheck->setEnabled(false);
        }
        else    // 打开失败
        {
            QMessageBox::critical(this, "错误提示", "串口打开失败！！！\r\n\r\n该串口可能被占用，请选择正确的串口\r\n或者波特率过高，超出硬件支持范围");
        }
    }
    else    // 等待打开
    {

        mySerialPort->close();
        ui->btnSwitch->setText("打开串口");

        // 端口号下拉框恢复可选，避免误操作
        ui->cmbSerialPort->setEnabled(true);
        ui->cmbBaudRate->setEnabled(true);
        ui->cmbStop->setEnabled(true);
        ui->cmbData->setEnabled(true);
        ui->cmbCheck->setEnabled(true);
    }

}

// 发送按键槽函数
// 如果勾选16进制发送，按照asc2的16进制发送
void MainWindow::on_btnSend_clicked()
{
    QByteArray sendData;

    // 判断是否为16进制发送，将发送区全部的asc2转换为16进制字符串显示，发送的时候转换为16进制发送
    if(ui->chkSend->checkState() == false)   // 16进制发送复选框未选中
    {
        // 字符串形式发送，GB2312编码用以兼容大多数单片机
        //sendData = ui->txtSend->toPlainText().toUtf8();// Unicode编码输出
        sendData = ui->txtSend->toPlainText().toLocal8Bit();// GB2312编码输出
    }
    else    // 16进制发送复选框选中
    {
        // 16进制发送，不要用.data()，.data()返回的是字符数组，0x00在ASC2中的意义为NUL，也就是'\0'结束符，所以遇到0x00就会终止
        //sendData = QByteArray::fromHex(ui->txtSend->toPlainText().toUtf8());// Unicode编码输出
        sendData = QByteArray::fromHex(ui->txtSend->toPlainText().toLocal8Bit());// GB2312编码输出
    }

    // 判断发送状态
    int a = mySerialPort->write(sendData);  // 如发送成功，会返回发送的字节长度。失败，返回-1。
    if(a > 0)   // 发送字节计数并显示
    {
        sendNum += a;   // 保存发送字节数
        setNumOnLabel(lblSendNum, "S: ", sendNum);    // 调用状态栏函数 显示成功发送的字节数
    }

}

// 状态栏标签显示计数值
// num：数量
void MainWindow::setNumOnLabel(QLabel *lbl, QString strS, long num)
{
    // 标签显示
    QString strN = QString::asprintf("%ld", num);   // 将长整型数值转换为对应的字符串表示
    QString str = strS + strN;  // 一个字符串和一个长整型数值结合起来
    lbl->setText(str);  // 将最终的连接好的字符串 str 设置为传入的标签 lbl 的文本内容，从而显示在界面上。
}

// 清除接收 槽函数
void MainWindow::on_btnClearRec_clicked()
{
    ui->txtRec->clear();

    // 清除发送、接收字节计数
    sendNum = 0;
    recvNum = 0;
    tSend = 0;
    tRecv = 0;

    // 状态栏显示计数值
    setNumOnLabel(lblSendNum, "S: ", sendNum);
    setNumOnLabel(lblRecvNum, "R: ", recvNum);

    // 清空帧数量
    recvFrameNum=0, recvFrameRate=0, recvErrorNum=0, tFrame=0;
    setNumOnLabel(lblRecvFrameNum, "FNum: ", recvFrameNum);
//    ui->txtFrameErrorNum->setText(QString::number(recvErrorNum));
}

// 清除发送 槽函数
void MainWindow::on_btnClearSend_clicked()
{
    ui->txtSend->clear();

    // 清除发送字节计数
    sendNum = 0;
    tSend = 0;

    // 状态栏显示计数值
    setNumOnLabel(lblSendNum, "S: ", sendNum);
}

// 先前接收的部分在复选框状态转换槽函数中进行转换。（最好多选框和接收区组成一个自定义控件，方便以后调用）
void MainWindow::on_chkRec_stateChanged(int arg1)
{
    // 获取文本字符串
    QString txtBuf = ui->txtRec->toPlainText();

    // 获取16进制接收复选框状态，未选为0，选中为2
    if(arg1 == 0)   // 为0时，多选框未被勾选，接收区先前接收的16进制数据转换为asc2字符串格式
    {
        //QString str1 = QByteArray::fromHex(txtBuf.toUtf8());
        //QString str1 = QByteArray::fromHex(txtBuf.toLocal8Bit());

        // 将字节数组 txtBuf 中的十六进制数据，以 GB2312 编码方式解码成 Unicode 字符串，最终结果存储在 str1 中
        // 将一个QString对象txtBuf中的内容转换为本地字符编码（toLocal8Bit()），然后将这些字节数据解析为原始字节数据（fromHex()）得到的一个字节数组
        // 使用一个名为 "GB2312" 的字符编码（QTextCodec::codecForName("GB2312")），将刚才得到的字节数组从GB2312编码解码为Unicode字符串
        QString str1 = QTextCodec::codecForName("GB2312")->toUnicode(QByteArray::fromHex(txtBuf.toLocal8Bit()));


        ui->txtRec->clear();        // 文本控件清屏
        ui->txtRec->insertPlainText(str1);// 显示新文本

        ui->txtRec->moveCursor(QTextCursor::End);        // 移动光标到文本结尾
    }
    else
    {
        // 不为0时，16进制接收复选框被勾选，接收区先前接收asc2字符串转换为16进制显示
        //QString str1 = txtBuf.toUtf8().toHex().toUpper();// Unicode编码输出
        // 将字符串 txtBuf 转换为本地字符编码的字节数组（toLocal8Bit()），然后将该字节数组转换为十六进制表示（toHex()），最后将结果转换为大写形式（toUpper()
        QString str1 = txtBuf.toLocal8Bit().toHex().toUpper();// GB2312编码输出

        // 添加空格
        QByteArray str2;
        for(int i = 0; i<str1.length (); i+=2)  // 遍历了 str1 中的每两个字符，也就是十六进制数据的每个字节。
        {
            // QString QString::mid(int position, int n)  从字符串中提取一个子字符串
            // constposition 是子字符串的起始位置（索引）， n 是要提取的字符数量。
            str2 += str1.mid (i,2).toLocal8Bit();   // 从 str1 中提取连续的两个字符，然后将它们转换为对应的字节数据（使用 toLocal8Bit()），并附加到字节数组 str2 中
            str2 += " ";    // 在每两个字符之间添加一个空格。
        }

        // 文本控件清屏，显示新文本
        ui->txtRec->clear();
        ui->txtRec->insertPlainText(str2);

        ui->txtRec->moveCursor(QTextCursor::End);        // 移动光标到文本结尾

    }
}

// 先前发送区的部分在复选框状态转换槽函数中进行转换。（最好多选框和发送区组成一个自定义控件，方便以后调用）
void MainWindow::on_chkSend_stateChanged(int arg1)
{
    // 获取文本字符串
    QString txtBuf = ui->txtSend->toPlainText();

    // 获取多选框状态，未选为0，选中为2
    // 为0时，多选框未被勾选，将先前的发送区的16进制字符串转换为asc2字符串
    if(arg1 == 0)
    {
        //把gb2312编码转换成unicode
        QString str1 = QTextCodec::codecForName("GB2312")->toUnicode(QByteArray::fromHex(txtBuf.toLocal8Bit()));

        ui->txtSend->clear();
        ui->txtSend->insertPlainText(str1);
        ui->txtSend->moveCursor(QTextCursor::End);

    }
    else
    {
        // 多选框被勾选，将先前的发送区的asc2字符串转换为16进制字符串
        QString str1 = txtBuf.toLocal8Bit().toHex().toUpper();// GB2312编码输出

        // 添加空格
        QString str2;
        for(int i = 0; i<str1.length (); i+=2)
        {
            str2 += str1.mid (i,2);
            str2 += " ";
        }

        ui->txtSend->clear();// 文本控件清屏
        ui->txtSend->insertPlainText(str2);// 显示新文本
        ui->txtSend->moveCursor(QTextCursor::End);// 移动光标到文本结尾

    }
}

// 定时发送开关 选择复选框
void MainWindow::on_chkTimSend_stateChanged(int arg1)
{
    // 获取定时发送复选框状态
    if(arg1 == 0)   // 定时发送复选框状态：未选=0
    {
        timSend->stop();
        ui->txtSendMs->setEnabled(true);        // 时间输入框恢复可选
    }
    else    // 定时发送复选框状态：选中
    {
        // 对输入的值做限幅，小于20ms会弹出对话框提示
        if(ui->txtSendMs->text().toInt() >= 20) // 大于20ms 开启定时器
        {
            timSend->start(ui->txtSendMs->text().toInt());// 设置定时时长，重新计数
            ui->txtSendMs->setEnabled(false);            // 让时间输入框不可选，避免误操作（输入功能不可用，控件背景为灰色）
        }
        else    // 小于20ms 弹出提示框
        {
            ui->chkTimSend->setCheckState(Qt::Unchecked);
            QMessageBox::critical(this, "错误提示", "定时发送的最小间隔为 20ms\r\n请确保输入的值 >=20");
        }
    }
}

// 发送速率、接收速率统计-定时器
void MainWindow::dataRateCalculate(void)
{
    // 特定时间内 发送和接收的字节数以及帧率
    sendRate = sendNum - tSend; // 计算发送数据的传输速率，通过将当前发送的数据数量 sendNum 减去上一次计算时的数据数量 tSend 来得到
    recvRate = recvNum - tRecv; // 计算接收数据的传输速率，通过将当前接收的数据数量 recvNum 减去上一次计算时的数据数量 tRecv 来得到。
    recvFrameRate = recvFrameNum - tFrame;  // 计算接收的帧率，通过将当前接收的帧数量 recvFrameNum 减去上一次计算时的帧数量 tFrame 来得到。

    // 标签上显示
    setNumOnLabel(lblSendRate, "Byte/s: ", sendRate);   // 第二个参数是用于显示的描述性文本，第三个参数是速率值。
    setNumOnLabel(lblRecvRate, "Byte/s: ", recvRate);
    setNumOnLabel(lblFrameRate, "FPS: ", recvFrameRate);

    // 更新计算基准 以便下次使用
    tSend = sendNum;
    tRecv = recvNum;
    tFrame = recvFrameNum;
}

// "显示波形界面" 按键槽函数
// 记得把plot在析构中释放掉，不然很容易下次运行崩溃
void MainWindow::on_pushButton_clicked()
{
    plot->show();// 显示波形绘图窗口
}

// 帧过滤
// 适用于有帧头、功能字、有效字段长度、校验位的接收，无帧尾
// str：串口接收到的数据
void MainWindow::xFrameDataFilter(QByteArray *str, float value[])
{
    int num = str->size();  // 调用 size() 函数来获取字符串的长度，对于 QString 类型，size() 函数返回字符串中的字符数
    if(num) // 字符数大于零
    {
        for(int i=0; i<num; i++)    // 遍历接收到的数据字节数组中的每一个字节。
        {
            // 使用 at() 函数获取接收到的字节数组 str 中在索引 i 处的字节
            chrtmp[tnum] = str->at(i);  		// 从接收缓存区读取一个字节

            if (f_h_flag == 1)  // 有帧头。判断功能字、有效字段长度，接收消息
            {
                if (f_fun_word) // 有帧头，有功能字
                {
                    if (f_length) // 有帧头，有功能字，有有效字节长度
                    {
                        if((tnum-4) <f_length) // 有帧头，有功能字，未超出有效字节长度+校验位，接收数据
                        {
                            tnum ++;
                        }
                        else // 有帧头，有功能字，超出有效字节长度。判断校验位
                        {
                            // 累加和校验计算
                            unsigned char crc=0;
                            for(i=0; i<tnum;i++)
                            {
                                crc += chrtmp[i];
                            }

                            // 校验对比
                            if(crc == chrtmp[tnum]) // 校验通过，将缓冲区的数据打包发送
                            {
                                ++recvFrameNum;// 有效帧数量计数
                                setNumOnLabel(lblRecvFrameNum, "FNum: ", recvFrameNum);

                                // 根据功能字进行功能解析，自动根据帧长度解析为对应的real（与float等价）值。
                                if (f_fun_word == FunWord_WF)
                                {
                                    for (int i = 0; i < (f_length / 4); i++) // 每个值占用4字节(32位)
                                    {
                                        unsigned char* bytePtr = &chrtmp[i * 4 + 4];    // 在chrtmp数组中，real值被以字节表示，且在该数组中的偏移量为4。每个real值占用4个字节
                                        float floatValue;
                                        memcpy(&floatValue, bytePtr, sizeof(float));    // 将每个4字节的数据块解析为一个real值，
                                        value[i] = floatValue;  // 存储在value数组中
                                    }
                                }

                                // 显示波形（在这里显示可以处理多帧粘包，避免多帧粘包只显示一帧的情况）
                                if(!plot->isHidden())
                                {
                                    // 绘图窗口未隐藏，将解析出的short数组，传入波形图，进行绘图
                                    plot->ShowPlot_WaveForm(plot->pPlot1, value);
                                }

                            }
                            else
                            {
                                ++recvErrorNum;// 误码帧数量计数
                            }
                            tnum = 0;                            // 清0重新接收

                            // 清空标志位
                            f_h1_flag = 0;
                            f_h_flag = 0;
                            f_fun_word = 0;
                            f_length = 0;

                        }
                        // 把上面下面的判断标志位 == 1去掉
                    }
                    else    // 有帧头，有功能字，无效字节长度
                    {
                        if(chrtmp[tnum] <= ValidByteLength) // 小于有效字节最大长度
                        {
                            f_length = chrtmp[tnum];// 记录当前帧的有效字节长度
                            tnum ++;
                        }
                        else
                        {
                            tnum = 0;// 清0重新接收

                            // 清空标志位
                            f_h1_flag = 0;
                            f_h_flag = 0;
                            f_fun_word = 0;
                        }
                    }
                }
                else	// 有帧头，无功能字，判断是否为有效功能字
                {
                    if ((chrtmp[tnum] == FunWord_WF) || chrtmp[tnum] == FunWord_SM)
                    {
                        f_fun_word = chrtmp[tnum];//记录功能字
                        tnum ++;
                    }
                    else
                    {
                        tnum = 0;    // 清0重新接收

                        // 清空标志位
                        f_h1_flag = 0;
                        f_h_flag = 0;
                    }
                }
            }
            else	// 没有接收到帧头
            {
                if (f_h1_flag == 1)			        //没有帧头，有帧头1。下一步判断是否为第2个字节
                {
                    if (chrtmp[tnum] == Frame_Header2)          // 如果为帧头的第2个字节 3B，接收到帧头标志位标志位置1，tnum自增
                    {
                        f_h_flag = 1;
                        tnum ++;
                    }
                    else
                    {
                        // 这里再添加一个判断，出现 3A 3A 3B xx的情况，如果没有这个判断会重新计数，导致丢帧
                        if(chrtmp[tnum] == Frame_Header1)   // 3A 3A
                        {
                            f_h1_flag = 1;
                            tnum = 1;
                        }
                        else
                        {
                            // 重新计数，但如果出现 3A 3A 3B xx的情况，会导致丢帧，要加上上面的判断
                            f_h1_flag = 0;
                            tnum = 0;
                        }
                    }
                }
                else						//没有帧头，没有帧头1。下一步判断，是否为帧头的第1个字节
                {
                    if (chrtmp[tnum] == Frame_Header1)  // 如果为帧头的第1个字节，标志位置1，tnum自增
                    {
                        f_h1_flag = 1;
                        tnum ++;
                    }
                    else                                // 否则，标志位清0，tnum清0
                    {
                        tnum = 0;
                    }
                }
            }

            static int xx=0;
            // 判断多长的数据没有换行符，如果超过2000，会人为向数据接收区添加换行，来保证CPU占用率不会过高，不会导致卡顿
            // 但由于是先插入换行，后插入接收到的数据，所以每一箩数据并不是2000
            if(chrtmp[tnum] != 0x0A)
            {
                ++xx;
                if(xx > 2000)
                {
                    ui->txtRec->appendPlainText("");    // appendPlainText("") 是向文本框追加一个空字符串，即一个空白行。
                    ui->txtRec->appendPlainText("");
                    xx=0;   // 将变量 xx 的值重置为 0，以便下次再次判断。
                }
            }
            else
            {
                xx=0;
            }

            // 大于MaxFrameLength个字节的帧不接收
            if (tnum > (MaxFrameLength - 1) )
            {
                tnum = 0;
                f_h1_flag = 0;
                f_h_flag = 0;
                f_t1_flag = 0;
                continue;
            }
        }
    }
}

// 特征值提取并显示
void MainWindow::feature_extraction()
{
    // 使用了正则表达式匹配字符串
    // [-+]?: 匹配可能出现在数字前面的正负号。[-+] 表示匹配负号或正号，而 ? 表示前面的符号出现 0 次或 1 次。
    // [0-9]*: 匹配零个或多个数字字符。
    // \\.?: 匹配一个可能出现的小数点。\\. 表示匹配实际的小数点，而 ? 表示小数点可能出现 0 次或 1 次。
    // [0-9]+: 匹配一个或多个数字字
    const QString recStr = QString::fromLatin1(recBuf); // 将 QByteArray 转换为 QString
    set_measurement_value("HR=([-+]?[0-9]*\\.?[0-9]+)", ui->txtHR, recStr);
    set_measurement_value("SpO2=([-+]?[0-9]*\\.?[0-9]+)", ui->txtSpo2, recStr);
    set_measurement_value("SBP=([-+]?[0-9]*\\.?[0-9]+)", ui->txtSBP, recStr);
    set_measurement_value("DBP=([-+]?[0-9]*\\.?[0-9]+)", ui->txtDBP, recStr);
    set_measurement_value("BF=([-+]?[0-9]*\\.?[0-9]+)", ui->txtBF, recStr);
    set_measurement_value("MH=([-+]?[0-9]*\\.?[0-9]+)", ui->txtMH, recStr);
}

void MainWindow::set_measurement_value(const QString &regexPattern, QTextEdit *textEdit, const QString &recStr)
{
    QRegularExpression regex(regexPattern);                     // 正则表达式，匹配浮点数或整数格式
    QRegularExpressionMatch match = regex.match(recStr);        // 在接收到的数据中寻找匹配

    if (match.hasMatch()) {
        QString valueStr = match.captured(1);                       // 提取匹配到的字符串

        if (!valueStr.isEmpty()) {
            // 判断是整数还是浮点数
            bool isFloat = valueStr.contains('.');                  // 是否包含小数点

            bool ok = false;
            if (isFloat) {
                // 是浮点数，进行浮点数转换和显示
                float floatValue = valueStr.toFloat(&ok);           // 将字符串转换为浮点数
                if (ok) {
                    textEdit->setText(QString::number(floatValue));    // 将浮点数显示在 txtHR 文本框中
                }
            } else {
                int intValue = valueStr.toInt(&ok);                 // 将字符串转换为整数
                if (ok) {
                    textEdit->setText(QString::number(intValue));      // 将整数显示在 txtHR 文本框中
                }
            }
        }

        textEdit->setAlignment(Qt::AlignCenter);                       //  将文本居中显示
    }
}

// 处理保存按钮被点击时的操作
void MainWindow::on_btnSaveEig_clicked()
{
        // 弹出一个文件保存对话框，让用户选择保存文件的位置和名称。
        // 用户选择的文件名将存储在变量 fileName 中。
        QString fileName = QFileDialog::getSaveFileName(this, "Save Data", "", "CSV Files (*.csv);;All Files (*)");

        if (fileName.isEmpty()) {
            return; // 用户取消保存，函数直接返回，不进行后续的文件保存操作。
        }

        QFile file(fileName); // 指定的文件名 fileName 上创建一个QFile对象，用于文件操作。

        // 尝试以只写文本模式打开文件。如果文件无法打开，会弹出一个错误消息框，并且函数返回。
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open file for writing.");
            return;
        }

        // 创建一个 QTextStream 对象 out，用于将数据写入到文件中。
        QTextStream out(&file);

        // 写入CSV表头
        out << "HR,SpO2,SBP,DBP,BF,MH\n";

        // 从文本框 ui->txtHR 中读取数据并写入文件
        QString hrText = ui->txtHR->toPlainText();
        if (!hrText.isEmpty()) {
            out << hrText << ",";
        } else {
            out << ",";
        }

        // 从文本框 ui->txtSpo2 中读取数据并写入文件
        QString spo2Text = ui->txtSpo2->toPlainText();
        if (!spo2Text.isEmpty()) {
            out << spo2Text << ",";
        } else {
            out << "\n";
        }

        // 从文本框 ui->txtSBP 中读取数据并写入文件
        QString sbpText = ui->txtSBP->toPlainText();
        if (!sbpText.isEmpty()) {
            out << sbpText << ",";
        } else {
            out << "\n";
        }

        // 从文本框 ui->txtDBP 中读取数据并写入文件
        QString dbpText = ui->txtDBP->toPlainText();
        if (!dbpText.isEmpty()) {
            out << dbpText << ",";
        } else {
            out << "\n";
        }

        // 从文本框 ui->txtBF 中读取数据并写入文件
        QString bfText = ui->txtBF->toPlainText();
        if (!bfText.isEmpty()) {
            out << bfText << ",";
        } else {
            out << "\n";
        }

        // 从文本框 ui->txtBF 中读取数据并写入文件
        QString mhText = ui->txtMH->toPlainText();
        if (!mhText.isEmpty()) {
            out << mhText << "\n";
        } else {
            out << "\n";
        }

        // 关闭文件
        file.close();

        QMessageBox::information(this, "Success", "Data saved successfully to " + fileName);

}
