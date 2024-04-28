#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include "CellButton.h"
#include "../main_screen/main_screen.h"

namespace Ui {
class GameScreen;
}

class GameScreen : public QMainWindow {
    Q_OBJECT

public:
    GameScreen(QWidget *parent = nullptr);
    ~GameScreen();

private slots:
    void handleCellClicked(int player);
    void handleResetButtonClicked();
    void handleExitButtonClicked();

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    CellButton *cellButtons[3][3];
    int currentPlayer;
    QPushButton *resetButton;
    QPushButton *exitButton;
    QPushButton *ReturnMenu;
    QPushButton *MatchHistory;
    void setButtonStyle(QPushButton *button);
    void setButtonHoverEffect(QPushButton *button);


    Ui::GameScreen *ui;
};

#endif // GAME_SCREEN_H
