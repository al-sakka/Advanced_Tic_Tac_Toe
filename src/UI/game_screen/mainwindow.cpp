#include "mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include "ui_mainwindow.h"
#include <QLabel>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{







    /****************************************<Header Ui propr.>********************************************************************/
    //this header is responsible for the "XO-mathc" appears
    ui->setupUi(this);
    // Create the header label
    QLabel *headerLabel = new QLabel("X-O Match", this);
    headerLabel->setAlignment(Qt::AlignCenter); // Center-align the text
    QFont font("Segoe UI", 25, QFont::Bold);
    headerLabel->setFont(font);
    //headerLabel->setStyleSheet("background-color: red; color: white; font-size: 55px; padding: 10px;"); // another style if neeeded




    // Set the header label as the window's header
    setWindowTitle(" Tic-Tac-Toe Match "); // Set window title
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint); // Set window flags
    setCentralWidget(ui->centralwidget); // Set central widget
    setStyleSheet("QMainWindow::title { background-color: black; color: white; }"); // Set window title style
    setUnifiedTitleAndToolBarOnMac(true); // Enable unified title and toolbar on macOS
    setMenuWidget(headerLabel); // Set header label as the window's header
    /*************************************************<end of header>********************************************************************/







    /*Creating Widget*/
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);





     /******************************************************************************************************************/
    /******↓ ↓ ↓ ↓ ↓ ↓↓ ↓↓ ↓↓↓↓↓↓**     **** Making the program with fixed Dimensions *************** */
    setFixedSize(500, 600);


    mainLayout = new QVBoxLayout(centralWidget);











     /******************************************************************************************************************/
    /***↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*********     **** Creating the cells and adding it to the gridWidget *************** */
    QWidget *gridWidget = new QWidget(centralWidget);
    QGridLayout *gridLayout = new QGridLayout(gridWidget);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cellButtons[row][col] = new CellButton(this);
            gridLayout->addWidget(cellButtons[row][col], row, col);
            connect(cellButtons[row][col], &CellButton::cellClicked, this, &MainWindow::handleCellClicked);

            // Set cell style
            cellButtons[row][col]->setStyleSheet("background-color: black; border: none; color: white;");
            cellButtons[row][col]->setFont(QFont("Arial", 24, QFont::Bold)); // Set font size
            cellButtons[row][col]->setMinimumSize(100, 100); // Set minimum size for each cell button
        }
    }



    gridWidget->setLayout(gridLayout);
    mainLayout->addWidget(gridWidget);











    /******************************************************************************************************************/
    /***↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*************    Creating the down buttons , don't forget to intiallize them form mainWindo.h file!!!       *************** */
    resetButton = new QPushButton("Reset", centralWidget);
    exitButton = new QPushButton("Exit", centralWidget);
    ReturnMenu = new QPushButton("MainMenu", centralWidget);
    MatchHistory = new QPushButton("MatchHistory", centralWidget);










    /**********************************************************************************************************************************/
    /***↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓********* **** Applying styles and hover effcet to the buttons , the implementation is donw there *********** */

    setButtonStyle(resetButton);
    setButtonStyle(exitButton);
    setButtonStyle(ReturnMenu);
    setButtonStyle(MatchHistory);
    //hover effect
    setButtonHoverEffect(resetButton);
    setButtonHoverEffect(exitButton);
    setButtonHoverEffect(ReturnMenu);
    setButtonHoverEffect(MatchHistory);



    // Set a fixed size for the buttons
    resetButton->setFixedSize(100, 50);
    exitButton->setFixedSize(100, 50);
    ReturnMenu->setFixedSize(100,50);
    MatchHistory->setFixedSize(115,50);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(ReturnMenu);
    buttonLayout->addWidget(MatchHistory);
    buttonLayout->setSpacing(10); // Add spacing between buttons
    buttonLayout->setContentsMargins(10, 10, 10, 10); // Add margins around buttons

    mainLayout->addLayout(buttonLayout);















    /******************************************************************************************************************/
    /***↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*********     **** Connecting buttons to different screens!!!!!!!!!!!!!!!!!!!!!!! *********** */
    //NOTE /* Don't forget to connect the other buttons!  */



    connect(resetButton, &QPushButton::clicked, this, &MainWindow::handleResetButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::handleExitButtonClicked);





















    // Set window background color to white
    setStyleSheet("background-color: white;");

    currentPlayer = 1; //to change which to start X or O ?
}











void MainWindow::setButtonStyle(QPushButton *button) {
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(button);
    shadowEffect->setBlurRadius(5); // Set blur radius
    shadowEffect->setColor(QColor(0, 0, 0, 128)); // Set shadow color and opacity
    shadowEffect->setOffset(5, 5); // Set shadow offset
    button->setGraphicsEffect(shadowEffect); // Apply shadow effect to the button

    button->setStyleSheet(
        "QPushButton {"
        "   background-color: black;"
        "   border: 2px solid white;"
        "   border-radius: 25px;" // Adjust the radius to make the button more or less rounded
        "   color: white;"
        "   padding: 10px 20px;" // Adjust the padding to control the button size
        "}"
        );
}




void MainWindow::setButtonHoverEffect(QPushButton *button) {
    button->setCursor(Qt::PointingHandCursor); // Change cursor to pointing hand on hover
    QString style =
        "QPushButton:hover {"
        "   background-color: yellow;" // Adjust the opacity for hover effect
        " color: black;"
        "}";
    button->setStyleSheet(button->styleSheet() + style);
}





MainWindow::~MainWindow()
{
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            delete cellButtons[row][col];
        }
    }
}

void MainWindow::handleCellClicked(int player) {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cellButtons[row][col]->setCurrentPlayer(currentPlayer);
        }
    }
}

void MainWindow::handleResetButtonClicked() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cellButtons[row][col]->setText("");
        }
    }
}

void MainWindow::handleExitButtonClicked() {
    close(); // Close the main window and exit the program
}
