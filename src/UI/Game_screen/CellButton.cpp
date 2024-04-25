#include "cellbutton.h"
#include "mainwindow.h"





CellButton::CellButton(MainWindow *parent) : QPushButton(parent), mainWindow(parent) {
    setText("");
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFixedSize(150, 150); // Set fixed size for the button
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QPushButton { background-color: black; border: 2px solid white; color: white; font-size: 80px;  }"); // Set button style and font size
    connect(this, &QPushButton::clicked, this, &CellButton::onClicked);
    currentPlayer_ = 1;
}





void CellButton::onClicked() {
    if (text().isEmpty()) { // Check if the cell is empty
        QString symbol = (currentPlayer_ == 1 ? "X" : "O");
        setText(symbol);

        // Set color based on symbol
        if (symbol == "X") {
            setStyleSheet("color: yellow;"
                          "background-color: black;"
                          "font-size: 80px;"
                          ); // Adjust the font size here as well
        } else if (symbol == "O") {
            setStyleSheet("color: red;"
                          "background-color: black;"
                          "font-size: 80px;"
                          ); // Adjust the font size here as well
        }

        emit cellClicked(currentPlayer_);
        currentPlayer_ = (currentPlayer_ == 1 ? 2 : 1); // Alternate between player 1 (X) and player 2 (O)
    }
}




void CellButton::setCurrentPlayer(int player) {
    currentPlayer_ = player;
}
