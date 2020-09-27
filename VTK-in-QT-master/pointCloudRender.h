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
class PointCloudRender
{
public:
    PointCloudRender();
    ~PointCloudRender() = default;
    /*载入点集，坐标存储顺序为x,y,z*/
    bool LoadPoints(const std::vector<std::vector<float> >& pts);
    /*载入点集，坐标存储顺序为x,y,z,size of point*/
    bool LoadPoints(const float * pts,const size_t iSize);
    /*显示点云*/
    void show();
    void init(vtkSmartPointer<vtkRenderWindow> renderwind);





private:

    vtkSmartPointer<vtkPoints> m_points;
    float m_low_x; // minimal z-value
    float m_high_x; // maximal z-value
    float m_low_y; // minimal z-value
    float m_high_y; // maximal z-value
    float m_low_z; // minimal z-value
    float m_high_z; // maximal z-value
    vtkSmartPointer<vtkRenderWindow> m_renderwind;

    vtkSmartPointer<vtkPolyData> m_polydata;


    vtkSmartPointer<vtkVertexGlyphFilter> m_glyphFilter;

    vtkSmartPointer<vtkElevationFilter> m_elevationFilter;

    vtkSmartPointer<vtkPolyDataMapper> m_dataMapper;

    vtkSmartPointer<vtkActor> m_actor;

    vtkSmartPointer<vtkProperty> m_vtkProperty;
    vtkSmartPointer<vtkRenderer> m_renderer;

    vtkSmartPointer<vtkTextActor> m_textActor;
    vtkSmartPointer<vtkTextProperty> m_tprop;

    //添加坐标轴
    vtkSmartPointer<vtkAxesActor> m_axesActor;
//    vtkTextProperty* Xprop;

    // add color bar
    vtkSmartPointer<vtkScalarBarActor> m_scalarBar;
    vtkSmartPointer<vtkLookupTable> m_hueLut;



    vtkSmartPointer<vtkRenderWindowInteractor> m_renderwindIt;
    double *m_Pbound;
    double m_ratio;
    void ViewPositiveX(vtkRenderer *renderer);

    void ViewNegativeX(vtkRenderer *renderer);
    void ViewPositiveY(vtkRenderer *renderer);

    void ViewNegativeY(vtkRenderer *renderer);

    void ViewPositiveZ(vtkRenderer *renderer);
    void ViewNegativeZ(vtkRenderer *renderer);
    void ViewDirection(vtkRenderer *renderer,
                       double lookX, double lookY, double lookZ,
                       double upX, double upY, double upZ);
};



#endif
