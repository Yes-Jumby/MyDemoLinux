#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <QDebug>
 #include <atomic>
std::atomic<int> a_atomic{ 0 };
#define THREADMAX 20

pthread_t thread[THREADMAX]; //ŽŽœšÏß³Ìº¯Êý·µ»ØÀàÐÍ
pthread_mutex_t mut; //»¥³âËøÀàÐÍ
static int number=0;

void *thread1(void* a) //Ïß³Ìº¯Êý
{
//    pthread_mutex_lock(&mut); //ŒÓËø£¬ÓÃÓÚ¶Ô¹²Ïí±äÁ¿²Ù×÷
//    lua_State *L = luaL_newstate();
//    luaL_openlibs(L);
//    if(luaL_loadfile(L, "*****.lua") || lua_pcall(L, 0,0,0)){
//        printf("error %s\n", lua_tostring(L,-1));
//    }
//    number++;
//    lua_getglobal(L,"****");
//    lua_pushnumber(L, number);
//    lua_pcall(L,1,0,0);
//    lua_pop(L, 1);
//    lua_close(L);
//    pthread_mutex_unlock(&mut); //œâËø
    for(int i=0;i<10;i++)
    {
        //pthread_mutex_lock(&mut);
        number++;
        //qDebug()<<number;
        a_atomic.store(a_atomic+1);
        qDebug()<<number<<" "<<a_atomic;
        //pthread_mutex_unlock(&mut);
    }

}


void thread_create(void)
{
    /*ŽŽœšÏß³Ì*/
    int i=0;
    for (i=0;i<THREADMAX;i++){
        pthread_create(&thread[i], NULL, thread1, NULL);
    }
}

void thread_wait(void)
{
    int i=0;
    for (i=0;i<THREADMAX ;i++){
        pthread_join(thread[i],NULL);
    }
}

int main2()
{
    /*ÓÃÄ¬ÈÏÊôÐÔ³õÊŒ»¯»¥³âËø*/
    pthread_mutex_init(&mut,NULL);
    thread_create();
    thread_wait();
    return 0;
}
