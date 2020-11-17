#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QDebug>
#include "DlgSystemParam.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_count = 0;


        QtVariantPropertyManager *variantManager = new QtVariantPropertyManager();

        QString strName;

        int i = 0;
        QtProperty *topItem = variantManager->addProperty(QtVariantPropertyManager::groupTypeId(),
                    QString::number(i++) + QLatin1String(" Group Property"));
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

//        item = variantManager->addProperty(QVariant::Date, QString::number(i++) + QLatin1String(" Date Property"));
//        item->setValue(QDate::currentDate().addDays(2));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Time, QString::number(i++) + QLatin1String(" Time Property"));
//        item->setValue(QTime::currentTime());
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::DateTime, QString::number(i++) + QLatin1String(" DateTime Property"));
//        item->setValue(QDateTime::currentDateTime());
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::KeySequence, QString::number(i++) + QLatin1String(" KeySequence Property"));
//        item->setValue(QKeySequence(Qt::ControlModifier | Qt::Key_Q));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Char, QString::number(i++) + QLatin1String(" Char Property"));
//        item->setValue(QChar(386));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Locale, QString::number(i++) + QLatin1String(" Locale Property"));
//        item->setValue(QLocale(QLocale::Polish, QLocale::Poland));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Point, QString::number(i++) + QLatin1String(" Point Property"));
//        item->setValue(QPoint(10, 10));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::PointF, QString::number(i++) + QLatin1String(" PointF Property"));
//        item->setValue(QPointF(1.2345, -1.23451));
//        item->setAttribute(QLatin1String("decimals"), 3);
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Size, QString::number(i++) + QLatin1String(" Size Property"));
//        item->setValue(QSize(20, 20));
//        item->setAttribute(QLatin1String("minimum"), QSize(10, 10));
//        item->setAttribute(QLatin1String("maximum"), QSize(30, 30));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::SizeF, QString::number(i++) + QLatin1String(" SizeF Property"));
//        item->setValue(QSizeF(1.2345, 1.2345));
//        item->setAttribute(QLatin1String("decimals"), 3);
//        item->setAttribute(QLatin1String("minimum"), QSizeF(0.12, 0.34));
//        item->setAttribute(QLatin1String("maximum"), QSizeF(20.56, 20.78));
//        topItem->addSubProperty(item);

        item = variantManager->addProperty(QVariant::Rect, QString::number(i++) + QLatin1String(" Rect Property"));
        item->setValue(QRect(10, 10, 20, 20));
        topItem->addSubProperty(item);
        item->setAttribute(QLatin1String("constraint"), QRect(0, 0, 50, 50));

//        item = variantManager->addProperty(QVariant::RectF, QString::number(i++) + QLatin1String(" RectF Property"));
//        item->setValue(QRectF(1.2345, 1.2345, 1.2345, 1.2345));
//        topItem->addSubProperty(item);
//        item->setAttribute(QLatin1String("constraint"), QRectF(0, 0, 50, 50));
//        item->setAttribute(QLatin1String("decimals"), 3);

        item = variantManager->addProperty(QtVariantPropertyManager::enumTypeId(),
                        QString::number(i++) + QLatin1String(" Enum Property"));
        QStringList enumNames;
        enumNames << "Linescan3D" << "Areascan" << "Enum2";
        item->setAttribute(QLatin1String("enumNames"), enumNames);
        item->setValue(1);
        topItem->addSubProperty(item);
        strName = "DeviceScanType";
        m_property_dic[item] =strName;



//        item = variantManager->addProperty(QtVariantPropertyManager::flagTypeId(),
//                        QString::number(i++) + QLatin1String(" Flag Property"));
//        QStringList flagNames;
//        flagNames << "Flag0" << "Flag1" << "Flag2";
//        item->setAttribute(QLatin1String("flagNames"), flagNames);
//        item->setValue(5);
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::SizePolicy, QString::number(i++) + QLatin1String(" SizePolicy Property"));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Font, QString::number(i++) + QLatin1String(" Font Property"));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Cursor, QString::number(i++) + QLatin1String(" Cursor Property"));
//        topItem->addSubProperty(item);

//        item = variantManager->addProperty(QVariant::Color, QString::number(i++) + QLatin1String(" Color Property"));
//        topItem->addSubProperty(item);

        QtVariantEditorFactory *variantFactory = new QtVariantEditorFactory();

        QtTreePropertyBrowser *variantEditor = ui->widget;
        variantEditor->setFactoryForManager(variantManager, variantFactory);
        variantEditor->addProperty(topItem);
        variantEditor->setPropertiesWithoutValueMarked(true);
        variantEditor->setRootIsDecorated(false);

        variantEditor->show();

        connect(variantManager, SIGNAL(valueChanged(QtProperty *, const QVariant &)),
                    this, SLOT(on_valueChanged(QtProperty *, const QVariant &)));
    //ui->widget->setEnabled(false);
        qDebug()<<QString("main:: Frame lost:%1").arg(100);
        qDebug()<<"size of cloud3d:"<<sizeof(Cloud3D);

        m_pGrabberForCamera = new CGrabberForCamera();
        s_GrabberInitParam sGrabberInitParam;
    //    sGrabberInitParam.iImageWidth = m_iImageWidth;
    //    sGrabberInitParam.iImageHeight = m_iImageHeight;
    //    sGrabberInitParam.iImageHeight3D = m_iImageHeight3D;
        sGrabberInitParam.strLogFilesPath = "../../KDVisualInspect/Data/log/";
        sGrabberInitParam.strCTIFilesPath = "../../KDVisualInspect/Config/GenTL producer/linux_arm64/sickGenTLProducer.cti";
        sGrabberInitParam.isShowLOGInCMD = false;
        sGrabberInitParam.isWriteLOG = false;
        sGrabberInitParam.isUsingEncoder = false;

        sGrabberInitParam.strDeviceIPorMAC = "192.168.1.91";"192.168.1.91";"169.254.44.197";;
        sGrabberInitParam.isUsingIP = true;
        sGrabberInitParam.strCSVFilesPath = "../../KDVisualInspect/Config/Camera3D.csv";
        sGrabberInitParam.strCalibXMLPath = "../../KDVisualInspect/Config/CalibrationResult.json";

        sGrabberInitParam.strDataSavePath="../../KDVisualInspect/Data";;
        sGrabberInitParam.iBufferCount = 10;
        sGrabberInitParam.e_ImageType = 5;

        sGrabberInitParam.fScaleY = 1.0;

        //sGrabberInitParam.pCallBackFunc = std::bind(&MainWindow::ImgCallBack,this,_1);
        m_pGrabberForCamera->Init(sGrabberInitParam);

        //ui->widget_camera->registerCameraPointer(m_pGrabberForCamera);
}

MainWindow::~MainWindow()
{
    m_pGrabberForCamera->SaveToCSV("../../KDVisualInspect/Config/Camera3D.csv");
    delete m_pGrabberForCamera;
    delete ui;
}
void MainWindow::on_valueChanged(QtProperty *property, const QVariant &value)
{
    qDebug()<<"changed!"<<++m_count;
    QString s =m_property_dic[property];
        qDebug()<<s<<":"<<value;
        if(s == "TriggerMode_TriggerSelector_LineStart") {
            qDebug()<<"hello";
        }
}

void MainWindow::on_pushButton_clicked()
{
    CDlgSystemParam *dlg = new CDlgSystemParam(0,m_pGrabberForCamera);
    dlg->show();
}
