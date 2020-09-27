#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "pointCloudRender.h"
namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainView *ui;
    PointCloudRender m_ren;
};

#endif // MAINVIEW_H
