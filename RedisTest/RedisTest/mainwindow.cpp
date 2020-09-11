#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<int> list;
    list.push_back(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
