#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KDConfig.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CKDConfig::setParameterFile("../../hello1.ini");
    std::cout<<"a:"<<CKDConfig::getValue<int>("a")<<std::endl;
    std::cout<<"b:"<<CKDConfig::getValue<int>("b")<<std::endl;
    std::cout<<"c:"<<CKDConfig::getValue<QString>("c").toStdString()<<std::endl;
    CKDConfig::setValue("a",1900);
    CKDConfig::setValue("b",2000);
    CKDConfig::setValue("c","192.168.122.122");
    quint64 temp = 1000000000000;
    CKDConfig::setValue("c1",temp);
    uint64_t temp1  = 1000000000000;
    CKDConfig::setValue("temp1",(quint64)temp1);
    std::cout<<"a:"<<CKDConfig::getValue<int>("a")<<std::endl;
    std::cout<<"b:"<<CKDConfig::getValue<int>("b")<<std::endl;
    std::cout<<"c:"<<CKDConfig::getValue<QString>("c").toStdString()<<std::endl;
    std::cout<<"temp1:"<<CKDConfig::getValue<quint64>("temp1")<<std::endl;
    uint64_t temp2  = CKDConfig::getValue<quint64>("temp1");
    std::cout<<"temp2:"<<temp2<<std::endl;
//    std::cout<<"a:"<<typeid(int).name()<<" "<<(QString(typeid(int).name()) == "i")<<std::endl;
//    std::cout<<"a:"<<typeid(QString).name()<<" "<<(QString(typeid(QString).name()) == "7QString")<<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
