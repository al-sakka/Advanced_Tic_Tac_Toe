#include "main_screen.h"

MainScreen::MainScreen(QWidget *parent) :
    QWidget{parent}
{
    setWindowTitle("Tic Tac Toe");

    // Create the vertical layout for the main screen
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // standard
    setFixedSize(standard_Width, standard_height);

    // Create a horizontal layout for the toolbar
    QHBoxLayout *toolbarLayout = new QHBoxLayout();
    toolbarLayout->setSpacing(10);
    toolbarLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Create the logout button
    Custom_Button *logoutButton = new Custom_Button("<", this);
    logoutButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    toolbarLayout->addWidget(logoutButton);
    connect(logoutButton, &Custom_Button::clicked, this, &MainScreen::handleLogout);

    // Add the toolbar layout to the main layout
    mainLayout->addLayout(toolbarLayout);

    // Add spacing
    mainLayout->addSpacing(80);

    // Title label with variable
    QLabel *userLabel = new QLabel(this);
    userLabel->setAlignment(Qt::AlignCenter);
    userLabel->setStyleSheet("font-weight: bold; font-size: 24px;");
    mainLayout->addWidget(userLabel);

    mainLayout->addSpacing(40);

    // Label for game mode selection
    QLabel *modeLabel = new QLabel("Choose Game Mode:", this);
    modeLabel->setStyleSheet("font-size: 16px;"); // Set font size
    modeLabel->setAlignment(Qt::AlignCenter); // Align center
    mainLayout->addWidget(modeLabel);

    mainLayout->addSpacing(20);

    Custom_Button *custButton = new Custom_Button("Multiplayer", this);
    custButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(custButton);
    connect(custButton, &Custom_Button::clicked, this, &MainScreen::handleMultiplayer);

    Custom_Button *custButton2 = new Custom_Button("Single Player", this);
    custButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(custButton2);

    // Create the difficulty buttons (easy, normal, hard)
    Custom_Button *easyButton = new Custom_Button("Easy", this);
    easyButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(easyButton, &Custom_Button::clicked, this, &MainScreen::handleSingleplayerEasy);

    Custom_Button *normalButton = new Custom_Button("Normal", this);
    normalButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(normalButton, &Custom_Button::clicked, this, &MainScreen::handleSingleplayerNormal);

    Custom_Button *hardButton = new Custom_Button("Hard", this);
    hardButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(hardButton, &Custom_Button::clicked, this, &MainScreen::handleSingleplayerHard);

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
}

void MainScreen::setUserName(const std::string &userName) {
    this->userName = userName;
    QLabel *userLabel = findChild<QLabel *>();
    if (userLabel)
        userLabel->setText(QString::fromStdString("Welcome back, " + userName));
}

void MainScreen::handleLogout() {
    SignScreen *signWindow = new SignScreen();
    signWindow->show();
    this->hide();
}

void MainScreen::handleMultiplayer() {
    GameScreen *mainWindow = new GameScreen();
    mainWindow->show();
    this->hide();
}

void MainScreen::handleSingleplayerEasy() {
    //
}

void MainScreen::handleSingleplayerNormal() {
    //
}

void MainScreen::handleSingleplayerHard() {
    //
}
