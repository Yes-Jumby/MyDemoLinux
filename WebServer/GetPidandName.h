#ifndef GETPIDANDNAME_H
#define GETPIDANDNAME_H
#include <sys/types.h>
#include <string>
#include <vector>
class CGetPidandName
{
public:
    CGetPidandName();
    void getPidByNameSTD(std::vector<pid_t> &vecPid, const std::string &task_name_STD);
    void getNameByPidSTD(pid_t pid, std::string &task_name_STD) ;
};

#endif // GETPIDANDNAME_H
