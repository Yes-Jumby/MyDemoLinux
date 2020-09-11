#include <iostream>
 #include <thread>
 #include <atomic>
using namespace std;
 atomic<int> a{ 0 };
 atomic<int> b{ 0 };
 int c =0;
 void SetValue()
 {// atomic类模板中的函数都是原子操作.  int temp = a.load();相当于 int temp = a的原子操作
//     int t = 1;
//     a.store(t, memory_order_seq_cst); // 相当于 a = t的原子操作
//     b.store(2, memory_order_seq_cst); // 相当于 b = 2的原子操作
     for(int i = 0;i<100;i++)
     {
//         a++;
//         b++;
         //c++;
         //cout << a << " "<< b <<" "<<c<< endl;
         cout <<"too lag to big to win!!!"<< endl;
     }

 }
 void Observer()
 {
     //cout << a << endl<< b << endl;
 }
 struct s_AtomicTimestamp
 {
     s_AtomicTimestamp():CameraStampBase(0),GPSStampBase(0){}
     const s_AtomicTimestamp& operator=(const s_AtomicTimestamp& AtomicTimestamp)
     {
         CameraStampBase.store(AtomicTimestamp.CameraStampBase);
         GPSStampBase.store(AtomicTimestamp.GPSStampBase);
         return *this;
     }
     std::atomic_uint64_t CameraStampBase;
     std::atomic_uint64_t GPSStampBase;
 };
 int main()
 {
     int c = 1000;
     cout << a << endl;
     c = a.load();
     cout << c << endl;
     c = 100;
     a.store(c);
     cout << a << endl;

     return 0;
//     thread T2(SetValue);
//     thread T1(SetValue);


//     T1.join(); // 主线程(调用方)等待子线程 T1 执行完成,才能继续执行,阻塞
//     T2.join(); // 同上,执行这一行前: T1已经结束,T2很可能也结束了
//     return 0;
//     a =1;
//     b =3;
//     int c = a + b;
//     cout << a << endl<< b << endl<< c << endl;
//     s_AtomicTimestamp sTamp1,sTamp2;
//     sTamp1.CameraStampBase=100;
//     sTamp1.GPSStampBase=200;
//    cout << sTamp1.CameraStampBase << endl<< sTamp1.GPSStampBase << endl;
//    cout << sTamp2.CameraStampBase << endl<< sTamp2.GPSStampBase << endl;
//    sTamp2 = sTamp1;
//    cout << sTamp1.CameraStampBase << endl<< sTamp1.GPSStampBase << endl;
//    cout << sTamp2.CameraStampBase << endl<< sTamp2.GPSStampBase << endl;
//     return 0;
 }

// typedef enum memory_order {
//     memory_order_relaxed,    // 不对执行顺序做保证
//     memory_order_acquire,    // 本线程中,所有后续的读操作必须在本条原子操作完成后执行
//     memory_order_release,    // 本线程中,所有之前的写操作完成后才能执行本条原子操作
//     memory_order_acq_rel,    // 同时包含 memory_order_acquire 和 memory_order_release
//     memory_order_consume,    // 本线程中,所有后续的有关本原子类型的操作,必须在本条原子操作完成之后执行
//     memory_order_seq_cst    // 全部存取都按顺序执行
//     } memory_order;
