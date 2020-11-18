#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ren.init(ui->qvtkWidget->GetRenderWindow(),ui->qvtkWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    for(int i = 0;i<10;i++)
//    {
//        qsrand(QTime(0,0,0).secsTo((QTime::currentTime())));
//        float x,y,z;
//        std::vector<std::vector<float> > pts;
//        int randint = qrand()%100;
//        std::cout<<"randint:"<<randint<<std::endl;
//        for(int i =-100 ;i<=100;i++)
//        {
//            x =qrand()%randint;y=qrand()%randint;z=qrand()%randint;
//            std::vector<float> pts_xyz;
//            pts_xyz.push_back(x);
//            pts_xyz.push_back(y);
//            pts_xyz.push_back(z);
//            pts.push_back(pts_xyz);

//        }

//        m_ren.LoadPoints(pts);
//        std::cout << "nan :" << std::isnan(std::nanf("1"))<< std::endl;

//        //    qsrand(QTime(0,0,0).secsTo((QTime::currentTime())));
//        //    float x,y,z;
//        //    x = std::nanf("1");
//        //    std::vector<float> pts_xyz;
//        //    int randint = qrand()%100;
//        //    std::cout<<"randint:"<<randint<<std::endl;
//        //    for(int i =-100 ;i<=100;i++)
//        //    {
//        //        x =qrand()%randint;y=qrand()%randint;z=qrand()%randint;
//        //        pts_xyz.push_back(std::nanf("1"));
//        //        pts_xyz.push_back(std::nanf("1"));
//        //        pts_xyz.push_back(std::nanf("1"));

//        //    }
//        //    for(int i =0 ;i<10;i++)
//        //    {
//        //        x =qrand()%randint;y=qrand()%randint;z=qrand()%randint;


//        //        pts_xyz.push_back(x);
//        //        pts_xyz.push_back(y);
//        //        pts_xyz.push_back(z);

//        //    }

//        //    m_ren.LoadPoints(pts_xyz.data(),211);
//        //    m_ren.show();
//    }

    m_ren.LoadImage(nullptr,0,0);
}
