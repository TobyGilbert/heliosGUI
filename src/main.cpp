#include <QApplication>
#include "mainwindow.h"
//------------------------------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MainWindow w;

    QFile File("styleSheet/darkOrange");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    w.setStyleSheet(StyleSheet);
   // w.setStyleSheet("background-color: rgb(46, 46, 46)");
    w.setWindowTitle(QString("Helios"));
    w.show();
    app.exec();
}
//------------------------------------------------------------------------------------------------------------------------
