/********************************************************************************
** Form generated from reading UI file 'signscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNSCREEN_H
#define UI_SIGNSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignScreen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignScreen)
    {
        if (SignScreen->objectName().isEmpty())
            SignScreen->setObjectName("SignScreen");
        SignScreen->resize(800, 600);
        centralwidget = new QWidget(SignScreen);
        centralwidget->setObjectName("centralwidget");
        SignScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignScreen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        SignScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(SignScreen);
        statusbar->setObjectName("statusbar");
        SignScreen->setStatusBar(statusbar);

        retranslateUi(SignScreen);

        QMetaObject::connectSlotsByName(SignScreen);
    } // setupUi

    void retranslateUi(QMainWindow *SignScreen)
    {
        SignScreen->setWindowTitle(QCoreApplication::translate("SignScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignScreen: public Ui_SignScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNSCREEN_H
