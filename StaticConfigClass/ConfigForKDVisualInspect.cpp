#include "ConfigForKDVisualInspect.h"
void CConfigForKDVisualInspect::setParameterFile( const std::string& filename )
{
    if ( config_ == nullptr )
        config_ = std::shared_ptr<CConfigForKDVisualInspect>(new CConfigForKDVisualInspect);
    config_->file_read_.open(filename.c_str(), cv::FileStorage::READ);
    if ( config_->file_read_.isOpened() == false )
    {
        std::cerr<<"parameter file "<<filename<<" does not exist."<<std::endl;
        config_->file_read_.release();
        return;
    }
}

CConfigForKDVisualInspect::~CConfigForKDVisualInspect()
{
    if ( file_read_.isOpened() )
        file_read_.release();
}

std::shared_ptr<CConfigForKDVisualInspect> CConfigForKDVisualInspect::config_ = nullptr;


