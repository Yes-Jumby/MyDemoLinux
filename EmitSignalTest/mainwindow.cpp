#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qRegisterMetaType<QString>("QT::QString");
    connect(&m_EmitSignalOne,SIGNAL(myTestSignal(const QString &)),this,SLOT(on_mysignal(const QString &)));
    connect(&m_EmitSignalTwo,SIGNAL(myTestSignal(const QString &)),this,SLOT(on_mysignal(const QString &)));
    connect(this,SIGNAL(myTestSignal(const QString &)),this,SLOT(on_mysignal(const QString &)));
    m_EmitSignalOne.emitAsignal();
    m_EmitSignalTwo.emitAsignal();
    emit myTestSignal("MainWindow");

    //qRegisterMetaType<std::string>("std::string");
    connect(this,SIGNAL(signalRefresh(const std::string &)),
            this,SLOT(on_signalRefresh(const std::string &)));

    emit signalRefresh("hehe");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_mysignal(const QString &str)
{
    ui->textEdit->append(str);
}

void MainWindow::on_signalRefresh(const std::string &path) {
    ui->textEdit->append(QString::fromStdString(path));
}
