#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    unsigned int j;


    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    m_redisContext = redisConnectWithTimeout(IP, PORT, timeout);
    if (m_redisContext == NULL || m_redisContext->err) {
        if (m_redisContext) {
            m_str.sprintf("Connection error: %s\n", m_redisContext->errstr);
            ui->textEdit->append(m_str);
            redisFree(m_redisContext);
        } else {
            m_str.sprintf("Connection error: can't allocate redis context\n");
            ui->textEdit->append(m_str);
        }
        //exit(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    redisFree(m_redisContext);
}

void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<TEST_CMD_COUNT;i++)
    {
        m_reply = (redisReply *)redisCommand(m_redisContext,"LPUSH redisQT %d", i);
        m_str.sprintf("%u=======%u=======%s\n",m_reply->type, m_reply->integer,m_reply->str);
        ui->textEdit->append(m_str);
        freeReplyObject(m_reply);
    }
}
