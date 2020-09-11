#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <memory>

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
    void on_pushButton_info_clicked();

    void on_pushButton_critial_clicked();

    void on_pushButton_warn_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_test_clicked();

private:
    std::shared_ptr<QMessageBox> m_pMessageBox;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
