#include <iostream>
#include <fstream>
#include "xyzfour/model.pb.h"
#include <hiredis/hiredis.h>

/*
 *
 */
int main(void) {

    // 创建User对象
    hello::MyData u;//65
    //u.set_username("mylist");
    u.set_timestamp(1);
    u.set_x(100);
    u.set_y(100);
    u.set_z(100);
    u.set_qx(100);
    u.set_qy(100);
    u.set_qz(100);
    u.set_qw(100);



    // 将对象以二进制保存
    std::cout << "byteSize = " << 1 << std::endl;
    const size_t byteSize = u.ByteSizeLong();
    std::cout << "byteSize = " << byteSize << std::endl;
    char buf[byteSize];
    bzero(buf, byteSize);
    u.SerializeToArray(buf, byteSize);


    // 建立redis链接
    redisContext *c;
    redisReply *reply;

    struct timeval timeout = {1, 500000}; // 1.5 seconds
    c = redisConnectWithTimeout((char*) "127.0.0.1", 6379, timeout);
    if (c->err) {
        printf("Connection error: %s\n", c->errstr);
        exit(1);
    }

        //第一次执行:将对象写入redis数据库
        reply = (redisReply*) redisCommand(c, "LPUSH kd %b",  buf, byteSize); // 重点!!!
        printf("SET (binary API): %s\n", reply->str);
        freeReplyObject(reply);

    //    第二次执行:从redis数据库读取对象数据
        reply = (redisReply*) redisCommand(c, "LPOP kd");
        std::cout << "reply->len = " << reply->len << "\nreply->str : \n" << reply->str << std::endl; // 这里打印不完

        std::cout << "---------------------------" << std::endl;

        hello::MyData u2;
        u2.ParseFromArray(reply->str, reply->len);
        std::cout << u2.username() << std::endl;
        std::cout << u2.x() << std::endl;
        std::cout << u2.qx() << std::endl;
        std::cout << u2.timestamp() << std::endl;

    return 0;
}
