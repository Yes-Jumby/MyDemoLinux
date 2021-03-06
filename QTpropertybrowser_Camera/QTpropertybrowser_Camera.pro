#-------------------------------------------------
#
# Project created by QtCreator 2020-10-22T18:46:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTpropertybrowser
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
        QConfig/KDConfig.cpp \
        main.cpp \
        mainwindow.cpp \
    QPropertyBrowser/QtTreePropertyBrowserForCamera.cpp \
    QPropertyBrowser/DlgSystemParam.cpp

HEADERS += \
        QConfig/KDConfig.h \
        mainwindow.h \
    QPropertyBrowser/QtTreePropertyBrowserForCamera.h \
    QPropertyBrowser/DlgSystemParam.h

FORMS += \
        mainwindow.ui \
    QPropertyBrowser/DlgSystemParam.ui

INCLUDEPATH +=/opt/Qt5.12.0/include/QtPropertyBrowser
LIBS += /opt/Qt5.12.0/lib/libQtPropertyBrowser.so


INCLUDEPATH += $$PWD/../../KDVisualInspect/Lib/ubuntu-x64/Inc
#DEPENDPATH += $$PWD/../Lib/ubuntu-x64/Inc
LIBS += -L$$PWD/../../KDVisualInspect/Lib/ubuntu-x64/Bin/ -lGrabberForCamera
