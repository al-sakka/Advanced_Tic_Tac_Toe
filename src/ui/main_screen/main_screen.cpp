// main_screen.cpp
#include "main_screen.h"
#include "../game_screen/mainwindow.h" // Include the header file of MainWindow

MainScreen::MainScreen(QWidget *parent) : QWidget(parent) {

    // connect(custButton, &Custom_Button::clicked, this, &MainScreen::multiplayerButtonClicked);

    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(20, 20, 20, 20);

    ////////////
    setFixedSize(standard_Width, standard_hight);

    layout->addSpacing(20);

    // Title label with variable
    QLabel *userLabel = new QLabel(this);
    userLabel->setAlignment(Qt::AlignCenter);
    userLabel->setStyleSheet("font-weight: bold; font-size: 24px;");
    layout->addWidget(userLabel);

    layout->addSpacing(40);

    QLabel *modeLabel = new QLabel("Choose Game Mode:");
    modeLabel->setStyleSheet("font-size: 16px;"); // Set font size
    modeLabel->setAlignment(Qt::AlignCenter); // Align center
    layout->addWidget(modeLabel);

    layout->addSpacing(20);

    // Custom_Button *custButton;
    custButton = new Custom_Button("Multiplayer", this);
    custButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(custButton);
    layout->setAlignment(Qt::AlignCenter);

    layout->addSpacing(20);

    // Define the Custom_Button class and its constructor

    // Custom_Button *custButton2;
    custButton2 = new Custom_Button("Single Player", this);
    custButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(custButton2);
    layout->setAlignment(Qt::AlignCenter);

    // Create the difficulty buttons (easy, normal, hard)
    Custom_Button *easyButton = new Custom_Button("Easy",this);
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
    layout->addLayout(difficultyLayout);

    bool isVisible = false;

    // Connect the Single Player button to show/hide the difficulty buttons with fade animation
    QObject::connect(custButton2, &Custom_Button::clicked, [=]() mutable {
        if (!isVisible) {
            easyButton->show();
            normalButton->show();
            hardButton->show();
            createFadeAnimation(easyButton, true);
            createFadeAnimation(normalButton, true);
            createFadeAnimation(hardButton, true);

            // Disconnect the destroyed signal after the fade-in animation
            QObject::disconnect(easyButton, &QObject::destroyed, nullptr, nullptr);
            QObject::disconnect(normalButton, &QObject::destroyed, nullptr, nullptr);
            QObject::disconnect(hardButton, &QObject::destroyed, nullptr, nullptr);
        } else {
            createFadeAnimation(easyButton, false);
            createFadeAnimation(normalButton, false);
            createFadeAnimation(hardButton, false);

            // Connect the destroyed signal to hide the buttons after fade-out animation
            QObject::connect(easyButton, &QObject::destroyed, [=]() mutable {
                easyButton->hide();
                normalButton->hide();
                hardButton->hide();
                QObject::disconnect(easyButton, &QObject::destroyed, nullptr, nullptr);
                QObject::disconnect(normalButton, &QObject::destroyed, nullptr, nullptr);
                QObject::disconnect(hardButton, &QObject::destroyed, nullptr, nullptr);
            });
        }
        isVisible = !isVisible;
    });

    MainWindow *mainWindow = new MainWindow();
    // Connect the Multiplayer button to switch to MainWindow
    QObject::connect(custButton, &Custom_Button::clicked, [=]() {
         // Create an instance of MainWindow
        mainWindow->show(); // Show the MainWindow
        this->hide(); // Close the current MainScreen
    });

    setLayout(layout);
}

void MainScreen::setUserName(const std::string &userName) {
    this->userName = userName;
    QLabel *userLabel = findChild<QLabel *>();
    if (userLabel)
        userLabel->setText(QString::fromStdString("Welcome back, " + userName));
}
