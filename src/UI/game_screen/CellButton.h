#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>

class MainWindow; // Forward declaration of MainWindow class

class CellButton : public QPushButton {
    Q_OBJECT

public:
    explicit CellButton(MainWindow *parent = nullptr);

signals:
    void cellClicked(int value);

public slots:
    void setCurrentPlayer(int player);

private slots:
    void onClicked();

private:
    int currentPlayer_;
    MainWindow *mainWindow; // Pointer to MainWindow
};

#endif // CELLBUTTON_H
