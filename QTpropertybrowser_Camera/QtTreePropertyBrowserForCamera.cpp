#include "QtTreePropertyBrowserForCamera.h"
#include <memory>
CQtTreePropertyBrowserForCamera::CQtTreePropertyBrowserForCamera(QWidget *parent):QtTreePropertyBrowser(parent)
{
    m_count = 0;

    QtVariantPropertyManager *variantManager = new QtVariantPropertyManager();
    //std::shared_ptr<QtVariantPropertyManager> variantManager = std::make_shared<QtVariantPropertyManager>();
    QString strName;

    int i = 0;
    QtProperty *topItem = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                                      QLatin1String(" Group Property"));
    strName = "TriggerMode_TriggerSelector_LineStart";
    QtVariantProperty *item = variantManager->addProperty(QVariant::Bool, strName/*QString::number(i++) + QLatin1String(" Bool Property")*/);
    item->setValue(true);
    topItem->addSubProperty(item);

    m_property_dic[item] =strName;

    strName = "Height_RegionSelector_Region1";
    item = variantManager->addProperty(QVariant::Int, /*QString::number(i++) + */strName);
    item->setValue(20);
    item->setAttribute(QLatin1String("minimum"), 0);
    item->setAttribute(QLatin1String("maximum"), 100);
    item->setAttribute(QLatin1String("singleStep"), 10);
    topItem->addSubProperty(item);

    m_property_dic[item] =strName;

    item = variantManager->addProperty(QVariant::Double, QString::number(i++) + QLatin1String(" Double Property"));
    item->setValue(1.2345);
    item->setAttribute(QLatin1String("singleStep"), 0.1);
    item->setAttribute(QLatin1String("decimals"), 3);
    topItem->addSubProperty(item);
    strName = "double";
    m_property_dic[item] =strName;

    item = variantManager->addProperty(QVariant::String, QString::number(i++) + QLatin1String(" String Property"));
    item->setValue("Value");
    topItem->addSubProperty(item);
    strName = "String";
    m_property_dic[item] =strName;

    item = variantManager->addProperty(QVariant::Rect, QString::number(i++) + QLatin1String(" Rect Property"));
    item->setValue(QRect(10, 10, 20, 20));
    topItem->addSubProperty(item);
    item->setAttribute(QLatin1String("constraint"), QRect(0, 0, 50, 50));


    item = variantManager->addProperty(QtVariantPropertyManager::enumTypeId(),
                    QString::number(i++) + QLatin1String(" Enum Property"));
    QStringList enumNames;
    enumNames << "Linescan3D" << "Areascan" << "Enum2";
    item->setAttribute(QLatin1String("enumNames"), enumNames);
    item->setValue(1);
    topItem->addSubProperty(item);
    strName = "DeviceScanType";
    m_property_dic[item] =strName;

    QtVariantEditorFactory *variantFactory = new QtVariantEditorFactory();

    QtTreePropertyBrowser *variantEditor = this;
    variantEditor->setFactoryForManager(variantManager, variantFactory);
    variantEditor->addProperty(topItem);
    variantEditor->setPropertiesWithoutValueMarked(true);
    variantEditor->setRootIsDecorated(false);

    variantEditor->show();

    connect(variantManager, SIGNAL(valueChanged(QtProperty *, const QVariant &)),
                this, SLOT(on_valueChanged(QtProperty *, const QVariant &)));
}

void CQtTreePropertyBrowserForCamera::on_valueChanged(QtProperty *property, const QVariant &value)
{
    qDebug()<<"changed!"<<++m_count;
    QString s =m_property_dic[property];
        qDebug()<<s<<":"<<value;
        if(s == "TriggerMode_TriggerSelector_LineStart") {
            qDebug()<<"hello";
        }
}
