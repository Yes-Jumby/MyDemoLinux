#ifndef QPROCESSSERVER_H
#define QPROCESSSERVER_H
#include <memory>
#include <functional>

class QProcess;
class CGetPidandName;
class  CQProcessServer
{
public:
    CQProcessServer(const std::string &path);
    ~CQProcessServer();
    void openServer();
    void closeServer();
    //use if need.After set,use closeServer to make it works.
    void setServerPort(const std::string &port);
    void setServerIp(const std::string &ip);
private:
    std::shared_ptr<QProcess> m_pCMD;
    std::shared_ptr<CGetPidandName> m_pCGetPidandName;
    std::string m_strPath;
    std::string m_strPort;
    std::string m_strIp;
};

#endif // QPROCESSSERVER_H
