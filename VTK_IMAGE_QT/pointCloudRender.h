#ifndef _POINTCLOUDRENDER_H
#define _POINTCLOUDRENDER_H
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkScalarBarActor.h>
#include <vtkLookupTable.h>
#include <vtkDebugLeaks.h>
#include <vtkPolyData.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkAutoInit.h>
#include <vtkPointPicker.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkTextActor.h>
#include <vtkObjectFactory.h>
#include <vtkLabeledDataMapper.h>
#include <vtkAxesActor.h>
#include <vtkCaptionActor2D.h>
#include <vtkCamera.h>
#include <vtkProperty.h>

#include <vtkImageData.h>
#include <vtkInformation.h>
#include <vtkImageViewer2.h>
#include <vtkImageActor.h>
#include <QVTKWidget.h>
#include "glog/logging.h"
class PointCloudRender
{
public:
    PointCloudRender();
    ~PointCloudRender() = default;
    void init(vtkSmartPointer<vtkRenderWindow> renderwind,QVTKWidget *pQVTKWidget);
    bool LoadImage(const unsigned char * pImage,const size_t iWidth,const size_t iHeight);

private:
    QVTKWidget *m_pQVTKWidget;
    vtkSmartPointer<vtkRenderWindow> m_renderwind;
    vtkSmartPointer<vtkRenderer> m_renderer;
    //2d image
    vtkSmartPointer<vtkImageData> m_ImageData;
    vtkSmartPointer<vtkInformation> m_imageinfo;
    vtkSmartPointer<vtkImageViewer2> m_ImageViewer2;
    void showImage();
};



#endif
