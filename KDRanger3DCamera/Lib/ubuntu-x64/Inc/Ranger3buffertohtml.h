#pragma once
#include <memory>
#include <string>
#include <mutex>
#include "cloud.h"

namespace Potree{
    class PotreeConverter;
};
struct PotreeArguments;
class CRanger3buffertohtml{
public:
    //conversionQuality:0 for fast,1 for default,2 for nice;desttype:0 for bin,1 for las,2 for laz
    CRanger3buffertohtml(int conversionQuality = 1,int desttype = 0);
    ~CRanger3buffertohtml(void);
    //Return true if camera inits successful
    bool converterFilestoPotree(const std::string &sourceFile,const std::string &outdir,const std::string &pageName,const std::string &pageTemplatePath);
    //Return true if camera close successful
    bool converterBuffertoPotree(const Cloud3D &cloud,void *pbuffer3D,void *pbuffer2D,const std::string &outdir,const std::string &pageName,const std::string &pageTemplatePath);
private:
    std::shared_ptr<Potree::PotreeConverter> m_pPotreeConverter ;
    std::shared_ptr<PotreeArguments> m_pPotreeArguments ;
    std::mutex m_Mutex;
};
