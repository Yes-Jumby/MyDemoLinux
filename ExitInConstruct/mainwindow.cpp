#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"1";
    exit(0);
    qDebug()<<"2";
}

MainWindow::~MainWindow()
{
    qDebug()<<"hello";
    delete ui;
}
