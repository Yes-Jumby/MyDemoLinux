#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "cloud.h"

class CReadAndWriteDat{
public:
    CReadAndWriteDat(void){}
    ~CReadAndWriteDat(void){}
    //new version
    bool readbinToCloud(const std::string &path);
    void writebin(const std::string & path,const Cloud3D &cloud,void *pbuffer3D,void *pbuffer2D);
    bool readbinToLAS(const std::string &path);
    void writeLAS(const std::string & path,const Cloud3D &cloud,void *pbuffer3D,void *pbuffer2D);

    //old version
    bool transformToCloudWin(const std::string & inpath);
    bool transformToCloudLinux(const std::string & inpath);
};
