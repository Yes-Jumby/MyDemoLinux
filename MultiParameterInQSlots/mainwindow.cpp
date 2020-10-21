#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(signalVTKRefresh(const float *,const size_t )),
            this,SLOT(on_signalVTKRefresh(const float *,const size_t )));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_signalVTKRefresh(const float *pFloat,const size_t isize) {
    //branch
    qDebug()<<"cloud size: "<<isize<<" pCloud:"<<pFloat;
}

void MainWindow::on_pushButton_clicked()
{
    float *p =new float[10];
    emit signalVTKRefresh(p,3825);
    delete []p;
}
