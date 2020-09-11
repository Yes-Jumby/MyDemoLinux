#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface.h"
#include "QProcessServer.h"
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
    void on_pushButton_open_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::MainWindow *ui;
    CInterface Interface;
    CQProcessServer *cmdclass;
};

#endif // MAINWINDOW_H
