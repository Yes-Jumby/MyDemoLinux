#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QCoreApplication>
//#include <QDir>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Process.setWorkingDirectory("/home/ubuntu/Downloads/potree-1.6");
//    ui->label1->setText(QCoreApplication::applicationDirPath());
//    ui->label2->setText(QDir::currentPath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    Process.execute("sudo gulp watch");
}

void MainWindow::on_stop_clicked()
{
    //Process.execute("^C");
}
