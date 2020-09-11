#include <QImage>
#include <QDebug>
enum imu{
    e_iiii,
    e_mmmm,
    e_uuuu,
};
int main()
{
    QImage image,imageBuffer;
    image.load("/home/ubuntu/1403636580063555584.png");
    qDebug()<<image.width();
    qDebug()<<image.height();
    qDebug()<<image.depth();
    qDebug()<<image.width()*image.height();
    qDebug()<<image.save("/home/ubuntu/ouput.png","png",100);
    imageBuffer = QImage(image.bits(),image.width(),image.height(),image.format());
    qDebug()<<imageBuffer.width();
    qDebug()<<imageBuffer.height();
    qDebug()<<imageBuffer.depth();
    qDebug()<<imageBuffer.width()*imageBuffer.height();
    qDebug()<<image.format();
    qDebug()<<imageBuffer.save("/home/ubuntu/ouputBuffer.png","png",100);
    imu iui = e_mmmm;
    qDebug()<<iui;
    return 0;
}
