#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include <signal.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),cmd(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Interface.test();
    cmd = new QProcess(this);
    connect(cmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));
    connect(cmd , SIGNAL(readyReadStandardError()) , this , SLOT(on_readerror()));
    ui->lineEdit->setText("live-server --port=8888 --host=127.127.127.127 --no-browser --ignore=""");;
    cmdclass = new CQProcessServer("../Data/html");
    cmdclass->setServerIp("127.127.127.127");
    cmdclass->setServerPort("8888");
}

MainWindow::~MainWindow()
{
    if(cmd)
    {
        cmd->close();
        cmd->waitForFinished();
    }
    delete ui;
}

void MainWindow::on_start_clicked()
{
    strCmd = ui->lineEdit->text()+"\n";
    cmd->write(strCmd.toLocal8Bit());
    cmd->write("ls\n");
    //qDebug()<<cmd->processId();
}

void MainWindow::on_stop_clicked()
{
//    QString jsStr = QString("ps -ef|grep 'node'|grep -v grep|cut -c 10-16|xargs kill -9\n");
//    cmd->write("ps -ef|grep \"node\"|grep -v grep|cut -c 10-16|xargs kill -9\n");
    //cmd->execute("sh killthread.sh");
    //signal(SIGINT,SIG_DFL);
    kill(0,SIGINT);
}

void MainWindow::on_readoutput()
{
    ui->textEdit->append(cmd->readAllStandardOutput().data());
}

void MainWindow::on_readerror()
{
    std::cout<<cmd->readAllStandardError().data()<<std::endl;
    ui->textEdit1->append(cmd->readAllStandardError().data());
}

void MainWindow::on_start_2_clicked()
{
    cmd->start("bash");             //启动终端(Windows下改为cmd)
    cmd->waitForStarted();        //等待启动完成
    cmd->write("cd ../Data/html\n");               //向终端写入“ls”命令，注意尾部的“\n”不可省略
    cmd->write("ls\n");               //向终端写入“ls”命令，注意尾部的“\n”不可省略
    //qDebug()<<cmd->processId();
}

void MainWindow::on_start_CLASS_clicked()
{
    cmdclass->openServer();
}

void MainWindow::on_stop_CLASS_clicked()
{
    cmdclass->closeServer();
}
