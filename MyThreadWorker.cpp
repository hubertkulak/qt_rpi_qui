#include "MyThreadWorker.h"
#include <QDebug>



MyThreadWorker::MyThreadWorker()
{

}

void MyThreadWorker::start()
{
    imu_first = new Adafruit_BNO055;
    imu_first->imu_initialization();

    timer = new QTimer();
    timer->start(1000);
    qDebug() << QString("start work in time");
    connect(timer,SIGNAL(timeout()),this,SLOT(doWork()));
}

void MyThreadWorker::doWork()
{

        imu_first->sig_bno_handler();
        gpioSleep(0, 0, 1000);
        imu_first->savevector();
        //zapis danych
        x=imu_first->myStruct.x;
        y=imu_first->myStruct.y;
        z=imu_first->myStruct.z;
        correct=imu_first->init_correct;
        qDebug()<<"Dane: " << x;

        emit dataReady(x, y, z, correct);

}


