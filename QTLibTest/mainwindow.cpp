#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Interface.test();

    cmdclass = new CQProcessServer("../Data/html");
    cmdclass->setServerIp("127.0.0.1");
    cmdclass->setServerPort("8080");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_clicked()
{
    cmdclass->openServer();
}

void MainWindow::on_pushButton_close_clicked()
{
    cmdclass->closeServer();
}
