/***************************************************************************
 *
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file redistest.cpp
 * @author liujun05(com@baidu.com)
 * @date 2014/02/25 10:28:44
 * @brief
 *
 **/

#include<unistd.h>
#include <stdio.h>
#include <hiredis.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


#ifndef uint32
#define uint32 unsigned int
#endif

#define MAX_REDIS_SERVER_CNT 10
#define MAX_REDIS_IPS 1024

typedef struct _redis_conf_t
{
    uint32 redis_num;
    char redis_ips[MAX_REDIS_IPS];
    char redis_ip_array[MAX_REDIS_SERVER_CNT][MAX_REDIS_IPS];
    uint32 redis_port;

} redis_conf;

typedef struct _redis_data_t
{
    uint32 redis_num;
    redisContext *rc[MAX_REDIS_SERVER_CNT];
}redis_data;

redis_conf g_cfg;
redis_data g_data;

void show_usage()
{
    printf("usage: ./redis -n [num] -h [host] -p [port]\n");
}

/** 解析参数 */
int main_parse_option(int argc, char **argv)
{
    int c;
    //reset 获取参数的位置，多次调用时这个会出现问题
    while ((c = getopt(argc, argv, "h:p:n:")) != -1)
    {
        switch (c)
        {
        case 'h':
            sprintf(g_cfg.redis_ips, optarg);
            break;
        case 'p':
            g_cfg.redis_port = atoi(optarg);
            break;
        case 'n':
            g_cfg.redis_num = atoi(optarg);
            break;
        default:
            show_usage();
            fflush(stdout);
            return -1;
        }
    }
    return 0;
}

void* test_thread1(void* data)
{
    redis_data* redis_ins = (redis_data*)data;
    redisReply *reply;
    for(int i=0; i<redis_ins->redis_num; i++)
    {
        reply = (redisReply *)redisCommand( redis_ins->rc[i] ,"SET %s %s", "foo", "hello world");
        freeReplyObject(reply);
    }
}

int init_data()
{
    g_data.redis_num = 0;
    struct timeval timeout = { 1, 500000 }; // 1.5 seconds

    char *ptok = NULL;
    char *part = strtok_r(g_cfg.redis_ips, "-", &ptok);
    int num = 0;
    while(part)
    {
        strcpy(g_cfg.redis_ip_array[num++], part);
        part = strtok_r(NULL, "-", &ptok);
    }

    if(num != g_cfg.redis_num || num > MAX_REDIS_SERVER_CNT)
    {
        printf("ip num[%d] not equal redis_num[%d] or not vaild\n", num, g_cfg.redis_num);
    }

    g_data.redis_num = (num > MAX_REDIS_SERVER_CNT ) ? MAX_REDIS_SERVER_CNT : num;
    int i= 0;

    for(i=0; i<g_data.redis_num; i++)
    {
        g_data.rc[i] = redisConnectWithTimeout( g_cfg.redis_ip_array[i], g_cfg.redis_port , timeout);
        if( g_data.rc[i] == NULL || g_data.rc[i]->err)
        {
            printf("content to redis server[%s:%u], error[%s]\n",
                    g_cfg.redis_ip_array[i], g_cfg.redis_port, g_data.rc[i]->errstr
            );
            goto exit;
        }
    }
    return 0;

exit:
   for(int j=0; j<i; j++)
   {
        if(g_data.rc[j] != NULL)
        {
            redisFree(g_data.rc[j]);
        }
   }
   return -1;
}


int destory_data()
{
   for(int j=0; j<g_data.redis_num; j++)
   {
        if(g_data.rc[j] != NULL)
        {
            redisFree(g_data.rc[j]);
        }
   }
}

int main111111111111111(int argc, char** argv)
{
    g_cfg.redis_ips[0] = '\0';
    g_cfg.redis_port = 6379;
    g_cfg.redis_num = 0;
    if( 0 != main_parse_option(argc, argv) )
    {
        show_usage();
        return -1;
    }

    if(  0 == g_cfg.redis_num || g_cfg.redis_num >  MAX_REDIS_SERVER_CNT )
    {
        printf("the reids num[%u] is not vaild\n", g_cfg.redis_num);
        show_usage();
        return 0;
    }

    int ret = init_data();
    if( ret != 0)
    {
        printf("init num fail\n");
        return -1;
    }


    pthread_t t[100];
    for(int i=0; i<100; i++)
    {
        pthread_create(&t[i], NULL, test_thread1, &g_data);
    }

    for(int i=0; i<100; i++)
    {
        pthread_join(t[i], NULL);
    }

    destory_data();
    return 0;
}



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
