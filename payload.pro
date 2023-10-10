QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    MyThreadWorker.cpp \
    RPi_BNO055.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MyThreadWorker.h \
    RPi_BNO055.h \
    RPi_Sensor.h \
    imumaths.h \
    mainwindow.h \
    matrix.h \
    quaternion.h \
    vector.h

FORMS += \
    mainwindow.ui

LIBS += \
    -lpigpio

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
