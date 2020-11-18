#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QImage"
#include "QGraphicsScene"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->openGLWidget;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap img;
    img.load("D:/BZVisualInspect/PICTURE/200525_2d_0_SEN.xml.BMP");
    ui->labelPic->clear();
    ui->labelPic->setPixmap(img.scaled(ui->labelPic->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->labelPic->setAlignment(Qt::AlignCenter);

    QImage image;
    image.load("D:/BZVisualInspect/PICTURE/200525_2d_0_SEN.xml.BMP");
    ui->labelPic1->clear();
    ui->labelPic1->setPixmap(QPixmap::fromImage(image.scaled(ui->labelPic1->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation)));


    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(image.scaled(ui->graphicsView->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(image.width() + 10, image.height() + 10);
    ui->graphicsView->show();
}
