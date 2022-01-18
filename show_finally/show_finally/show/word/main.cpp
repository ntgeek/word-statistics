#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    w.setWindowTitle("词频统计程序 -- by NewThread's Geek");
    return a.exec();
}
