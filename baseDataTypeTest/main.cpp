#include <QDebug>

int main()
{
    qDebug()<<"int size:"<<sizeof(int);//4
    qDebug()<<"long size:"<<sizeof(long);//8
    qDebug()<<"long int size:"<<sizeof(long int);//8
    qDebug()<<"unsigned long int size:"<<sizeof(unsigned long int);//8
    qDebug()<<"uint64_t size:"<<sizeof(uint64_t);//8
    qDebug()<<"long long size:"<<sizeof(long long);//8
    qDebug()<<"unsigned long long size:"<<sizeof(unsigned long long);//8
    return 0;
}
