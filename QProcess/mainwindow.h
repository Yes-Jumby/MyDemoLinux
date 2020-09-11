#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QProcess>
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
private:
    Ui::MainWindow *ui;
QProcess Process;
};
#endif // MAINWINDOW_H
