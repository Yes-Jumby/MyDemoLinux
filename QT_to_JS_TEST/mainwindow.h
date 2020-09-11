#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_test_clicked();

private:
    Ui::MainWindow *ui;
    void readJS();
};

#endif // MAINWINDOW_H
