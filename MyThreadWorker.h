#ifndef MYTHREADWORKER_H
#define MYTHREADWORKER_H

#include "qthread.h"
#include "RPi_BNO055.h"
#include "pigpio.h"
#include <qdebug.h>
#include <QObject>
#include <QTimer>

class MyThreadWorker : public QObject
{
    Q_OBJECT

    public:
        float x;
        float y;
        float z;
        int correct;

    public:
          MyThreadWorker();

    private:
        Adafruit_BNO055 * imu_first;
        QTimer * timer;

    signals:
        void dataReady(float x, float y, float z, int correct);

    public slots:
        void doWork();
        void start();
};

#endif // MYTHREADWORKER_H
