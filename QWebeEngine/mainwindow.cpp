#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Process.setWorkingDirectory("/home/ubuntu/Downloads/potree-1.6");
    //Process.execute("gulp watch");
    m_webView = new QWebEngineView(this);
    //m_webView->load(QUrl("/home/ubuntu/Documents/work/my first project/QWebeEngine/Ranger3/test.html"));
    m_webView->load(QUrl("http://localhost:8080"));
    m_webView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    m_webView->resize(this->size());
}
