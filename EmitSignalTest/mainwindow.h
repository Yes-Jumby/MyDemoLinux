#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "EmitSignalOne.h"
#include "EmitSignalTwo.h"
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
    void myTestSignal(const QString &str);
private slots:
    void on_mysignal(const QString &str);
    void on_signalRefresh(const std::string &path);
private:
    CEmitSignalOne m_EmitSignalOne;
    CEmitSignalTwo m_EmitSignalTwo;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
