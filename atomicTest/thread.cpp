
#include <iostream>
#include <ctime>
#include <mutex>
#include <vector>
#include <thread>

std::mutex mtx;
size_t count = 0;

void threadFun()
{
    for (int i = 0; i < 100; i++)
    {
        // 防止多个线程同时访问同一资源
        std::unique_lock<std::mutex> lock(mtx);
        count++;
std::cout << count << std::endl;
    }
}

int main3(void)//172750
{
    clock_t start_time = clock();

    // 启动多个线程
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
        threads.push_back(std::thread(threadFun));
    for (auto&thad : threads)
        thad.join();

    // 检测count是否正确 10000*10 = 100000
    std::cout << "count number:" << count << std::endl;

    clock_t end_time = clock();
    std::cout << "耗时：" << end_time - start_time << "ms" << std::endl;

    return 0;
}

//#include <iostream>//20973
//#include <ctime>
//#include <vector>
//#include <thread>
//#include <atomic>


//std::atomic<size_t> count1(0);

//void threadFun()
//{
//    for (int i = 0; i < 100; i++)
//    {
//        count1++;
//        std::cout << count1 << std::endl;
//    }

//}

//int main(void)
//{
//    clock_t start_time = clock();

//    // 启动多个线程
//    std::vector<std::thread> threads;
//    for (int i = 0; i < 10; i++)
//        threads.push_back(std::thread(threadFun));
//    for (auto&thad : threads)
//        thad.join();

//    // 检测count是否正确 10000*10 = 100000
//    std::cout << "count number:" << count1 << std::endl;

//    clock_t end_time = clock();
//    std::cout << "耗时：" << end_time - start_time << "ms" << std::endl;

//    return 0;
//}
