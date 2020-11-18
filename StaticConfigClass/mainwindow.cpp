#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KDConfig.h"
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
    std::cout<<"a:"<<CKDConfig::getValue<int>("a")<<std::endl;
    std::cout<<"b:"<<CKDConfig::getValue<int>("b")<<std::endl;
    std::cout<<"c:"<<CKDConfig::getValue<QString>("c").toStdString()<<std::endl;
//    std::cout<<"a:"<<typeid(int).name()<<" "<<(QString(typeid(int).name()) == "i")<<std::endl;
//    std::cout<<"a:"<<typeid(QString).name()<<" "<<(QString(typeid(QString).name()) == "7QString")<<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
