#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    unsigned long a= 1;
    int b = 1;
    bool flag =(a==b);
    qDebug()<<flag;
    return;

    QString result = "";
    QFile scriptFile("/home/ubuntu/Documents/work/my first project/QT_to_JS_TEST/QT.js");
    if (!scriptFile.open(QIODevice::ReadOnly))
    {
        result.clear();
        qWarning() << "QT.js open failed";
        return;
    }
    QTextStream out(&scriptFile);
    QString contents = out.readAll();
    scriptFile.close();

    QScriptEngine engine;
    QScriptValue js = engine.evaluate(contents);        //个人理解：加载js文本到操作引擎
    QScriptValue func;
    func = engine.globalObject().property("startLiveServer");   //调用js方法
    result = func.call(QScriptValue()).toString();
    qDebug() << "result:" << result;
}

void MainWindow::on_pushButton_stop_clicked()
{
    QString result = "";
    QFile scriptFile("/home/ubuntu/Documents/work/my first project/QT_to_JS_TEST/QT.js");
    if (!scriptFile.open(QIODevice::ReadOnly))
    {
        result.clear();
        qWarning() << "QT.js open failed";
        return;
    }
    QTextStream out(&scriptFile);
    QString contents = out.readAll();
    scriptFile.close();

    QScriptEngine engine;
    QScriptValue js = engine.evaluate(contents);        //个人理解：加载js文本到操作引擎
    QScriptValue func;
    QScriptValueList arg;
    func = engine.globalObject().property("stopLiveServer");   //调用js方法
    result = func.call(QScriptValue()).toString();
    qDebug() << "result:" << result;
}

void MainWindow::on_pushButton_test_clicked()
{
    QString result = "";
    QFile scriptFile("/home/ubuntu/Documents/work/my first project/QT_to_JS_TEST/QT.js");
    if (!scriptFile.open(QIODevice::ReadOnly))
    {
        result.clear();
        qWarning() << "QT.js open failed";
        return;
    }
    QTextStream out(&scriptFile);
       QString contents = out.readAll();
       scriptFile.close();

       double var1 = 1;
       double var2 = 2;
       //qDebug() << "var1:" << var1 << "var2:" << var2;

       QScriptValueList args;      //调用js方法时传入的参数
       args << QScriptValue(var1) << QScriptValue(var2);
       QScriptEngine engine;
       QScriptValue js = engine.evaluate(contents);        //个人理解：加载js文本到操作引擎
       QScriptValue func;
       func = engine.globalObject().property("trans2wCal");   //调用js方法
       result = func.call(QScriptValue(), args).toString();
       qDebug() << "result:" << result;

       func = engine.globalObject().property("trans3wCal");   //调用js方法
       result = func.call(QScriptValue(), args).toString();
       qDebug() << "result:" << result;

}
