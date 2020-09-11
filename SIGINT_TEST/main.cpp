//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}

//#include <stdio.h>
//#include <pthread.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/types.h>

//#define true 1

//void * One(void * no)
//{
//    while (true)
//    {
//    printf("NUAACS1\n");
//    sleep(1);
//    }
//}

//void * Two(void * no)

//{
//    while (true)
//    {
//    printf("NUAACS2\n");
//    sleep(1);
//    }
//}

//void Stop(int signo)
//{
//    printf("oops! stop!!!\n");
//    _exit(0);
//}

//int main()
//{
//    int res;
//    pthread_t A, B;

//    signal(SIGINT, Stop);
//    res = pthread_create(&A, NULL, One, NULL);
//    res = pthread_create(&B, NULL, Two, NULL);
//    res = pthread_join(A, NULL);
//    res = pthread_join(B, NULL);
//    printf("all stop!!!\n");

//    return 0;
//}
//#include <QtCore>
//#include <signal.h>
//#include <cstdio>
//int getPID(const QByteArray &line) {
//   int pid = 0;
//   char c1, c2;
//   if (sscanf(line.data(), "@@@%d@@%c%c", &pid, &c1, &c2) == 3)
//      if (c1 == '@' && (c2 == '\r' || c2 == '\n')) return pid;
//   return 0;
//}

//int main(int argc, char *argv[]) {
//   auto input = QByteArray(
//                    "echo _kill_me_now_ > log\n"
//                    "/bin/sh -c 'echo @@@$$@@@>&2; exec tail -f log'\n"
//                    "echo done\n"
//                    "exit\n")
//                    .split('\n');
//   // tail -f will block

//   QCoreApplication app(argc, argv);
//   QProcess process;
//   int pid = 0;

//   auto const writeInputLine = [&] {
//      if (input.isEmpty()) return;
//      auto const line = input.takeFirst();
//      puts(line.data());
//      fflush(stdout);
//      process.write(line);
//      process.write("\n");
//   };

//   process.setProcessChannelMode(QProcess::SeparateChannels);
//   QObject::connect(&process, &QProcess::stateChanged, [](int state) {
//      auto static const meta = QMetaEnum::fromType<QProcess::ProcessState>();
//      fprintf(stderr, "State=%s\n", meta.key(state));
//      fflush(stderr);
//      if (state == QProcess::NotRunning) QCoreApplication::quit();
//   });
//   QObject::connect(&process, &QProcess::readyReadStandardError, [&] {
//      auto const data = process.readAllStandardError();
//      if (auto p = getPID(data)) pid = p; // we could suppress pid output here
//      fputs(data.data(), stdout);
//      fflush(stdout);
//      if (data.endsWith("$ ")) writeInputLine();
//   });
//   QObject::connect(&process, &QProcess::readyReadStandardOutput, [&] {
//      while (process.canReadLine()) {
//         auto const line = process.readLine();
//         fputs(line.data(), stdout);
//         if (line.startsWith("_kill_me_now_") && pid) {
//            kill(pid, SIGTERM);
//            pid = 0;
//         }
//      }
//      fflush(stdout);
//   });

//   process.start("/bin/sh", {"--noediting", "-i"});
//   return app.exec();
//}
//#include <sys/types.h>
//#include <dirent.h>
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//#define BUF_SIZE 1024

//void getPidByName(pid_t *pid, char *task_name)
// {
//     DIR *dir;
//     struct dirent *ptr;
//     FILE *fp;
//     char filepath[50];
//     char cur_task_name[50];
//     char buf[BUF_SIZE];

//     dir = opendir("/proc");
//     if (NULL != dir)
//     {
//         while ((ptr = readdir(dir)) != NULL) //循环读取/proc下的每一个文件/文件夹
//         {
//             //如果读取到的是"."或者".."则跳过，读取到的不是文件夹名字也跳过
//             if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
//                 continue;
//             if (DT_DIR != ptr->d_type)
//                 continue;

//             sprintf(filepath, "/proc/%s/status", ptr->d_name);//生成要读取的文件的路径
//             fp = fopen(filepath, "r");
//             if (NULL != fp)
//             {
//                 if( fgets(buf, BUF_SIZE-1, fp)== NULL ){
//                     fclose(fp);
//                     continue;
//                 }
//                 sscanf(buf, "%*s %s", cur_task_name);

//                 //如果文件内容满足要求则打印路径的名字（即进程的PID）
//                 if (!strcmp(task_name, cur_task_name)){
//                     sscanf(ptr->d_name, "%d", pid);
//                 }
//                 fclose(fp);
//             }
//         }
//         closedir(dir);
//     }
// }

// void getNameByPid(pid_t pid, char *task_name) {
//     char proc_pid_path[BUF_SIZE];
//     char buf[BUF_SIZE];

//     sprintf(proc_pid_path, "/proc/%d/status", pid);
//     FILE* fp = fopen(proc_pid_path, "r");
//     if(NULL != fp){
//         if( fgets(buf, BUF_SIZE-1, fp)== NULL ){
//             fclose(fp);
//         }
//         fclose(fp);
//         sscanf(buf, "%*s %s", task_name);
//     }
// }

// int main(int argc, char** argv)
// {
//     printf("task name is %s\n", argv[0]);
//     char task_name[50];
//     pid_t pid = getpid();

//     printf("pid of this process:%d\n", pid);
//     getNameByPid(pid, task_name);
//     for(int i=0;i<50;i++)
//     {
//         printf("task name is %c\n", task_name[i]);
//     }


//     /*
//     strcpy(task_name, argv[0]+2);
//     printf("task name is %s\n", task_name);
//     getPidByName(task_name);
//     */
//     printf("getNameByPid:%s\n", task_name);
//     getPidByName(&pid, task_name);
//     printf("getPidByName:%d\n", pid);
//     //sleep(15);
//     return 0;
// }
