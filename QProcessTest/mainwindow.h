#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QProcess>
#include "QProcessServer.h"
#include "interface.h"
//#include "ReadAndWriteDat.h"
//#include "sharedlibrarytest.h"
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
    void on_start_clicked();
    void on_stop_clicked();
    void on_readoutput();
    void on_readerror();
    void on_start_2_clicked();

    void on_start_CLASS_clicked();

    void on_stop_CLASS_clicked();

private:
    Ui::MainWindow *ui;
QProcess* cmd;
QString strCmd;
CQProcessServer *cmdclass;
CInterface Interface;
//CReadAndWriteDat ReadAndWriteDat;
//SharedLibraryTest SharedLibraryTest1;
};
#endif // MAINWINDOW_H
