#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <vtkOrientationMarkerWidget.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vtkAxesActor* axesActor =

 vtkAxesActor::New();

 vtkOrientationMarkerWidget* widgetAxes =

 vtkOrientationMarkerWidget::New();

 widgetAxes->SetOrientationMarker(axesActor);

 widgetAxes->SetInteractor(ui->qvtkWidget->GetRenderWindow()->GetInteractor());

 widgetAxes->SetEnabled(1);

 widgetAxes->SetInteractive(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
