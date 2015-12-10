#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash( QPixmap("Splash.png"));

    splash.show();
    a.processEvents();
    QThread::sleep(3);


    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
