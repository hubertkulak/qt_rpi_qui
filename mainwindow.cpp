#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //imuobiekt = new Adafruit_BNO055();
      auto thread = new QThread;
      auto worker = new MyThreadWorker();

      worker->moveToThread(thread);

     connect(thread, SIGNAL(started()), worker , SLOT(start()));
     connect(worker, SIGNAL(dataReady(float,float,float,int)), this, SLOT(updateData(float,float,float,int)));


     thread->start();

    //setting the temperature sliders range
    ui->slider1->setMinimum(10);
    ui->slider2->setMinimum(10);
    ui->slider1->setMaximum(50);
    ui->slider2->setMaximum(50);

    //imuobiekt->imu_initialization();
    gpioSleep(0, 0, 2000);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_opcja1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_opcja2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_opcja3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_opcja4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_opcja5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_option2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_option1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_option3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_slider1_valueChanged(int value)
{
    ui->lcd1->display(value);
}


void MainWindow::on_slider2_valueChanged(int value)
{
    ui->lcd2->display(value);
}

void MainWindow::on_setbtn_2_clicked()
{
    krotnosc1=ui->spinBoxphoto1->value();
    QString s = QString::number(krotnosc1);
    ui->photolabel1->setText(s);
}


void MainWindow::on_setbtn_3_clicked()
{
    krotnosc2=ui->spinBoxphoto2->value();
    QString s = QString::number(krotnosc2);
    ui->photolabel2->setText(s);
}


void MainWindow::on_opcja6_clicked()
{
    this->close();
}

void MainWindow::on_option3_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(imu_init==1){
    ui->imuinit->setText("Yes");
    }else {
    ui->imuinit->setText("No");
    }

        ui->imu1x->display(imux);
        ui->imu1y->display(imuz);
        ui->imu1z->display(imuy);
        gpioSleep(0, 0, 2000);
}

void MainWindow::updateData(float x, float y, float z , int correct)
{
    qDebug() << "Data x: " << x << " Z: "<< z << " Y: " << y <<" Init: " << correct;
    imux=x;
    imuy=y;
    imuz=z;
    imu_init = correct;

    if(imu_init==1){
    ui->imuinit->setText("Yes");
    }else {
    ui->imuinit->setText("No");
    }

        ui->imu1x->display(imux);
        ui->imu1y->display(imuy);
        ui->imu1z->display(imuz);
        gpioSleep(0, 0, 2000);
}
