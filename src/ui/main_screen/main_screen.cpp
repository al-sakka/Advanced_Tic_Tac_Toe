#include "main_screen.h"
#include "./ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    setWindowTitle("Tic Tac Toe");
    // Create the vertical layout for the main screen
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    // mainLayout->setAlignment(Qt::AlignCenter);
    // mainLayout->setContentsMargins(20, 20, 20, 20);

    // Set fixed size
    // setFixedSize(standard_Width, standard_hight);

    // Add spacing
    // mainLayout->addSpacing(20);

    // Title label with variable
    QLabel *userLabel = new QLabel(this);
    userLabel->setAlignment(Qt::AlignCenter);
    userLabel->setStyleSheet("font-weight: bold; font-size: 24px;");
    mainLayout->addWidget(userLabel);

    // mainLayout->addSpacing(40);

    // Label for game mode selection
    QLabel *modeLabel = new QLabel("Choose Game Mode:", this);
    modeLabel->setStyleSheet("font-size: 16px;"); // Set font size
    modeLabel->setAlignment(Qt::AlignCenter); // Align center
    mainLayout->addWidget(modeLabel);

    // mainLayout->addSpacing(20);

    // Create the difficulty buttons (easy, normal, hard)
    Custom_Button *easyButton = new Custom_Button("Easy", this);
    Custom_Button *normalButton = new Custom_Button("Normal", this);
    Custom_Button *hardButton = new Custom_Button("Hard", this);

    // Hide the difficulty buttons initially
    easyButton->hide();
    normalButton->hide();
    hardButton->hide();

    // Add the difficulty buttons to a horizontal layout
    QHBoxLayout *difficultyLayout = new QHBoxLayout();
    difficultyLayout->addWidget(easyButton);
    difficultyLayout->addWidget(normalButton);
    difficultyLayout->addWidget(hardButton);
    mainLayout->addLayout(difficultyLayout);

    Custom_Button *custButton2 = new Custom_Button("Single Player", this);
    // custButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(custButton2);

    Custom_Button *custButton = new Custom_Button("Multiplayer", this);
    // custButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(custButton);

    bool difficultyVisible = false;
   // Connect the Single Player button to show/hide the difficulty buttons with fade animation
    QObject::connect(custButton2, &Custom_Button::clicked, [=]() mutable {
        if (!difficultyVisible) {
            easyButton->show();
            normalButton->show();
            hardButton->show();
            createFadeAnimation(easyButton, true);
            createFadeAnimation(normalButton, true);
            createFadeAnimation(hardButton, true);
        } else {
            createFadeAnimation(easyButton, false);
            createFadeAnimation(normalButton, false);
            createFadeAnimation(hardButton, false);
        }
        difficultyVisible = !difficultyVisible;
    });

    // Connect the Multiplayer button to switch to GameScreen
    QObject::connect(custButton, &Custom_Button::clicked, [=]() {
        GameScreen *mainWindow = new GameScreen();
        mainWindow->show();
        this->hide();
    });

    // Set layout for the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainScreen::setUserName(const std::string &userName) {
    this->userName = userName;
    QLabel *userLabel = findChild<QLabel *>();
    if (userLabel)
        userLabel->setText(QString::fromStdString("Welcome back, " + userName));
}
