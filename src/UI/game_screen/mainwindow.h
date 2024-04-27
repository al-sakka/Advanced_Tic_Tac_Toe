#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include "cellbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
