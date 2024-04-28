#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <string>
#include "../../../utilities/main_includes.h"
#include "../../../utilities/Buttons/custom_button.h"
#include "../../../utilities/Animation/animation.h"
#include "../game_screen/game_screen.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    void setUserName(const std::string &userName);
signals:
    // void multiplayerButtonClicked();
private:
    Ui::MainScreen *ui;
    std::string userName;
};

#endif // MAIN_SCREEN_H
