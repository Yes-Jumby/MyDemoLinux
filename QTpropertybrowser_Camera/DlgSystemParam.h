#ifndef DLGSYSTEMPARAM_H
#define DLGSYSTEMPARAM_H

#include <QDialog>
#include "GrabberForCamera.h"
namespace Ui {
class CDlgSystemParam;
}

class CDlgSystemParam : public QDialog
{
    Q_OBJECT

public:
    explicit CDlgSystemParam(QWidget *parent = nullptr,CGrabberForCamera *pGrabberForCamera = nullptr);
    ~CDlgSystemParam();

private:
    Ui::CDlgSystemParam *ui;
    CGrabberForCamera* m_pGrabberForCamera;
};

#endif // DLGSYSTEMPARAM_H
