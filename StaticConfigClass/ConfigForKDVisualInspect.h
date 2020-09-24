#ifndef CONFIGFORKDVISUALINSPECT_H
#define CONFIGFORKDVISUALINSPECT_H

#include <memory>
#include <iostream>
#include <opencv2/core/core.hpp>
using namespace std;

class CConfigForKDVisualInspect
{
private:
    static std::shared_ptr<CConfigForKDVisualInspect> config_;
    cv::FileStorage file_read_;


    CConfigForKDVisualInspect () {}
public:
    ~CConfigForKDVisualInspect();
    
    // set a new config file 
    static void setParameterFile( const std::string& filename ); 
    
    // access the parameter values
    template< typename T >
    static T get( const std::string& key )
    {
        return T( CConfigForKDVisualInspect::config_->file_read_[key] );
    }
};


#endif // CONFIG_H
