#include "GetPidandName.h"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#define BUF_SIZE 1024
CGetPidandName::CGetPidandName()
{

}

void CGetPidandName::getPidByNameSTD(std::vector<pid_t> &vecPid, const std::string &task_name_STD)
 {
     vecPid.clear();
     DIR *dir;
     struct dirent *ptr;
     FILE *fp;
     char filepath[BUF_SIZE];
     char cur_task_name[BUF_SIZE];
     char buf[BUF_SIZE];
     pid_t pid = -1;

     dir = opendir("/proc");
     if (nullptr != dir)
     {
         while ((ptr = readdir(dir)) != nullptr) //循环读取/proc下的每一个文件/文件夹
         {
             //如果读取到的是"."或者".."则跳过，读取到的不是文件夹名字也跳过
             if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
                 continue;
             if (DT_DIR != ptr->d_type)
                 continue;

             sprintf(filepath, "/proc/%s/status", ptr->d_name);//生成要读取的文件的路径
             fp = fopen(filepath, "r");
             if (nullptr != fp)
             {
                 if( fgets(buf, BUF_SIZE-1, fp)== nullptr ){
                     fclose(fp);
                     continue;
                 }
                 sscanf(buf, "%*s %s", cur_task_name);

                 //如果文件内容满足要求则打印路径的名字（即进程的PID）
                 if (!strcmp(task_name_STD.c_str(), cur_task_name)){
                     sscanf(ptr->d_name, "%d", &pid);
                     vecPid.push_back(pid);
                 }
                 fclose(fp);
             }
         }
         closedir(dir);
     }
 }


 void CGetPidandName::getNameByPidSTD(pid_t pid, std::string &task_name_STD) {
     char proc_pid_path[BUF_SIZE];
     char buf[BUF_SIZE];
     char task_name[BUF_SIZE];

     sprintf(proc_pid_path, "/proc/%d/status", pid);
     FILE* fp = fopen(proc_pid_path, "r");
     if(nullptr != fp){
         if( fgets(buf, BUF_SIZE-1, fp)== nullptr ){
             fclose(fp);
         }
         fclose(fp);
         sscanf(buf, "%*s %s", task_name);
         task_name_STD = task_name;
     }
 }
