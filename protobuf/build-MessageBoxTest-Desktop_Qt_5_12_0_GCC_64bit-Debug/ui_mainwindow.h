/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_info;
    QPushButton *pushButton_critial;
    QPushButton *pushButton_warn;
    QPushButton *pushButton_about;
    QPushButton *pushButton_test;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(454, 357);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_info = new QPushButton(centralWidget);
        pushButton_info->setObjectName(QString::fromUtf8("pushButton_info"));
        pushButton_info->setGeometry(QRect(110, 80, 89, 25));
        pushButton_critial = new QPushButton(centralWidget);
        pushButton_critial->setObjectName(QString::fromUtf8("pushButton_critial"));
        pushButton_critial->setGeometry(QRect(260, 80, 89, 25));
        pushButton_warn = new QPushButton(centralWidget);
        pushButton_warn->setObjectName(QString::fromUtf8("pushButton_warn"));
        pushButton_warn->setGeometry(QRect(110, 190, 89, 25));
        pushButton_about = new QPushButton(centralWidget);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
        pushButton_about->setGeometry(QRect(260, 190, 89, 25));
        pushButton_test = new QPushButton(centralWidget);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));
        pushButton_test->setGeometry(QRect(180, 250, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_info->setText(QApplication::translate("MainWindow", "info", nullptr));
        pushButton_critial->setText(QApplication::translate("MainWindow", "critial", nullptr));
        pushButton_warn->setText(QApplication::translate("MainWindow", "warn", nullptr));
        pushButton_about->setText(QApplication::translate("MainWindow", "about", nullptr));
        pushButton_test->setText(QApplication::translate("MainWindow", "test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
