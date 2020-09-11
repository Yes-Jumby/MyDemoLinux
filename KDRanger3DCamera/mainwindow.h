#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "GrabberForCamera.h"
#include "Ranger3buffertohtml.h"
#include "readAndWriteDat.h"
#include <QMainWindow>
#include <QMutex>
#include <QTimer>
#include <queue>
#include <unistd.h>
struct s_myParam
{
    s_myParam()
    {
        width =0;
        height =0;
        p2DBuffer= nullptr;
        p3DBuffer= nullptr;
        iFrameCount=0;
    }
    unsigned char * p2DBuffer;
    float * p3DBuffer;
    size_t width;
    size_t height;
    size_t iFrameCount;
    Cloud3D cloud;              //parameters from which we can translate intensity and height image to cloud
    std::string  strDataSavePath;//path to save image
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalRefresh(const std::string &path);
private slots:
    void on_pushButton_init_clicked();

    void on_pushButton_startgrab_clicked();

    void on_pushButton_stopgrab_clicked();

    void on_pushButton_snap_clicked();

    void on_pushButton_close_clicked();

    void on_loadFinished(bool ok);


    void on_pushButton_test_clicked();
    void on_signalRefresh(const std::string &path);

private:
    std::shared_ptr<CGrabberForCamera> m_pGrabberForCamera ;
    std::shared_ptr<CRanger3buffertohtml> m_pRanger3buffertohtml;

    void ImgCallBack(const s_GrabberCallBackParam* pInfo);
    void ImgSave(const s_GrabberCallBackParam* pInfo);
    void ImgSaveBin(const s_GrabberCallBackParam* pInfo);
    void Imghtml(const std::string &path);
    Ui::MainWindow *ui;
    bool m_bReadytoDisplay;
    QMutex m_QMutex;
    QTimer* m_pTimer;
    CReadAndWriteDat ReadAndWriteDat;
    void *m_p2D;
    void *m_p3D;

    std::queue<s_GrabberCallBackParam*>qInitQueue;
    std::queue<s_GrabberCallBackParam*>qSaveQueue;
    std::queue<std::string>qDisplayQueue;
    bool m_bIsRunning;
    void ThreadWork_save();
    void ThreadWork_show();
    int m_iMemorySize;
};

#endif // MAINWINDOW_H
