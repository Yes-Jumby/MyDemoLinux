#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string.h>
#include <thread>
#include <QKeySequence>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_iIndex(0),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Process = new QProcess(nullptr);
    ui->lineEdit_url->setText("http://127.0.0.1:8080/DisplayInit.html");
    ui->widget_web1->setDisplayWeb(QUrl("http://127.0.0.1:8080/DisplayInit.html"));
    ui->widget_web2->setDisplayWeb(QUrl("http://127.0.0.1:8080/DisplayInit.html"));
    ui->lineEdit_js->setText("5_dat_cloud3D_potree_0");
    //connect(this,SIGNAL(signalTest),this,SLOT(on_siganlTest));
    QKeySequence::Copy;
    //init Qtimer
    m_pTimer = new QTimer(this);
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(on_timeout()));
}

MainWindow::~MainWindow()
{
    //Process->execute("sh stop.sh");
    delete ui;
}

void MainWindow::on_pushButton_changeweb1_clicked()
{
    QString jsStr ="startLiveServer()";
    qDebug()<<jsStr;
    ui->widget_web1->runJavaScript(jsStr);
    //ui->widget_web1->setDisplayWeb(QUrl(ui->lineEdit_url->text()));
}

void MainWindow::on_pushButton_changeweb2_clicked()
{
    QString jsStr ="stopLiveServer()";
    qDebug()<<jsStr;
    ui->widget_web1->runJavaScript(jsStr);
    //ui->widget_web2->setDisplayWeb(QUrl(ui->lineEdit_url->text()));
}

void MainWindow::on_pushButton_callfunction_clicked()
{
    for(int i=0;i<674;i++)
    {
        qDebug()<<i;
        QString jsStr = QString("updatePointCloud(\"pointclouds/dat_cloud3D_potree_%1/cloud.js\")").arg(i);
        qDebug()<<jsStr;
        ui->widget_web1->runJavaScript(jsStr);
    }

}

void MainWindow::on_timeout()
{

    QString jsStr = QString("updatePointCloudoffline(\"pointclouds/dat_cloud3D_potree_%1/cloud.js\")").arg(m_iIndex);
    qDebug()<<jsStr;
    ui->widget_web1->runJavaScript(jsStr);
    ui->widget_web2->runJavaScript(jsStr);
    m_iIndex++;
    if(m_iIndex>673)
    {
        m_pTimer->stop();
    }
}

void MainWindow::on_pushButton_threadfun_clicked()
{
    //for(int i=0;i<10;i++)
    //{
        std::thread * pthread = new std::thread(&MainWindow::on_pushButton_callfunction_clicked,this);
        pthread->detach();
        delete pthread;
    //}

}

void MainWindow::on_pushButton_timerStart_clicked()
{
    m_pTimer->start(500);
}

void MainWindow::on_pushButton_timerStop_clicked()
{
    m_pTimer->stop();
    m_iIndex = 0;
}
