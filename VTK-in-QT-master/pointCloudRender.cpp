#include "pointCloudRender.h"




VTK_MODULE_INIT(vtkRenderingOpenGL2); //非cmake生成的工程需添加
VTK_MODULE_INIT(vtkRenderingFreeType);


class PointPickerInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
    PointPickerInteractorStyle(){};
    ~PointPickerInteractorStyle(){};

    static PointPickerInteractorStyle* New();

    virtual void OnLeftButtonDown()
    {
        vtkInteractorStyleTrackballCamera::OnLeftButtonDown();

        int *clickPos = this->GetInteractor()->GetEventPosition();
        vtkSmartPointer<vtkPointPicker> pointPicker = vtkSmartPointer<vtkPointPicker>::New();

        pointPicker->Pick(clickPos[0], clickPos[1], 0, this->GetCurrentRenderer());
        double *pickCoordinate = pointPicker->GetPickPosition();
        std::string str = "X: " + std::to_string(pickCoordinate[0]) + " Y: " + std::to_string(pickCoordinate[1]) + " Z: " + std::to_string(pickCoordinate[2]);
        //std::cout << str << std::endl;

        textActor->SetInput(str.c_str());

    }
    void unitizeTextActor(vtkSmartPointer<vtkTextActor> textActor)
    {
        this->textActor = textActor;
        //this->renderer = renderer;
    }
private:
    vtkSmartPointer<vtkTextActor> textActor;
    //vtkRenderer* renderer;
};
vtkStandardNewMacro(PointPickerInteractorStyle);

PointCloudRender::PointCloudRender() :m_low_z(FLT_MAX), m_high_z(FLT_MIN),m_Pbound(nullptr),m_ratio(5.0)
{
}
bool PointCloudRender::LoadPoints(const float * pts,const size_t iSize)
{
    float *ptemp = new float[iSize*3];
    memcpy(ptemp,pts,sizeof(float)*iSize*3);
    m_points->Resize(0);
    if (iSize < 0)  return false;
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
    std::cout << "Points :" <<" isize:"<<iSize<<"   "<< m_low_z <<"  "<<m_high_z<< std::endl;
    delete []ptemp;

    return true;
}
bool PointCloudRender::LoadPoints(const std::vector<std::vector<float> >& pts)
{
	//m_points->Allocate(0);
	//m_points->Reset();
	//m_points = vtkSmartPointer<vtkPoints>::New();
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
    std::cout << "Points :" << m_low_z <<"  "<<m_high_z<< std::endl;

	return true;
}
void PointCloudRender::init(vtkSmartPointer<vtkRenderWindow> renderwind)
{
    m_renderwind = renderwind;

    m_points = vtkSmartPointer<vtkPoints>::New();
    m_polydata = vtkSmartPointer<vtkPolyData>::New();

    m_glyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();

    m_elevationFilter = vtkSmartPointer<vtkElevationFilter>::New();

    m_dataMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    m_dataMapper->SetInputConnection(m_elevationFilter->GetOutputPort());

    m_actor = vtkSmartPointer<vtkActor>::New();
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

    //添加坐标轴

    m_axesActor = vtkSmartPointer<vtkAxesActor>::New();
    m_axesActor->SetXAxisLabelText("");
    m_axesActor->SetYAxisLabelText("");
    m_axesActor->SetZAxisLabelText("");
    m_axesActor->SetTotalLength(2, 2, 2);
    m_axesActor->SetCylinderRadius(0.500 * m_axesActor->GetCylinderRadius());
    m_axesActor->SetConeRadius(0.25 * m_axesActor->GetConeRadius());
    m_axesActor->SetSphereRadius(1.500 * m_axesActor->GetSphereRadius());
//    vtkTextProperty* Xprop = axesActor->GetXAxisCaptionActor2D()->GetCaptionTextProperty();
//    Xprop->ItalicOn();
//    Xprop->ShadowOff();
//    Xprop->SetFontFamilyToTimes();
//    Xprop->SetFontSize(20);
    m_renderer->AddActor(m_axesActor);

    // add color bar
    m_scalarBar = vtkSmartPointer<vtkScalarBarActor>::New();
    m_hueLut = vtkSmartPointer<vtkLookupTable>::New();
    m_hueLut->SetHueRange(0, 1);
    m_hueLut->SetSaturationRange(1, 1);
    m_hueLut->SetValueRange(1, 1);

    m_scalarBar->SetLookupTable(m_hueLut);
    m_scalarBar->SetWidth(0.05);
    m_scalarBar->SetNumberOfLabels(7);
    m_scalarBar->SetTitleRatio(2);
    m_scalarBar->SetTextPositionToSucceedScalarBar();
    m_renderer->AddActor2D(m_scalarBar);

//    vtkSmartPointer<PointPickerInteractorStyle> m_style;
//    m_style = vtkSmartPointer<PointPickerInteractorStyle>::New();
//    m_style->unitizeTextActor(m_textActor);

//    m_renderwindIt = vtkSmartPointer<vtkRenderWindowInteractor>::New();

//    m_renderwindIt->SetInteractorStyle(m_style);
//    m_renderwindIt->SetRenderWindow(m_renderwind);
//    m_renderwind->SetInteractor(m_renderwindIt);
//    m_renderwindIt->Initialize();
//    m_renderwindIt->Start();

}
void PointCloudRender::show()
{
	std::cout << "Points :" << m_points->GetNumberOfPoints() << std::endl;

    m_polydata->SetGlobalWarningDisplay(0); // close vtkOutoutWindow
    m_polydata->SetPoints(m_points);

    m_glyphFilter->SetInputData(m_polydata);
    m_glyphFilter->Update();

    m_elevationFilter->SetInputConnection(m_glyphFilter->GetOutputPort());
    m_axesActor->SetTotalLength((m_high_z-m_low_z)/m_ratio, (m_high_z-m_low_z)/m_ratio, (m_high_z-m_low_z)/m_ratio);
//    m_elevationFilter->SetLowPoint(0, 0, m_low_z);
//    m_elevationFilter->SetHighPoint(0, 0, m_high_z);
//    m_Pbound = m_elevationFilter->GetOutput()->GetBounds();
//    std::cout << "show :" << m_Pbound[4] <<"  "<<m_Pbound[5]<< std::endl;
//    if((m_Pbound[1]-m_Pbound[0])>0 && m_Pbound[3]-m_Pbound[2]>0 && m_Pbound[5]-m_Pbound[4]>0){
//        m_axesActor->SetTotalLength((m_Pbound[1]-m_Pbound[0])/m_ratio, (m_Pbound[3]-m_Pbound[2])/m_ratio, (m_high_z-m_low_z)/m_ratio);
//    } else {
//        m_axesActor->SetTotalLength(1, 1, 1);
//    }

    m_dataMapper->SetInputConnection(m_elevationFilter->GetOutputPort());

    m_actor->SetMapper(m_dataMapper);
    m_actor->GetProperty()->SetPointSize(2);

    m_renderer->AddActor(m_actor);


	// add color bar
    m_hueLut->SetTableRange(m_low_z, m_high_z);
    m_hueLut->Build();
    m_scalarBar->SetLookupTable(m_hueLut);
    m_renderer->AddActor2D(m_scalarBar);
    m_renderer->AutomaticLightCreationOn();
//    m_renderer->ResetCamera();
//    m_renderer->GetActiveCamera()->Zoom(1.5);
    ViewPositiveY(m_renderer);
    m_renderwind->AddRenderer(m_renderer);
    m_renderwind->Render();
}

void PointCloudRender::ViewDirection(vtkRenderer *renderer,
                   double lookX, double lookY, double lookZ,
                   double upX, double upY, double upZ)
{
    renderer->GetActiveCamera()->SetPosition(0, 0, 0);    //相机位置
    renderer->GetActiveCamera()->SetFocalPoint(lookX, lookY, lookZ);    //焦点位置
    renderer->GetActiveCamera()->SetViewUp(upX, upY, upZ);    //朝上方向
    renderer->ResetCamera();
}

void PointCloudRender::ViewPositiveX(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, 1, 0, 0, 0, 0, 1);
}

void PointCloudRender::ViewNegativeX(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, -1, 0, 0, 0, 0, 1);
}

void PointCloudRender::ViewPositiveY(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, 0, 1, 0, 0, 0, 1);
}

void PointCloudRender::ViewNegativeY(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, 0, -1, 0, 0, 0, 1);
}

void PointCloudRender::ViewPositiveZ(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, 0, 0, 1, 0, 1, 0);
}
void PointCloudRender::ViewNegativeZ(vtkRenderer *renderer)
{
    PointCloudRender::ViewDirection(renderer, 0, 0, -1, 0, 1, 0);
}
