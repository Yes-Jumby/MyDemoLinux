#ifndef SPENDTIME_H
#define SPENDTIME_H
#include<time.h>
#include<sys/time.h>
class CSpendTimeMicro
{
public:
    CSpendTimeMicro():m_lStart(0),m_lEnd(0){
    }
    ~CSpendTimeMicro(){}
    unsigned long long GetTimeStamp()
    {
    	return GetMicrosecond();
    }
    void Start()
    {
        m_lStart = GetMicrosecond();
    }
    unsigned long long End()
    {
        m_lEnd = GetMicrosecond();
        return (m_lEnd - m_lStart);
    }
private:
    unsigned long long GetMicrosecond() {
        timeval stTime;
        gettimeofday(&stTime, nullptr);
        return (static_cast<unsigned long long>(stTime.tv_sec) * 1000000 + static_cast<unsigned long long>(stTime.tv_usec));
    }
    unsigned long long m_lStart;
    unsigned long long m_lEnd;
};

class CSpendTimeNano
{
public:
    CSpendTimeNano():m_lStart(0),m_lEnd(0){
    }
    ~CSpendTimeNano(){}
    unsigned long long GetTimeStamp()
    {
        return GetNanosecond();
    }
    void Start()
    {
        m_lStart = GetNanosecond();
    }
    unsigned long long End()
    {
        m_lEnd = GetNanosecond();
        return (m_lEnd - m_lStart);
    }
private:
    unsigned long long GetNanosecond() {
        timespec stTime;
        clock_gettime(CLOCK_REALTIME, &stTime);
        return (static_cast<unsigned long long>(stTime.tv_sec) * 1000000000 + static_cast<unsigned long long>(stTime.tv_nsec));
    }
    unsigned long long m_lStart;
    unsigned long long m_lEnd;
};
#endif // SPENDTIME_H
