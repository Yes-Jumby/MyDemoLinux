#include "glog/logging.h"
#include "One.h"
#include "Two.h"
void initGlog()
{
    google::InitGoogleLogging("main");
    //google::SetLogFilenameExtension("glog_");
    FLAGS_stop_logging_if_full_disk = true;//stop log if disk is full
    FLAGS_colorlogtostderr = true;
    google::SetLogDestination(google::INFO, "../gLogTest/INFO/INFO_");
    google::SetLogDestination(google::WARNING, "../gLogTest/WARNING/WARNING_");
    google::SetLogDestination(google::ERROR, "../gLogTest/ERROR/ERROR_");
    //google::SetLogDestination(google::FATAL, "../gLogTest/FATAL/FATAL_");
    FLAGS_stderrthreshold = google::INFO;//default is error
}
void closeGlog()
{
    google::ShutdownGoogleLogging();
}
int main()
{
    initGlog();
    One one;
    Two two;

    closeGlog();


    return 0;
}
