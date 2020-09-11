#include "Two.h"

Two::Two()
{
    //google::InitGoogleLogging("One");//can only be called once
    LOG(INFO)<<"Two constructed INFO";
    LOG(WARNING)<<"Two constructed WARNING";
    LOG(ERROR)<<"Two constructed ERROR";
    //LOG(FATAL)<<"Two constructed FATAL";//will abort
}
