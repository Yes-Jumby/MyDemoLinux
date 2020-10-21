#include <iostream>
#include <fstream>
#include "imu/imu_result.pb.h"
#include <hiredis/hiredis.h>

/*
 *
 */
int main(void) {

    //
    protodata::imu_result imu_result_;//65
    imu_result_.set_r11(1);
    imu_result_.set_r12(1);
    imu_result_.set_r13(1);
    imu_result_.set_r21(1);
    imu_result_.set_r22(1);
    imu_result_.set_r23(1);
    imu_result_.set_r31(1);imu_result_.set_r32(1);imu_result_.set_r33(1);
    imu_result_.set_dx(1);imu_result_.set_dy(1);imu_result_.set_dz(1);
    imu_result_.set_odometer_count(100);imu_result_.set_time_stamp(1000);


    // 将对象以二进制保存
    std::cout << "byteSize = " << 1 << std::endl;
    const size_t byteSize = imu_result_.ByteSizeLong();
    std::cout << "byteSize = " << byteSize << std::endl;
    char buf[byteSize];
    bzero(buf, byteSize);


    // 建立redis链接
    redisContext *c;
    redisReply *reply;

    struct timeval timeout = {1, 500000}; // 1.5 seconds
    c = redisConnectWithTimeout((char*) "127.0.0.1", 6379, timeout);
    if (c->err) {
        printf("Connection error: %s\n", c->errstr);
        exit(1);
    }

    for (int i = 0 ;i < 5002;i++)
    {
        imu_result_.set_odometer_count(1);
        imu_result_.set_time_stamp(i+1);
        imu_result_.SerializeToArray(buf, byteSize);
        //第一次执行:将对象写入redis数据库
        reply = (redisReply*) redisCommand(c, "RPUSH imu %b",  buf, byteSize); // push in last
        //printf("SET (binary API): %s\n", reply->str);
    }

//    std::cout << "---------------------------" << std::endl;
//    protodata::imu_result u2;
//    for (int i = 0 ;i < 10;i++)
//    {
//        reply = (redisReply*) redisCommand(c, "LPOP imu"); // pop in first
//        //std::cout << "reply->len = " << reply->len << "\nreply->str : \n" << reply->str << std::endl;
//        u2.ParseFromArray(reply->str, reply->len);
//        std::cout << u2.time_stamp()<< std::endl;
//        //std::cout << u2.odometer_count()<< std::endl;
//    }



    freeReplyObject(reply);
    return 0;
}
