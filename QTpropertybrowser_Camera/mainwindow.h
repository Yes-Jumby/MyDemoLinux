#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qtpropertymanager.h"
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"
#include "QPropertyBrowser/QtTreePropertyBrowserForCamera.h"
#include <QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_valueChanged(QtProperty *property, const QVariant &value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int m_count;
    QMap<QtProperty*,QString>m_property_dic;
    CGrabberForCamera* m_pGrabberForCamera;
};

#endif // MAINWINDOW_H
