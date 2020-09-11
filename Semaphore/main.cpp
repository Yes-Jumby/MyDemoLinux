#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>
#include <qdebug.h>
#include <qmutex.h>
#include <SpendTime.h>
const int DataSize=250000;
const int BufferSize=10;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);
int threadnum=0;
QString str="  ";
QMutex mutex;
//int index = 0;

//要定义两个信号量，一个用于表示自由空间，一个用于表示已用空间

class Producer : public QThread
 {
 public:
     void run();
 };

 void Producer::run()
 {
     for (int i = 0; i < DataSize; ++i) {
         freeBytes.acquire();//申请一个自由空间，没有就阻塞
         buffer[i % BufferSize] = i;
         usedBytes.release();//已用空间增加一个，有货啦！
     }
 }


class Consumer : public QThread
 {
 public:
     void run();
 };

 void Consumer::run()
 {
     for (int i = 0; i < DataSize; ++i) {
         usedBytes.acquire();
         //fprintf(stderr,"%d\n", buffer[i % BufferSize]);
         freeBytes.release();
     }
 }

int main(int argc, char *argv[])
 {
     QCoreApplication app(argc, argv);
     Producer producer;
     Consumer consumer;
     CSpendTimeMicro SpendTimeMicro;
     CSpendTimeNano SpendTimeNano;
     SpendTimeMicro.Start();
     SpendTimeNano.Start();
     producer.start();
     consumer.start();
     producer.wait();
     consumer.wait();
     fprintf(stderr,"MicroTime:%llu NanoTime:%llu\n", SpendTimeMicro.End(),SpendTimeNano.End());

     return 0;
 }
