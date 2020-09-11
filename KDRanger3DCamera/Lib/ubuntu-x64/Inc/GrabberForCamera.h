
#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include <mutex>
#include "cloud.h"
struct s_DataBuffer{
    s_DataBuffer(){
        iImageRows = 0;
        iImageCols = 0;
        pBuffer = nullptr;
    }
    const s_DataBuffer& operator=(const s_DataBuffer& DataBuffer)
    {
        iImageRows = DataBuffer.iImageRows;
        iImageCols = DataBuffer.iImageCols;
    }
    size_t  iImageRows;         //rows of image
    size_t  iImageCols;         //cols of image
    void *pBuffer;
};
struct s_GrabberCallBackParam{
    s_GrabberCallBackParam(){
        iFrameCount = 0;
         e_ImageType = 0;
         strDataSavePath = "";
    }
    const s_GrabberCallBackParam& operator=(const s_GrabberCallBackParam& GrabberCallBackParam)
    {
        iFrameCount = GrabberCallBackParam.iFrameCount;
        e_ImageType = GrabberCallBackParam.e_ImageType;
        sBuffer2D = GrabberCallBackParam.sBuffer2D;
        sBuffer3D = GrabberCallBackParam.sBuffer3D;
        cloud = GrabberCallBackParam.cloud;
        strDataSavePath = GrabberCallBackParam.strDataSavePath;
    }
    uint64_t  iFrameCount;      //image number
    int   e_ImageType;          //image type
    s_DataBuffer sBuffer2D;     //2D image info(intensity)
    s_DataBuffer sBuffer3D;     //3d image info(height)
    Cloud3D cloud;              //parameters from which we can translate intensity and height image to cloud
    std::string  strDataSavePath;//path to save image
};
struct s_GrabberInitParam{
    s_GrabberInitParam(){
        isShowLOGInCMD = false;
        isWriteLOG = false;
        isUsingIP = false;
        iBufferCount = 0;
        iImageWidth = 0;
        iImageHeight = 0;
        iImageHeight3D = 0;
        e_ImageType = 0;
        strLogFilesPath = "";
        strCTIFilesPath = "";
        strCSVFilesPath = "";
        strCalibXMLPath = "";
        strDataSavePath = "";
        fScaleY = 0.02;
        iTimeOut = 4000;
    }
    std::string  strLogFilesPath;//path to save log files
    std::string  strCTIFilesPath;//path of CTI files
    bool         isShowLOGInCMD; //set it true if show log in terminal
    bool         isWriteLOG;     //set it true if save log to disk

    std::string  strDeviceIPorMAC;//IP or MAC of camera
    bool         isUsingIP;       // set it true if using ip to connect the camera
    std::string  strCSVFilesPath; //path of CSV files
    std::string  strCalibXMLPath; //path of calibration files

    std::string  strDataSavePath; //path to save data got by callback function
    size_t       iBufferCount;    //Set the number of image buffers in the server thread
    int           e_ImageType;    //image type:2 - raw images;5 - calibarated intensity and height image
    int          iImageWidth;     //image width
    int          iImageHeight;    //image height for intensity image(min:4 max:256 increment:4)
    int          iImageHeight3D;  //image height for height image(min:1 max:4096)
    double fScaleY;               //resolution of Axis Y
    unsigned long iTimeOut;       //time out
    //pointer of callback function
    std::function<void(const s_GrabberCallBackParam*)> pCallBackFunc;
};
namespace SickCam{
    class Ranger3Shared;
};
class ImageGrabber;
class CGrabberForCamera{
public:
    CGrabberForCamera(void);
    ~CGrabberForCamera(void);
    //Return true if camera inits successful
    bool Init(const s_GrabberInitParam &pInitParam);
    //Return true if camera close successful
    bool Close();
    //Start Grabbing in continous mode
    bool StartGrab();
    //Stop Grabbing in continous mode
    bool StopGrab();
    //Start to get imageCount images ,this will stop voluntarily.
    bool SnapShot(int imageCount = 1);
    //Return true if set camera parameter success
    bool SetParameter(const std::string & paramName, const std::string & paramValue);
    //Return empty string when error happened
    std::string GetParameter(const std::string & paramName);

private:
    std::shared_ptr<SickCam::Ranger3Shared> m_pR3S ;
    std::unique_ptr<ImageGrabber> m_pIG;
    std::function<void(const s_GrabberCallBackParam*)> m_pCallBackFunc;
    s_GrabberCallBackParam m_sGrabInfo;
    int           m_eImageType;
    std::string m_strImageWidth ;
    std::string m_strImageHeight;
    std::string m_strImageHeight3D;
    std::string m_strDataSavePath;
    void run();
    bool m_bThreadRunning;
    std::mutex m_MutexSlaveThread;
};
