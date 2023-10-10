#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QStackedWidget>
#include <QVBoxLayout>
#include "RPi_BNO055.h"
#include "RPi_BNO055.h"
#include "pigpio.h"
#include "MyThreadWorker.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:

     int krotnosc1;
     int krotnosc2;
     float imux;
     float imuy;
     float imuz;
     int imu_init;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateData(float x, float y, float z, int correct);


private slots:

    void on_opcja1_clicked();

    void on_opcja2_clicked();

    void on_opcja3_clicked();

    void on_opcja4_clicked();

    void on_opcja5_clicked();

    void on_option2_clicked();

    void on_option1_clicked();

    void on_option3_clicked();

    void on_pushButton_clicked();


    void on_slider1_valueChanged(int value);

    void on_slider2_valueChanged(int value);


     void on_setbtn_2_clicked();

     void on_setbtn_3_clicked();

     void on_opcja6_clicked();


     void on_option3_2_clicked();


     //Adafruit_BNO055 * imuobiekt;
     void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
