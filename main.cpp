#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 在QApplication 创建之前加入代码，解决分辨率不同导致的文字压缩
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
