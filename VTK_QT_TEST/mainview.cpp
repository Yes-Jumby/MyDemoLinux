#include "mainview.h"

#define vtkRenderingCore_AUTOINIT 2(vtkRenderingOpenGL2, vtkInteractionStyle)
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
#include <vtkCylinderSource.h>
#include "ui_mainview.h"
#include <QtGlobal>
MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // This creates a polygonal cylinder model with eight circumferential facets
    // (i.e, in practice an octagonal prism).
    vtkSmartPointer<vtkCylinderSource> cylinder =
      vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetResolution(8);

    // The mapper is responsible for pushing the geometry into the graphics library.
    // It may also do color mapping, if scalars or other attributes are defined.
    vtkSmartPointer<vtkPolyDataMapper> cylinderMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    // The actor is a grouping mechanism: besides the geometry (mapper), it
    // also has a property, transformation matrix, and/or texture map.
    // Here we set its color and rotate it around the X and Y axes.
    vtkSmartPointer<vtkActor> cylinderActor =
      vtkSmartPointer<vtkActor>::New();
    cylinderActor->SetMapper(cylinderMapper);
    cylinderActor->GetProperty()->SetColor(1.0000, 0.3882, 0.2784);
    cylinderActor->RotateX(30.0);
    cylinderActor->RotateY(-45.0);

    // The renderer generates the image
    // which is then displayed on the render window.
    // It can be thought of as a scene to which the actor is added
    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cylinderActor);
    renderer->SetBackground(0.1, 0.2, 0.4);
    // Zoom in a little by accessing the camera and invoking its "Zoom" method.
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(1.5);

    // The render window is the actual GUI window
    // that appears on the computer screen
    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->SetSize(200, 200);
    
    // These lines are important:
    // The actual render windows comes from the QVTK widget
    // The Renderer object should be passed to the QVTK widget (actors to be add for example)
    renderWindow = ui->qvtkWidget->GetRenderWindow();
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);


//    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
//        vtkSmartPointer<vtkAppendPolyData> appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
//        double p,j,k;
//        for(int i =0 ;i<10;i++)
//        {
//            p =i;j=i;k=0;
//            vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();
//            cubeSource->SetXLength(0.008);
//            cubeSource->SetYLength(0.008);
//            cubeSource->SetZLength(0.008);
//            cubeSource->SetCenter(p + 0.004, j + 0.004, k + 0.004);
//            cubeSource->Update();

//            appendFilter->AddInputData(cubeSource->GetOutput());
//        }

//        appendFilter->Update();
//        // Remove any duplicate points.
//        vtkSmartPointer<vtkCleanPolyData> cleanFilter = vtkSmartPointer<vtkCleanPolyData>::New();
//        cleanFilter->SetInputConnection(appendFilter->GetOutputPort());
//        cleanFilter->Update();
//        //Create a mapper and actor
//        vtkSmartPointer<vtkPolyDataMapper> appendmapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//        appendmapper->SetInputConnection(cleanFilter->GetOutputPort());
//        vtkSmartPointer<vtkActor> appendactor = vtkSmartPointer<vtkActor>::New();
//        appendactor->SetMapper(appendmapper);
//        appendactor->GetProperty()->SetColor(1, 1, 1);

//        renderer->AddActor(appendactor);
//        renderer->SetBackground(0, 0, 0);
//        // Zoom in a little by accessing the camera and invoking its "Zoom" method.
//        renderer->ResetCamera();
//        renderer->GetActiveCamera()->Zoom(1.5);

//        vtkSmartPointer<vtkRenderWindow> renWin = ui->qvtkWidget->GetRenderWindow();
//        renWin->AddRenderer(renderer);
        //renWin->SetSize(600, 600);

//        vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//        iren->SetRenderWindow(renWin);

//        //vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
//        //iren->SetInteractorStyle(style);
//        iren->Initialize();
//        iren->Start();

}

MainView::~MainView()
{
    delete ui;
}
