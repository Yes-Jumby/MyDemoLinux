#-------------------------------------------------
#
# Project created by QtCreator 2013-06-09T09:28:54
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Semaphore
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CFLAGS_ISYSTEM = -I
DESTDIR += $$PWD/../Bin
SOURCES += main.cpp \
    qhiredis.cpp \
    demo.cpp \
    baiduhiredis.cpp

HEADERS += \
    SpendTime.h

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lhiredis

INCLUDEPATH += $$PWD/../../../../../../usr/local/include/hiredis
DEPENDPATH += $$PWD/../../../../../../usr/local/include/hiredis

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/ -lev

INCLUDEPATH += $$PWD/../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../usr/include
