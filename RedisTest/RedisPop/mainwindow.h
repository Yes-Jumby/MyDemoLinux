#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define PORT 6379
#define IP   "127.0.0.1"
#define TEST_CMD_COUNT 10
#include <hiredis.h>
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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    redisContext *m_redisContext;
    redisReply *m_reply;
    QString m_str;
};

#endif // MAINWINDOW_H
