#include <sys/stat.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "/home/innovation-2/imu/hello1";

    string str2 = "../../hello1/hello1";
    int a = mkdir(str1.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    cout<<a<<endl;
    a = mkdir(str2.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    cout<<a<<endl;
    return 0;
}
