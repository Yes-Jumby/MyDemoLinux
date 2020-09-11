#include "ThreadData.h"
#include <QDebug>
#include <QMessageBox>
CThreadData::CThreadData():
    m_bThreadruning(false)
{
}

void CThreadData::StartMyThread()
{
    m_bThreadruning = true;
    start(QThread::HighPriority);
}

void CThreadData::StopMyThread()
{
    if(m_bThreadruning)
    {
         qDebug()<<tr("++++++++++++++++++   wait end");
        m_bThreadruning = false;

        m_Semaphore.acquire();

        qDebug()<<tr("++++++++++++++++++   wait end success");
    }
}

void CThreadData::run()
{
    while (m_bThreadruning)
    {

        try
        {


            if(m_bThreadruning == false)
            {
                break;
            }



//            if(m_bThreadruning)
//            {
//                m_MutexFrameData.lock();
//                bool bWait = m_WaitCondition.wait(&m_MutexFrameData,200);
//                if(bWait)
//                {
//                    //qDebug()<<tr("=========bWait == true");
//                }
//                else
//                {
//                    //qDebug()<<tr("=========bWait == false");

//                }
//                m_MutexFrameData.unlock();
//            }
        }
        catch(...)
        {


        }

    }


    qDebug()<<tr("++++++++++++++++++end");
    m_Semaphore.release();

}
