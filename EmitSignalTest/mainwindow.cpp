#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qRegisterMetaType<QString>("QT::QString");
    connect(&m_EmitSignalOne,SIGNAL(myTestSignal(const QString &str)),this,SLOT(on_mysignal(const QString &str)));
    connect(&m_EmitSignalTwo,SIGNAL(myTestSignal(const QString &str)),this,SLOT(on_mysignal(const QString &str)));
    connect(this,SIGNAL(myTestSignal(const QString &str)),this,SLOT(on_mysignal(const QString &str)));
    m_EmitSignalOne.emitAsignal();
    m_EmitSignalTwo.emitAsignal();
    emit myTestSignal("MainWindow");

    //qRegisterMetaType<std::string>("std::string");
    connect(this,SIGNAL(signalRefresh(const std::string &str)),
            this,SLOT(on_signalRefresh(const std::string &str)));

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
