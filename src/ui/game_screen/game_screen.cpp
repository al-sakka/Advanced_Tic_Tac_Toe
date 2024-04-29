#include "game_screen.h"

GameScreen::GameScreen(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setContentsMargins(50, 50, 50, 50); // Set margins for the main layout

    // Set standard W,H
    setFixedSize(standard_Width, standard_height);

    QLabel *headerLabel = new QLabel("Match", this);
    headerLabel->setAlignment(Qt::AlignCenter);
    QFont font("Segoe UI", 30, QFont::Bold); // Increase font size and make it bold
    headerLabel->setFont(font);
    mainLayout->addWidget(headerLabel);
    mainLayout->addSpacing(20);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(centralWidget);
    centralLayout->setAlignment(Qt::AlignCenter);
    centralLayout->setSpacing(20); // Set spacing between widgets
    centralWidget->setLayout(centralLayout);

    setWindowTitle("Tic-Tac-Toe Match");
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    setStyleSheet("QMainWindow::title { background-color: black; color: white; }");
    setStyleSheet("background-color: white;");

    mainLayout->addWidget(centralWidget);

    ////////////////////////// The GRID ///////////////////////////////////
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10); // Set spacing between buttons

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            CellButton *button = new CellButton(this);
            // Set cell style
            button->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 80px");
            button->setFont(QFont("Arial", 24, QFont::Bold)); // Set font size
            button->setMinimumSize(105, 105); // Set minimum size for each cell button

            gridLayout->addWidget(button, row, col);
            connect(button, &QPushButton::clicked, this, [=](){ handleButtonClick(row, col, button); });
            cellButtons[row][col] = button; // Store the button in your array for later use
        }
    }

    centralLayout->addLayout(gridLayout);
    //////////////////////////////////////////////////////////////////////////////////

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(20); // Set spacing between buttons

    resetButton = new Custom_Button("Reset", this);
    resetButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ReturnMenu = new Custom_Button("Menu", this);
    ReturnMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    MatchHistory = new Custom_Button("History", this);
    MatchHistory->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(ReturnMenu);
    buttonLayout->addWidget(MatchHistory);

    centralLayout->addLayout(buttonLayout);

    connect(resetButton, &QPushButton::clicked, this, &GameScreen::handleResetButtonClicked);
    connect(ReturnMenu, &QPushButton::clicked, this, &GameScreen::handleReturnClicked);

    // Initialize the game state to player X
    currentPlayer = Player::X;
}

GameScreen::~GameScreen() {
    // TODO :: Destructor Implementation
}

void GameScreen::handleReturnClicked()
{
    MainScreen *mainScreen = new MainScreen();
    mainScreen->show();
    this->hide();
}

void GameScreen::handleResetButtonClicked(){
    // Reset the game
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cellButtons[row][col]->setText("");
        }
    }
    currentPlayer = Player::X; // Reset the current player to Player::X
}

void GameScreen::handleButtonClick(int row, int col, QPushButton *button) {
    if (button->text() == "") {
        if (currentPlayer == Player::X) {
            button->setText("X");
            button->setStyleSheet("background-color: black; border: 2px solid white; color: red; font-size: 80px");
        }
        else {
            button->setText("O");
            button->setStyleSheet("background-color: black; border: 2px solid white; color: yellow; font-size: 80px");
        }

        // Check for a winner
        if (checkWinner()) {

            msgBox.setStandardButtons( QMessageBox::Yes);
            QSpacerItem* horizontalSpacer = new QSpacerItem(400, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);
            msgBox.setText( "Winnerr !!!" );
            QGridLayout* layout = (QGridLayout*)msgBox.layout();
            layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
            msgBox.exec();

        } else {
            // Switch players
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
        }
    }
}

bool GameScreen::checkWinner() {
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (cellButtons[row][0]->text() != "" &&
            cellButtons[row][0]->text() == cellButtons[row][1]->text() &&
            cellButtons[row][1]->text() == cellButtons[row][2]->text())
            return true;
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (cellButtons[0][col]->text() != "" &&
            cellButtons[0][col]->text() == cellButtons[1][col]->text() &&
            cellButtons[1][col]->text() == cellButtons[2][col]->text())
            return true;
    }

    // Check diagonals
    if (cellButtons[0][0]->text() != "" &&
        cellButtons[0][0]->text() == cellButtons[1][1]->text() &&
        cellButtons[1][1]->text() == cellButtons[2][2]->text())
        return true;

    if (cellButtons[0][2]->text() != "" &&
        cellButtons[0][2]->text() == cellButtons[1][1]->text() &&
        cellButtons[1][1]->text() == cellButtons[2][0]->text())
        return true;

    return false;
}
