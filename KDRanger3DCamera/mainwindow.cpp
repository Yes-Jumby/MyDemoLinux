#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent>
#include <QFuture>
#include <thread>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_bReadytoDisplay(true),m_bIsRunning(false),
    ui(new Ui::MainWindow)
{
    qRegisterMetaType<std::string>("std::string");
    ui->setupUi(this);
    m_pGrabberForCamera = std::make_shared<CGrabberForCamera>();
    m_pRanger3buffertohtml = std::make_shared<CRanger3buffertohtml>();
    connect(ui->widget_display,SIGNAL(loadFinished(bool)),this,SLOT(on_loadFinished(bool)));
    connect(this,SIGNAL(signalRefresh(const std::string &)),this,SLOT(on_signalRefresh(const std::string &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_signalRefresh(const std::string &path)
{
    Imghtml(path);
}

void MainWindow::ThreadWork_save()
{
    while(m_bIsRunning)
    {
        if(!qSaveQueue.empty())
        {
            std::cout<<"qSaveQueue size:"<<qSaveQueue.size()<<std::endl;
            s_GrabberCallBackParam * pInfo = qSaveQueue.front();
            qSaveQueue.pop();
            ImgSave(pInfo);
            qInitQueue.push(pInfo);
        }
        usleep(100);
    }
    std::cout << "ThreadWork_save stop" << std::endl;
}
void MainWindow::ThreadWork_show()
{
    while(m_bIsRunning)
    {
        if(qDisplayQueue.size()==3)
        {
            std::cout<<"qDisplayQueue size:"<<qDisplayQueue.size()<<std::endl;
            std::string path = qDisplayQueue.front();
            Imghtml(path);
            while(!qDisplayQueue.empty())
            {
                qDisplayQueue.pop();
            }
        }
        usleep(100);
    }
    std::cout << "ThreadWork_show stop" << std::endl;
}

void MainWindow::ImgCallBack(const s_GrabberCallBackParam* pInfo)
{
    //std::cout << "ImgCallBack iFrameCount:" <<pInfo->iFrameCount<< std::endl;
    if(pInfo->sBuffer3D.pBuffer==nullptr || pInfo->sBuffer2D.pBuffer==nullptr)
    {
        //std::cout << "ImgCallBack null buffer:" << std::endl;
        return;
    }
    s_GrabberCallBackParam * sInfo = nullptr;
    if(!qInitQueue.empty())
    {
        sInfo = qInitQueue.front();
        qInitQueue.pop();
        *sInfo = *pInfo;
        memcpy(pInfo->sBuffer3D.pBuffer,pInfo->sBuffer3D.pBuffer,sizeof(float)*pInfo->sBuffer3D.iImageRows*pInfo->sBuffer3D.iImageCols);
        memcpy(pInfo->sBuffer2D.pBuffer,pInfo->sBuffer2D.pBuffer,sizeof(unsigned char)*pInfo->sBuffer2D.iImageRows*pInfo->sBuffer2D.iImageCols);
        qSaveQueue.push(sInfo);
    }
}
void MainWindow::ImgSaveBin(const s_GrabberCallBackParam* pInfo)
{
    std::string path = pInfo->strDataSavePath+"/"+std::to_string(200623)+"_dat_cal_cloud3D_"+std::to_string(pInfo->iFrameCount)+ ".dat";
    ReadAndWriteDat.writebin(path,pInfo->cloud,pInfo->sBuffer3D.pBuffer,pInfo->sBuffer2D.pBuffer);
}
void MainWindow::ImgSave(const s_GrabberCallBackParam* pInfo)
{
    std::cout<<"pInfo2.3D:"<<pInfo->sBuffer3D.pBuffer<<std::endl;
    std::string pagename = "dat_cloud3D_potree_"+std::to_string(pInfo->iFrameCount);
    m_pRanger3buffertohtml->converterBuffertoPotree(pInfo->cloud,pInfo->sBuffer3D.pBuffer,
                                                pInfo->sBuffer2D.pBuffer,
                                                pInfo->strDataSavePath,
                                                pagename,
                                                "/home/ubuntu/Downloads/PotreeConverter-1.6/PotreeConverter/resources/page_template");
    pagename = "http://127.0.0.1:8080/" + pagename +".html";
    emit signalRefresh(pagename);
}
void MainWindow::Imghtml(const std::string &path)
{
    if(m_bReadytoDisplay)
    {
        m_QMutex.lock();
        m_bReadytoDisplay = false;
        ui->widget_display->setDisplayWeb(QUrl(QString::fromStdString(path)));
        m_QMutex.unlock();
    }

}
void MainWindow::on_loadFinished(bool ok)
{
    std::cout<<"finished:"<<ok<<std::endl;
    if(ok)
    {
        m_QMutex.lock();
        m_bReadytoDisplay = true;
        m_QMutex.unlock();
    }
}
void MainWindow::on_pushButton_init_clicked()
{
    m_iMemorySize =3;
    for(int i = 0;i < m_iMemorySize;i++)
    {
        s_GrabberCallBackParam * myParam = new s_GrabberCallBackParam();
        myParam->sBuffer2D.pBuffer = new unsigned char[2560*2000];
        myParam->sBuffer3D.pBuffer = new float[2560*2000];
        qInitQueue.push(myParam);
    }
    m_bIsRunning = true;
    std::thread * pthread = new std::thread(&MainWindow::ThreadWork_save,this);
    pthread->detach();
    delete pthread;
//    std::thread * pthread1 = new std::thread(&MainWindow::ThreadWork_show,this);
//    pthread1->detach();
//    delete pthread1;


    std::string savepath = "/home/ubuntu/Documents/work/Ranger3/SDK_UBUNTU_UPDATE_200521/data/image/";
    s_GrabberInitParam sGrabberInitParam;
    sGrabberInitParam.strLogFilesPath = "../Data/log/";
    sGrabberInitParam.strCTIFilesPath = "/home/ubuntu/Documents/work/Ranger3/SDK_UBUNTU_UPDATE_200521/SDK_UBUNTU/GenTL producer/x64-ubuntu/sickGenTLProducer.cti";
    sGrabberInitParam.isShowLOGInCMD = false;
    sGrabberInitParam.isWriteLOG = true;

    sGrabberInitParam.strDeviceIPorMAC = "169.254.157.170";
    sGrabberInitParam.isUsingIP = true;
    sGrabberInitParam.strCSVFilesPath = "/home/ubuntu/Documents/work/Ranger3/SDK_UBUNTU_UPDATE_200521/config/200525_3D.csv";
    sGrabberInitParam.strCalibXMLPath = "/home/ubuntu/Documents/work/Ranger3/SDK_UBUNTU_UPDATE_200521/config/CalibrationResult.xml";

    //sGrabberInitParam.strDataSavePath="/home/ubuntu/Documents/work/Ranger3/SDK_UBUNTU_UPDATE_200521/data/dat/";
    sGrabberInitParam.strDataSavePath="../Data/html";;
    sGrabberInitParam.iBufferCount = 10;
    sGrabberInitParam.e_ImageType = 5;
    using namespace std::placeholders;
    sGrabberInitParam.pCallBackFunc = std::bind(&MainWindow::ImgCallBack,this,_1);;
    m_pGrabberForCamera->Init(sGrabberInitParam);
}

void MainWindow::on_pushButton_startgrab_clicked()
{
//    m_pTimer->start(2000);
//    return;
    m_pGrabberForCamera->StartGrab();
}

void MainWindow::on_pushButton_stopgrab_clicked()
{
//    m_pTimer->stop();
//    return;
    m_pGrabberForCamera->StopGrab();
}

void MainWindow::on_pushButton_snap_clicked()
{
    m_pGrabberForCamera->SnapShot();
}

void MainWindow::on_pushButton_close_clicked()
{
//    for(int i=0;i<10;i++)
//    {
//        if(i%2==0)
//        {
//            ui->widget_display->setDisplayWeb(QUrl("http://127.0.0.1:8080/dat_cloud3D_potree_0.html"));
//        }
//        else {
//           ui->widget_display->setDisplayWeb(QUrl("http://127.0.0.1:8080/5_dat_cloud3D_potree_0.html"));
//        }
//        std::cout<<"i :"<<i<<std::endl;

//    }
//    return;
    m_pGrabberForCamera->Close();


    while(qInitQueue.size() != m_iMemorySize);
        m_bIsRunning = false;
    while(!qInitQueue.empty())
    {
        s_GrabberCallBackParam * sInfo = qInitQueue.front();
        qInitQueue.pop();
        delete []sInfo->sBuffer2D.pBuffer;
        sInfo->sBuffer2D.pBuffer = nullptr;
        delete []sInfo->sBuffer3D.pBuffer;
        sInfo->sBuffer3D.pBuffer = nullptr;
        delete sInfo;
        sInfo = nullptr;
        std::cout<<"size :"<<qInitQueue.size()<<std::endl;
    }
}

void MainWindow::on_pushButton_test_clicked()
{
        for(int i=0;i<10;i++)
        {
            if(i%2==0)
            {
                ui->widget_display->setDisplayWeb(QUrl("http://127.0.0.1:8080/dat_cloud3D_potree_0.html"));
            }
            else {
               ui->widget_display->setDisplayWeb(QUrl("http://127.0.0.1:8080/5_dat_cloud3D_potree_0.html"));
            }
            std::cout<<"i :"<<i<<std::endl;

        }
}
