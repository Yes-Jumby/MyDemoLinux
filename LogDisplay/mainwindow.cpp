#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //showMaximized();
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int i = 0;i<100;i++)
    {
        ui->textBrowser->append("hello000000000000000000000000000000000000000");
        ui->textEdit->append("hello000000000000000000000000000000000000000");
    }

}
