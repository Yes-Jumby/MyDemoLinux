#include <sys/stat.h>
//#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "/home/innovation-2/imu/hello1";

    string str2 = "../hello1/hello1";
    cout<<(opendir(str1.c_str()) == nullptr)<<endl;
    int a = mkdir(str1.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    cout<<opendir(str1.c_str())<<endl;
    cout<<a<<endl;
    a = mkdir(str2.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    cout<<a<<endl;

    if(opendir("../Data") == nullptr)
    {
        mkdir("../Data",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/cloud") == nullptr)
    {
        mkdir("../Data/cloud",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/dat") == nullptr)
    {
        mkdir("../Data/dat",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/image") == nullptr)
    {
        mkdir("../Data/image",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/log") == nullptr)
    {
        mkdir("../Data/log",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/log/INFO") == nullptr)
    {
        mkdir("../Data/log/INFO",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/log/ERROR") == nullptr)
    {
        mkdir("../Data/log/ERROR",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/log/WARNING") == nullptr)
    {
        mkdir("../Data/log/WARNING",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    if(opendir("../Data/log/FATAL") == nullptr)
    {
        mkdir("../Data/log/FATAL",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
    }
    return 0;
}
