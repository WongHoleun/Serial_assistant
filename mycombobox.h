#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QMouseEvent>
#include <QSerialPort>
#include <QSerialPortInfo>

class myComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit myComboBox(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);   // 重写鼠标点击事件

signals:

private:
    void scanActivePort();

};

#endif // MYCOMBOBOX_H
