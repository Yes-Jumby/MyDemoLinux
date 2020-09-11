#ifndef THREADDATA_H
#define THREADDATA_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include <functional>


class CThreadData : public QThread
{
    Q_OBJECT
public:
    CThreadData();

    void StartMyThread();
    void StopMyThread();

private:
    bool m_bThreadruning;
    QWaitCondition m_WaitCondition;
    QSemaphore m_Semaphore;
    QMutex m_MutexFrameData;


protected:
    void run();

};

#endif // THREADDATA_H
