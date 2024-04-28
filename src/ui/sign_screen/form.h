#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>
#include <QFile>
#include "custom_button.h"




class Form : public QWidget
{
    Q_OBJECT
public:
    explicit Form(QWidget *parent = nullptr);

public slots:
    //void login_pressed();
    void signup_pressed();
    void login_pressed();
private:
    QVBoxLayout *main_layout;
    QHBoxLayout *row1;
    QHBoxLayout *row2;
    QHBoxLayout *row3;
    QLabel* user_name;
    QLineEdit* user_name_edit;
    QLabel* password;
    QLineEdit* password_edit;
    QMessageBox msgBox;
    Custom_Button* login;
    Custom_Button* signup;
};

#endif // FORM_H
