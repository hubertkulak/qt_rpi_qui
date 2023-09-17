#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QStackedWidget>
#include <QVBoxLayout>
#include "qcustomplot.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setting_plot();



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

     void realtimeDataSlot();


     void on_setbtn_2_clicked();

     void on_setbtn_3_clicked();

     void on_opcja6_clicked();

 private:
     int krotnosc1;
     int krotnosc2;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
