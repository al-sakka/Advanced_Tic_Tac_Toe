#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include "CellButton.h"
#include "../../../utilities/Buttons/custom_button.h"
#include "../../../utilities/main_includes.h"
#include "../main_screen/main_screen.h"

class GameScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr);
    ~GameScreen();

private slots:
    void handleReturnClicked();
    void handleResetButtonClicked();
    void handleButtonClick(int row, int col, QPushButton *button);
    bool checkWinner();

private:
    enum class Player { X, O };
    QPushButton *cellButtons[3][3];
    Player currentPlayer = Player::X;

    Custom_Button *resetButton;
    Custom_Button *ReturnMenu;
    Custom_Button *MatchHistory;
    QMessageBox msgBox;
    QVBoxLayout *mainLayout;
};

#endif // GAME_SCREEN_H
