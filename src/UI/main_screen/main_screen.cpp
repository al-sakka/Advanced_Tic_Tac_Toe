#include "main_screen.h"

void mainScreen(std::string userName, QWidget *window)
{

    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(20, 20, 20, 20);

    layout->addSpacing(20);

    // Title label with variable
    std::stringstream welcomeMessage;
    welcomeMessage << "Welcome back, " << userName;
    QLabel *userLabel = new QLabel(QString::fromStdString(welcomeMessage.str()), window);
    userLabel->setAlignment(Qt::AlignCenter); // Align title to the center
    userLabel->setStyleSheet("font-weight: bold; font-size: 24px;");
    layout->addWidget(userLabel);

    layout->addSpacing(40);

    QLabel *modeLabel = new QLabel("Choose Game Mode:");
    modeLabel->setStyleSheet("font-size: 16px;"); // Set font size
    modeLabel->setAlignment(Qt::AlignCenter); // Align center
    layout->addWidget(modeLabel);

    layout->addSpacing(20);

    Custom_Button *custButton;
    custButton = new Custom_Button("Multiplayer", window);
    custButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(custButton);
    layout->setAlignment(Qt::AlignCenter);

    layout->addSpacing(20);

    // Define the Custom_Button class and its constructor

    Custom_Button *custButton2;
    custButton2 = new Custom_Button("Single Player", window);
    custButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(custButton2);
    layout->setAlignment(Qt::AlignCenter);

    // Create the difficulty buttons (easy, normal, hard)
    Custom_Button *easyButton = new Custom_Button("Easy",window);
    Custom_Button *normalButton = new Custom_Button("Normal", window);
    Custom_Button *hardButton = new Custom_Button("Hard", window);

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

    window->setLayout(layout);

}
