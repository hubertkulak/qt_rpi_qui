#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QRandomGenerator>
#include <stdlib.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      //setting the background
    QPixmap backg("/home/hubertkulak/qtwork/m3/wave.png");
    backg = backg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, backg);
    this->setPalette(palette);

    QTimer dataTimer;

      //setting the temperature sliders range
    ui->slider1->setMinimum(10);
    ui->slider2->setMinimum(10);
    ui->slider1->setMaximum(50);
    ui->slider2->setMaximum(50);

    ui->customPlot->addGraph(); // blue line
    ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-1.2, 1.2);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
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

void MainWindow::realtimeDataSlot()
{
    static QElapsedTimer timer;
    // calculate two new data points:
    double key = timer.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
        // add data to lines:
        ui->customPlot->graph(0)->addData(key, 1);
        ui->customPlot->graph(1)->addData(key, 1);
        // rescale value (vertical) axis to fit the current data:
        //ui->customPlot->graph(0)->rescaleValueAxis();
        //ui->customPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        ui->statusBar->showMessage(
            QString("%1 FPS, Total Data points: %2")
                .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
            , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
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

