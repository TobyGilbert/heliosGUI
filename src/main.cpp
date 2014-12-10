#include <QApplication>
#include "mainwindow.h"
//------------------------------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MainWindow w;
    w.setStyleSheet("background-color: rgb(46, 46, 46)");
    w.setWindowTitle(QString("Helios"));
    w.show();
    app.exec();
}
//------------------------------------------------------------------------------------------------------------------------
