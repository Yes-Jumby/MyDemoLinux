#include "pointCloudRender.h"




VTK_MODULE_INIT(vtkRenderingOpenGL2); //非cmake生成的工程需添加
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkInteractionStyle) ;


PointCloudRender::PointCloudRender() :m_low_z(FLT_MAX), m_high_z(FLT_MIN),m_Pbound(nullptr),m_ratio(5.0),isReady(true)
{
}
bool PointCloudRender::LoadPoints(const float * pts,const size_t iSize)
{
    if(isReady)
    {
        float *ptemp = new float[iSize*3];
        memcpy(ptemp,pts,sizeof(float)*iSize*3);
        m_points->Resize(0);
        if (iSize == 0)  return false;
        m_low_z = std::numeric_limits<float>::max();
        m_high_z = std::numeric_limits<float>::lowest();

        size_t idx;
        float x,y,z;
        for (size_t i = 0; i < iSize; i++) {
            idx = i*3;
            x = ptemp[idx];
            y = ptemp[idx+1];
            z = ptemp[idx+2];
            if(std::isnan(x)||std::isnan(y)||std::isnan(z)) {
                //std::cout << "nann :" << std::endl;
                continue;
            }

            if (z < m_low_z)
                m_low_z = z;
            else if (z > m_high_z)
                m_high_z = z;

            m_points->InsertNextPoint(x, y, z);
        }
        LOG(INFO) << "Points :" <<" isize:"<<iSize<<"   "<< m_low_z <<"  "<<m_high_z;
        showCloud();
        delete []ptemp;
    }
    return true;
}
bool PointCloudRender::LoadPoints(const std::vector<std::vector<float> >& pts)
{
	//m_points->Allocate(0);
	//m_points->Reset();
	//m_points = vtkSmartPointer<vtkPoints>::New();
    if(isReady)
    {
        isReady = false;
        m_points->Resize(0);
        if (pts.empty())  return false;
        m_low_z = std::numeric_limits<float>::max();
        m_high_z = std::numeric_limits<float>::lowest();
        float x,y,z;
        for (size_t i = 0; i < pts.size(); i++) {
            if (pts[i].size() != 3) return false;

            x = pts[i][0];
            y = pts[i][1];
            z = pts[i][2];
            if(std::isnan(x)||std::isnan(y)||std::isnan(z)) {
                //std::cout << "nann :" << std::endl;
                continue;
            }

            if (z < m_low_z)
                m_low_z = z;
            else if (z > m_high_z)
                m_high_z = z;

            m_points->InsertNextPoint(x, y, z);
        }
        LOG(INFO) << "Points :" << m_low_z <<"  "<<m_high_z;
        showCloud();
        isReady = true;
    }

	return true;
}
bool PointCloudRender::LoadCloud(const float * pts,const size_t iSize)
{
    if(isReady)
    {
        float *ptemp = new float[iSize*4];
        memcpy(ptemp,pts,sizeof(float)*iSize*4);
        m_points->Resize(0);
        if (iSize == 0)  return false;
        m_low_z = std::numeric_limits<float>::max();
        m_high_z = std::numeric_limits<float>::lowest();

        size_t idx;
        float x,y,z;
        for (size_t i = 0; i < iSize; i++) {
            idx = i*4;
            x = ptemp[idx];
            y = ptemp[idx+1];
            z = ptemp[idx+2];
            if(std::isnan(x)||std::isnan(y)||std::isnan(z)) {
                //std::cout << "nann :" << std::endl;
                continue;
            }

            if (z < m_low_z)
                m_low_z = z;
            else if (z > m_high_z)
                m_high_z = z;

            m_points->InsertNextPoint(x, y, z);
        }
        LOG(INFO) << "Points :" <<" isize:"<<iSize<<"   "<< m_low_z <<"  "<<m_high_z;
        showCloud();
        delete []ptemp;
    }
//    if(isReady)
//    {
//        m_points->Resize(0);
//        if (iSize == 0)  return false;
//        m_low_z = std::numeric_limits<float>::max();
//        m_high_z = std::numeric_limits<float>::lowest();
//        size_t idx;
//        float x,y,z;
//        for (size_t i = 0; i < iSize; i++) {
//            idx = i;
//            x = pts[4*idx];
//            y = pts[4*idx+1];
//            z = pts[4*idx+2];
//            if(std::isnan(x)||std::isnan(y)||std::isnan(z)) {
//                //std::cout << "nann :" << std::endl;
//                continue;
//            }

//            if (z < m_low_z)
//                m_low_z = z;
//            else if (z > m_high_z)
//                m_high_z = z;

//            m_points->InsertNextPoint(x, y, z);
//        }
//        LOG(INFO) << "Points :" <<" isize:"<<iSize<<"   "<< m_low_z <<"  "<<m_high_z;
//        show();
//    }
    return true;
}
void PointCloudRender::init(vtkSmartPointer<vtkRenderWindow> renderwind,QVTKWidget *pQVTKWidget)
{
    m_renderwind = renderwind;
    m_pQVTKWidget = pQVTKWidget;

    m_points = vtkSmartPointer<vtkPoints>::New();
    m_polydata = vtkSmartPointer<vtkPolyData>::New();

    m_ImageData = vtkSmartPointer<vtkImageData>::New();

    m_imageinfo =	vtkSmartPointer<vtkInformation>::New();
    m_ImageData->SetDimensions(256, 256, 1);
    m_ImageData->SetScalarType(VTK_UNSIGNED_CHAR, m_imageinfo);
    m_ImageData->SetNumberOfScalarComponents(1, m_imageinfo);//每个像素需要表示的组份 =1是指标量图
    m_ImageData->AllocateScalars(m_imageinfo);//很重要

    m_glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();

    m_elevationFilter = vtkSmartPointer<vtkElevationFilter>::New();

    m_dataMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    m_dataMapper->SetInputConnection(m_elevationFilter->GetOutputPort());

    m_actor = vtkSmartPointer<vtkActor>::New();
    m_actor->GetProperty()->SetPointSize(2);
    m_actor->SetMapper(m_dataMapper);

    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_renderer->AddActor(m_actor);
    m_renderer->SetBackground(1, 1, 1);

    m_textActor = vtkSmartPointer<vtkTextActor>::New();
    m_textActor->SetInput("");
    m_tprop = m_textActor->GetTextProperty();
    m_tprop->SetFontFamilyToArial();
    m_tprop->SetFontSize(16);
    m_tprop->BoldOn();
    m_tprop->SetColor(0, 1, 0);
    m_textActor->SetDisplayPosition(30, 30);
    m_renderer->AddActor2D(m_textActor);


}
void PointCloudRender::showCloud()
{
    LOG(INFO) << "Points :" << m_points->GetNumberOfPoints();

    m_polydata->SetGlobalWarningDisplay(0); // close vtkOutoutWindow
    m_polydata->SetPoints(m_points);

    m_glyphFilter->SetInputData(m_polydata);
    m_glyphFilter->Update();

    m_elevationFilter->SetInputConnection(m_glyphFilter->GetOutputPort());


    m_dataMapper->SetInputConnection(m_elevationFilter->GetOutputPort());

    m_actor->SetMapper(m_dataMapper);


    m_renderer->AddActor(m_actor);


    m_renderer->AutomaticLightCreationOn();
    m_renderer->ResetCamera();
    m_renderer->GetActiveCamera()->Zoom(1.5);
    m_renderwind->AddRenderer(m_renderer);
    m_renderwind->Render();

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
