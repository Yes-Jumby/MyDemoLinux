#include <sys/stat.h>

int main()
{
    mkdir("../gLogTest/hello",S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);//same as use mkdir in terminal
    return 0;
}
