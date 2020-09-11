#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <QString>
#include <QDebug>
#include <vector>
#include <signal.h>
#define BUF_SIZE 1024

void getPidByName(pid_t *pid, char *task_name)
 {
     DIR *dir;
     struct dirent *ptr;
     FILE *fp;
     char filepath[50];
     char cur_task_name[50];
     char buf[BUF_SIZE];

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
                 if (!strcmp(task_name, cur_task_name)){
                     sscanf(ptr->d_name, "%d", pid);
                 }
                 fclose(fp);
             }
         }
         closedir(dir);
     }
 }
void getNameByPid(pid_t pid, char *task_name) {
    char proc_pid_path[BUF_SIZE];
    char buf[BUF_SIZE];

    sprintf(proc_pid_path, "/proc/%d/status", pid);
    FILE* fp = fopen(proc_pid_path, "r");
    if(nullptr != fp){
        if( fgets(buf, BUF_SIZE-1, fp)== nullptr ){
            fclose(fp);
        }
        fclose(fp);
        sscanf(buf, "%*s %s", task_name);
    }
}
void getPidByNameSTD(std::vector<pid_t> &vecPid, const std::string &task_name_STD)
 {
     vecPid.clear();
     DIR *dir;
     struct dirent *ptr;
     FILE *fp;
     char filepath[BUF_SIZE];
     char cur_task_name[BUF_SIZE];
     char buf[BUF_SIZE];
     pid_t pid;

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


 void getNameByPidSTD(pid_t pid, std::string &task_name_STD) {
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
 void getPidByNameQT(std::vector<pid_t> &vecPid, const QString &task_name)
  {
      vecPid.clear();
      DIR *dir;
      struct dirent *ptr;
      FILE *fp;
      char filepath[BUF_SIZE];
      char cur_task_name[BUF_SIZE];
      char buf[BUF_SIZE];
      pid_t pid;

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
                  if (!strcmp(task_name.toLocal8Bit().data(), cur_task_name)){
                      sscanf(ptr->d_name, "%d", &pid);
                      vecPid.push_back(pid);
                  }
                  fclose(fp);
              }
          }
          closedir(dir);
      }
  }


  void getNameByPidQT(pid_t pid, QString &task_name_qt) {
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
          task_name_qt = QString::fromLocal8Bit(task_name);
      }
  }
#include <iostream>
 int main(int argc, char** argv)
 {
//     QString str="SIGINT_TEST";
//     QString str1="node";
//     qDebug()<<strcmp(str.toLocal8Bit().data(), str1.toLocal8Bit().data());
//     printf("task name is %s\n", argv[0]);
//     char task_name[50];
//     pid_t pid = getpid();

//     printf("pid of this process:%d\n", pid);
//     getNameByPid(pid, task_name);
//     qDebug()<<strcmp(str.toLocal8Bit().data(), task_name);
//     printf("getNameByPid:%s\n", task_name);
//     getPidByName(&pid, task_name);
//     printf("getPidByName:%d\n", pid);

     std::string str="node";
//     pid_t pid = getpid();
//     getNameByPidSTD(pid, str);
//     //std::cout<<"getNameByPidQT:"<<std::endl;
//     std::cout<<"getNameByPidQT:"<<str<<std::endl;
     std::vector<pid_t> vecPid;
     getPidByNameSTD(vecPid, str);
     for(int i=0;i<vecPid.size();i++)
     {
         qDebug()<<"getPidByNameQT:"<<vecPid.at(i);
         kill(vecPid.at(i),SIGINT);
     }
     //sleep(15);
     return 0;
 }
