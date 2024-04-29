/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName("MainScreen");
        MainScreen->resize(800, 600);
        centralwidget = new QWidget(MainScreen);
        centralwidget->setObjectName("centralwidget");
        MainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScreen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScreen);
        statusbar->setObjectName("statusbar");
        MainScreen->setStatusBar(statusbar);

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
