#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(QDateTime::currentDateTime().toString("yyyyMMdd hh:mm:ss.zzz "));
}

MainWindow::~MainWindow()
{
    delete ui;
}
