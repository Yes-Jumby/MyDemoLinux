#-------------------------------------------------
#
# Project created by QtCreator 2020-06-23T09:57:37
#
#-------------------------------------------------

QT       += core gui
QT       += concurrent widgets
QT += webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(debug, debug|release){
CONFIG(debug, debug|release):TARGET = KDRanger3DCameraD
}else{
CONFIG(release, debug|release):TARGET = KDRanger3DCamera
}
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    QWidgetForPCView.cpp \
    readAndWriteDat.cpp

HEADERS += \
        mainwindow.h \
    QWidgetForPCView.h \
    readAndWriteDat.h

FORMS += \
        mainwindow.ui

DESTDIR += $$PWD/../Bin
INCLUDEPATH += $$PWD/Lib/ubuntu-x64/Inc
DEPENDPATH += $$PWD/Lib/ubuntu-x64/Inc
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lGrabberForCamera
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lGCBase_gcc42_v3_1
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lGenApi_gcc42_v3_1
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lGenIRanger
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lCommon
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lCalibrationWrapper
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lApiDll
LIBS += -L$$PWD/Lib/ubuntu-x64/Bin/ -lRanger3buffertohtml


LIBS +=  -lglog
LIBS +=  -llas
LIBS +=  -llaszip
LIBS +=  -lstdc++fs
LIBS += -llaszip
