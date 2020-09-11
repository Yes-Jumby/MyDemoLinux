#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
bool running = true;
class QConsumer : public QThread
 {
 public:
    QConsumer(redisContext *c):m_redisContext(c){}
     void run();
private:
     redisContext *m_redisContext;
     redisReply *m_reply;
 };

void QConsumer::run()
{
    printf("QConsumer 1\n");
    for(int i=0;i<1000;i++) {
    m_reply = (redisReply *)redisCommand(m_redisContext,"BRPOP redisQT 1");
    printf("LPOP=%u=======%u=======%s=======%s\n", m_reply->type,m_reply->elements, m_reply->element[0]->str, m_reply->element[1]->str);
    usleep(100);
    }
    printf("QConsumer 2\n");
}
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
        m_reply = (redisReply *)redisCommand(m_redisContext,"BRPOP redisQT 1");
        m_str.sprintf("%u=======%u=======%s=======%s\n", m_reply->type,m_reply->elements, m_reply->element[0]->str, m_reply->element[1]->str);;
        ui->textEdit->append(m_str);
        freeReplyObject(m_reply);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QConsumer Consumer(m_redisContext);
    Consumer.start();
    Consumer.wait();
}

void MainWindow::on_pushButton_3_clicked()
{
    running = false;
}
