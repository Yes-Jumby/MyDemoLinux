#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_changeweb1_clicked();

    void on_pushButton_changeweb2_clicked();

    void on_pushButton_callfunction_clicked();

    //void on_signalTest();
    void on_pushButton_threadfun_clicked();

    void on_pushButton_timerStart_clicked();

    void on_pushButton_timerStop_clicked();
    void on_timeout();

signals:
    //void signalTest();
private:
    Ui::MainWindow *ui;
    QProcess* Process;
    QTimer* m_pTimer;
    int m_iIndex;
};

#endif // MAINWINDOW_H
