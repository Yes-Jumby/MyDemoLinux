﻿#include <QCoreApplication>
#include <hiredis/hiredis.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}