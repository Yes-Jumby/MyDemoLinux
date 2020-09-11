#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis.h>
#include <QThread>
#include <QMutex>
#define PORT 6379
#define IP   "127.0.0.1"
#define TEST_CMD_COUNT 100
bool bruning = true;
unsigned long long num = 0;
//QMutex myQMutex;
class QProducer : public QThread
 {
 public:
    QProducer(redisContext *c):m_redisContext(c){}
     void run();
private:
     redisContext *m_redisContext;
     redisReply *m_reply;
 };
void QProducer::run()
{
    printf("QProducer 1\n");
    while (bruning) {
        //myQMutex.lock();
        m_reply = (redisReply *)redisCommand(m_redisContext,"RPUSH redisQT %d", num);
        //printf("LPUSH=%u=======%u=======%s\n",m_reply->type, m_reply->integer,m_reply->str);
        //myQMutex.unlock();
        //printf("LPUSH=%llu\n", num);
        num++;
        usleep(10000);
    }
    printf("QProducer 2\n");
}

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
    while (bruning) {
        //myQMutex.lock();
    m_reply = (redisReply *)redisCommand(m_redisContext,"BLPOP redisQT 1");
    //printf("LPOP=%u=======%u=======%s=======%s\n", m_reply->type,m_reply->elements, m_reply->element[0]->str, m_reply->element[1]->str);
    printf("LPOP=%s\n", m_reply->element[1]->str);
    //myQMutex.unlock();
    usleep(10000);
    }
    printf("QConsumer 2\n");
}

int mainqqq(int argc, char *argv[])
 {
    unsigned int j;
    redisContext *c[2];
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    for(int i=0;i<2;i++)
    {
        c[i] = redisConnectWithTimeout(hostname, port, timeout);
        if (c[i] == NULL || c[i]->err) {
            if (c[i]) {
                printf("Connection error: %s\n", c[i]->errstr);
                redisFree(c[i]);
            } else {
                printf("Connection error: can't allocate redis context\n");
            }
            exit(1);
        }
    }

     QProducer producer(c[0]);
     QConsumer consumer(c[1]);

     producer.start();
     consumer.start();

     producer.wait();
     consumer.wait();

     /* Disconnects and frees the context */
     for(int i=0;i<2;i++)
     {
        redisFree(c[i]);
     }
     return 0;
 }
