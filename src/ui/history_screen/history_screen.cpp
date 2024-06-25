#include "history_screen.h"

HistoryScreen::HistoryScreen(QWidget *parent) :
    QWidget{parent}
{
    history = db.getAllGameHistory();
    setWindowTitle("Matches History");

    // Create the main vertical layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Set standard sizes
    setFixedSize(standard_Width, standard_height); // Replace with your standard_Width and standard_height

    // Create a horizontal layout for the toolbar
    QHBoxLayout *toolbarLayout = new QHBoxLayout();
    toolbarLayout->setSpacing(10);
    toolbarLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Create the GoBack button
    Custom_Button *goBackButton = new Custom_Button("↩", this);
    QFont bannerFont("Segoe UI", 15);
    goBackButton->setFont(bannerFont);
    goBackButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    toolbarLayout->addWidget(goBackButton);
    connect(goBackButton, &Custom_Button::clicked, this, &HistoryScreen::handleGoBack);

    // Create the "Matches history" label
    QLabel *historyLabel = new QLabel("Matches history", this);
    historyLabel->setFont(bannerFont); // Use the same font for consistency
    toolbarLayout->addWidget(historyLabel);

    // Add the toolbar layout to the main layout
    mainLayout->addLayout(toolbarLayout);

    // Add spacing
    mainLayout->addSpacing(10);

    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // Create a widget to hold the history layout
    QWidget *historyWidget = new QWidget;
    QVBoxLayout *historyLayout = new QVBoxLayout(historyWidget);
    historyLayout->setAlignment(Qt::AlignTop);

    // Populate the history layout with game history entries
    for (const auto &entry : history) {
        QGroupBox *groupBox = new QGroupBox("Game History Entry");
        QVBoxLayout *groupBoxLayout = new QVBoxLayout;

        QLabel *usernameLabel = new QLabel("Username: " + entry.username);
        QLabel *timestampLabel = new QLabel("Timestamp: " + entry.timestamp);

        groupBoxLayout->addWidget(usernameLabel);
        groupBoxLayout->addWidget(timestampLabel);

        QLabel *matrixLabel = new QLabel("Matrix:");
        groupBoxLayout->addWidget(matrixLabel);

        for (int i = 0; i < 3; ++i) {
            QString row;
            for (int j = 0; j < 3; ++j) {
                row += entry.movesHistory.at(entry.movesHistory.length() - 1).cMove[i][j];
                if (j < 2) row += " ";
            }
            QLabel *rowLabel = new QLabel(row);
            groupBoxLayout->addWidget(rowLabel);
        }

        // Create and add the "Show Game" button
        Custom_Button *moreButton = new Custom_Button("Show Game", this);

        // Connect the "Show Game" button to the handleReplayScreen function
        connect(moreButton, &Custom_Button::clicked, [this, entry]() { handleReplayScreen(entry); });

        groupBoxLayout->addWidget(moreButton);

        groupBox->setLayout(groupBoxLayout);
        historyLayout->addWidget(groupBox);
    }

    // Set the history layout as the content of the scroll area
    scrollArea->setWidget(historyWidget);

    // Add the scroll area to the main layout
    mainLayout->addWidget(scrollArea);
}

void HistoryScreen::handleGoBack()
{
    MainScreen *mainWindow = new MainScreen();
    mainWindow->setUserName(this->username);
    mainWindow->show();

    // will be changed latter

    //
    this->hide();
}

void HistoryScreen::setUserName(QString username)
{
    this->username = username;
}

void HistoryScreen::handleReplayScreen(Database::GameHistoryEntry entry)
{
    ReplayScreen *replayScreen = new ReplayScreen();


    // will be changed later
    replayScreen->setUsername(this->username);
    replayScreen->setEntry(entry);
    replayScreen->setGameId(entry.gameId);
    replayScreen->show();
    this->hide();
}
