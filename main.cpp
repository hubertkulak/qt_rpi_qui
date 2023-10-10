#include "mainwindow.h"
#include <QApplication>
#include "MyThreadWorker.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //MyThreadWorker thread;
    //thread.start();



    return a.exec();
}
