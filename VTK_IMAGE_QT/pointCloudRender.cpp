#include "pointCloudRender.h"




VTK_MODULE_INIT(vtkRenderingOpenGL2); //非cmake生成的工程需添加
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkInteractionStyle) ;


PointCloudRender::PointCloudRender()
{
}

void PointCloudRender::init(vtkSmartPointer<vtkRenderWindow> renderwind,QVTKWidget *pQVTKWidget)
{
    m_renderwind = renderwind;
    m_pQVTKWidget = pQVTKWidget;

    m_ImageData = vtkSmartPointer<vtkImageData>::New();

    m_imageinfo =	vtkSmartPointer<vtkInformation>::New();
    m_ImageData->SetDimensions(256, 256, 1);
    m_ImageData->SetScalarType(VTK_UNSIGNED_CHAR, m_imageinfo);
    m_ImageData->SetNumberOfScalarComponents(1, m_imageinfo);//每个像素需要表示的组份 =1是指标量图
    m_ImageData->AllocateScalars(m_imageinfo);//很重要




}

bool PointCloudRender::LoadImage(const unsigned char * pImage,const size_t iWidth,const size_t iHeight)
{
    showImage();
    return true;
}
void PointCloudRender::showImage()
{
    int size = 256;
    unsigned char *ptr = (unsigned char*)m_ImageData->GetScalarPointer();

    for (int i = 0; i < size * size; i++)
    {
        *ptr++ = i % size;
    }
    m_ImageViewer2->SetInputData(m_ImageData);
    m_ImageViewer2->UpdateDisplayExtent();
    m_ImageViewer2->SetRenderWindow(m_renderwind);
    m_ImageViewer2->SetRenderer(m_renderer);
    m_ImageViewer2->SetupInteractor(m_renderwind->GetInteractor());
    m_ImageViewer2->SetSliceOrientationToXY();
    m_ImageViewer2->GetImageActor()->InterpolateOff();
    m_renderer->ResetCamera();
    m_renderer->DrawOn();
    m_pQVTKWidget->SetRenderWindow(m_ImageViewer2->GetRenderWindow());
    m_renderwind->Render();



}
