#include "QProcessServer.h"
#include "GetPidandName.h"
#include <QProcess>
#include <QDebug>
#include <signal.h>
CQProcessServer::CQProcessServer(const std::string &path):m_strPath(path),m_pCMD(nullptr)
{
    m_pCMD = std::make_shared<QProcess>();
    m_pCGetPidandName = std::make_shared<CGetPidandName>();
    m_pCMD->start("bash");             //启动终端(Windows下改为cmd)
    m_pCMD->waitForStarted();        //等待启动完成
    QString strCMD = "cd " + QString::fromStdString(m_strPath)+"\n";
    m_pCMD->write(strCMD.toLocal8Bit());
}

CQProcessServer::~CQProcessServer()
{
    if(m_pCMD)
    {
        m_pCMD->close();
        m_pCMD->waitForFinished();
    }
}

void CQProcessServer::openServer()
{
    QString strcmd = QString("live-server --port=%1 --host=%2 --no-browser --ignore=""\n").
            arg(m_strPort.c_str()).arg(m_strIp.c_str());
    m_pCMD->write(strcmd.toLocal8Bit());
}
void CQProcessServer::closeServer()
{
    std::string str="node";
    std::vector<pid_t> vecPid;
    m_pCGetPidandName->getPidByNameSTD(vecPid, str);
    qDebug()<<"pid_t size:"<<vecPid.size();
    for(int i=0;i<vecPid.size();i++)
    {
        qDebug()<<"getPidByNameQT:"<<vecPid.at(i);
        kill(vecPid.at(i),SIGINT);
    }
}

void CQProcessServer::setServerPort(const std::string &port)
{
    m_strPort = port;
}
void CQProcessServer::setServerIp(const std::string &ip)
{
    m_strIp = ip;
}
