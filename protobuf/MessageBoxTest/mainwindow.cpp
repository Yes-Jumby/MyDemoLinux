#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_pMessageBox(std::make_shared<QMessageBox>(parent)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_info_clicked()
{

    QMessageBox::information(nullptr,"info","hello",QMessageBox::Yes|QMessageBox::No|QMessageBox::Ok|QMessageBox::Help|QMessageBox::Open|QMessageBox::Save);
}

void MainWindow::on_pushButton_critial_clicked()
{
    m_pMessageBox->setWindowModality(Qt::NonModal);
    m_pMessageBox->critical(nullptr,"critical","hello");
}

void MainWindow::on_pushButton_warn_clicked()
{
    m_pMessageBox->setWindowModality(Qt::WindowModal);
    m_pMessageBox->warning(nullptr,"warn","hello");
}

void MainWindow::on_pushButton_about_clicked()
{
    m_pMessageBox->setWindowModality(Qt::ApplicationModal);
    m_pMessageBox->about(nullptr,"about","hello");
}

void MainWindow::on_pushButton_test_clicked()
{
    QMessageBox::information(nullptr,"info","align failed , plz align again");
}
