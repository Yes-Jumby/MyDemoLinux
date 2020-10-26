#ifndef QTTREEPROPERTYBROWSERFORCAMERA_H
#define QTTREEPROPERTYBROWSERFORCAMERA_H

#include <QObject>
#include "qtpropertymanager.h"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"
#include <QMap>
#include <QDebug>
class CQtTreePropertyBrowserForCamera :public QtTreePropertyBrowser
{
    Q_OBJECT
public:
    explicit CQtTreePropertyBrowserForCamera(QWidget *parent = nullptr);
private slots:
    void on_valueChanged(QtProperty *property, const QVariant &value);
private:
    int m_count;
    QMap<QtProperty*,QString>m_property_dic;
};

#endif // QTTREEPROPERTYBROWSERFORCAMERA_H
