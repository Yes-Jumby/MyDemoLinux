#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConfigForKDVisualInspect.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CConfigForKDVisualInspect::setParameterFile("/home/ubuntu/Documents/work/MyDemoLinux/StaticConfigClass/default.yaml");
    float fx_ = CConfigForKDVisualInspect::get<float>("camera.fx");
    std::cout<<"fx_"<<fx_<<endl;
    std::string path_ = CConfigForKDVisualInspect::get<std::string>("dataset_dir");
    std::cout<<"path_"<<path_<<endl;


    cv::FileStorage file_write_;
    file_write_.open("/home/ubuntu/Documents/work/MyDemoLinux/StaticConfigClass/default-default.yaml", cv::FileStorage::WRITE);
    file_write_<<"MYMAXTRIS"<<cv::Mat::eye(3,3,CV_8UC1);
    file_write_.release();
}

MainWindow::~MainWindow()
{
    delete ui;
}
