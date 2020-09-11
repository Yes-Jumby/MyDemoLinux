#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_webView = new QWebEngineView(this);
//    QWebEngineSettings* SETTING = m_webView->settings();
//    SETTING->setAttribute(QWebEngineSettings::LocalStorageEnabled,false);
    m_webView->load(QUrl("http://127.0.0.1:8080/DisplayInitnew.html"));
    //m_webView->load(QUrl("http://www.baidu.com"));

    m_webView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
