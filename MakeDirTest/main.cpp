#include <sys/stat.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "/home/innovation-2/imu/hello1";
    int a = mkdir(str.c_str(),S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    cout<<a;
    return 0;
}
