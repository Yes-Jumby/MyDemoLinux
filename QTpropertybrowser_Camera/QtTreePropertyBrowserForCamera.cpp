#include "QtTreePropertyBrowserForCamera.h"
#include <memory>
CQtTreePropertyBrowserForCamera::CQtTreePropertyBrowserForCamera(/*CGrabberForCamera *pGrabberForCamera,*/QWidget *parent):
    m_pGrabberForCamera(nullptr),QtTreePropertyBrowser(parent)
{
    m_count = 0;

    QtVariantPropertyManager *variantManager = new QtVariantPropertyManager();
    //std::shared_ptr<QtVariantPropertyManager> variantManager = std::make_shared<QtVariantPropertyManager>();
    QString strName;

    int i = 0;
    QtProperty *cameraProperty = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(),
                                                      QLatin1String("Camera Property"));

    //bool
    strName = "TriggerMode_TriggerSelector_LineStart";
    QtVariantProperty *item = variantManager->addProperty(QVariant::Bool, strName);
    item->setValue(true);
    cameraProperty->addSubProperty(item);
    m_property_dic[item] =strName;

    //int
    strName = "Height_RegionSelector_Region1";
    item = variantManager->addProperty(QVariant::Int, strName);
    item->setValue(20);
    item->setAttribute(QLatin1String("minimum"), 0);
    item->setAttribute(QLatin1String("maximum"), 100);
    item->setAttribute(QLatin1String("singleStep"), 10);
    cameraProperty->addSubProperty(item);
    m_property_dic[item] =strName;



    // enum
    strName = "DeviceScanType";
    item = variantManager->addProperty(QtVariantPropertyManager::enumTypeId(),
                    strName);
    QStringList enumNames;
    enumNames << "Linescan3D" << "Areascan";
    item->setAttribute(QLatin1String("enumNames"), enumNames);
    item->setValue(1);
    cameraProperty->addSubProperty(item);
    m_property_dic[item] =strName;

    QtVariantEditorFactory *variantFactory = new QtVariantEditorFactory();

    QtTreePropertyBrowser *variantEditor = this;
    variantEditor->setFactoryForManager(variantManager, variantFactory);
    variantEditor->addProperty(cameraProperty);
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
            if(value.value<bool>()) {
                qDebug()<<"On";
                //m_pGrabberForCamera->SetParameter(s.toStdString(),"On");
            } else {
                qDebug()<<"Off";
                //m_pGrabberForCamera->SetParameter(s.toStdString(),"Off");
            }
        }
        if(s == "Height_RegionSelector_Region1") {
            qDebug()<<"hello";
            qDebug()<<value.value<int>();
            //m_pGrabberForCamera->SetParameter(s.toStdString(),value.value<int>());
        }
        if(s == "DeviceScanType") {
            qDebug()<<"hello";
            if(value.value<int>()==0) {
                qDebug()<<"Linescan3D";
                //m_pGrabberForCamera->SetParameter(s.toStdString(),"Linescan3D");
            } else {
                qDebug()<<"Areascan";
                //m_pGrabberForCamera->SetParameter(s.toStdString(),"Areascan");
            }
        }
}
bool CQtTreePropertyBrowserForCamera::registerPointer(CGrabberForCamera *pGrabberForCamera)
{
    if(pGrabberForCamera == nullptr) {
        return false;
    } else {
        m_pGrabberForCamera = pGrabberForCamera;
        return true;
    }
}
//    item = variantManager->addProperty(QVariant::Double, QString::number(i++) + QLatin1String(" Double Property"));
//    item->setValue(1.2345);
//    item->setAttribute(QLatin1String("singleStep"), 0.1);
//    item->setAttribute(QLatin1String("decimals"), 3);
//    topItem->addSubProperty(item);
//    strName = "double";
//    m_property_dic[item] =strName;

//    item = variantManager->addProperty(QVariant::String, QString::number(i++) + QLatin1String(" String Property"));
//    item->setValue("Value");
//    topItem->addSubProperty(item);
//    strName = "String";
//    m_property_dic[item] =strName;

//    item = variantManager->addProperty(QVariant::Rect, QString::number(i++) + QLatin1String(" Rect Property"));
//    item->setValue(QRect(10, 10, 20, 20));
//    topItem->addSubProperty(item);
//    item->setAttribute(QLatin1String("constraint"), QRect(0, 0, 50, 50));
