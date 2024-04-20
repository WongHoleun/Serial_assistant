#include "mycombobox.h"

myComboBox::myComboBox(QWidget *parent) : QComboBox(parent)
{
    scanActivePort();   // 扫描可用串口
}

// 扫描可用串口
void myComboBox::scanActivePort()
{
    clear();    // 先清空列表项，防止多次刷新后重叠
    QStringList serialPortName;    // 串口端口号列表

    // 自动扫描当前可用串口，返回值追加到字符数组中
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {

        //serialPortName << info.portName();// 不携带有串口设备信息的文本
        // 携带有串口设备信息的文本
        QString serialPortInfo = info.portName() + ": " + info.description();// 串口设备信息，芯片/驱动名称
        serialPortName << serialPortInfo;
    }
    this->addItems(serialPortName);    // 可用串口号，显示到串口选择下拉框中
}

// 重写鼠标点击事件
void myComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {

        scanActivePort();   // 扫描可用串口
        showPopup();        // 弹出下拉框

    }
}
