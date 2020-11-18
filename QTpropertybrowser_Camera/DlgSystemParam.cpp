#include "DlgSystemParam.h"
#include "ui_DlgSystemParam.h"

CDlgSystemParam::CDlgSystemParam(QWidget *parent,CGrabberForCamera *pGrabberForCamera) :
    QDialog(parent),m_pGrabberForCamera(pGrabberForCamera),
    ui(new Ui::CDlgSystemParam)
{
    ui->setupUi(this);
    ui->widget->registerCameraPointer(m_pGrabberForCamera);
}

CDlgSystemParam::~CDlgSystemParam()
{
    delete ui;
}
