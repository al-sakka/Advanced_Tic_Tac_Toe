// main_screen.h
#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <string>
#include "../../../utilities/main_includes.h"
#include "../../../utilities/Buttons/custom_button.h"
#include "../../../utilities/Animation/animation.h"

class MainScreen : public QWidget {
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    // MainScreen(QWidget *parent = nullptr);
    void setUserName(const std::string &userName);
signals:
    void multiplayerButtonClicked();
private slots:
    // void showHideDifficultyButtons();

private:
    QVBoxLayout *layout;
    Custom_Button *custButton;
    Custom_Button *custButton2;
    Custom_Button *easyButton;
    Custom_Button *normalButton;
    Custom_Button *hardButton;
    std::string userName;
    bool difficultyVisible;

    // void createFadeAnimation(QWidget *widget, bool fadeIn);
};

#endif // MAIN_SCREEN_H
