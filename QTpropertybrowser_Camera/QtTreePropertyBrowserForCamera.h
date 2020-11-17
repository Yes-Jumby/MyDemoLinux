#ifndef QTTREEPROPERTYBROWSERFORCAMERA_H
#define QTTREEPROPERTYBROWSERFORCAMERA_H

#include <QObject>
#include "qtpropertymanager.h"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"
#include "GrabberForCamera.h"
#include <QMap>
#include <QDebug>
class CQtTreePropertyBrowserForCamera :public QtTreePropertyBrowser
{
    Q_OBJECT
public:
    explicit CQtTreePropertyBrowserForCamera(/*CGrabberForCamera *pGrabberForCamera,*/QWidget *parent = nullptr);
    bool registerCameraPointer(CGrabberForCamera *pGrabberForCamera);
private slots:
    void on_valueChanged(QtProperty *property, const QVariant &value);
private:
    void init_();
    int m_count;
    QMap<QtProperty*,QString>m_property_dic;
    CGrabberForCamera *m_pGrabberForCamera;
};

#endif // QTTREEPROPERTYBROWSERFORCAMERA_H
