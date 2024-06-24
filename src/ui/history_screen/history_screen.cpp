#include "history_screen.h"

HistoryScreen::HistoryScreen(QWidget *parent) :
    QWidget{parent}
{
    QList<Database::GameHistoryEntry> history = db.getAllGameHistory();
    setWindowTitle("Matches History");

    // Create the main vertical layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Set standard sizes
    setFixedSize(800, 600); // Replace with your standard_Width and standard_height

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

    // Add the toolbar layout to the main layout
    mainLayout->addLayout(toolbarLayout);

    // Add spacing
    mainLayout->addSpacing(40);

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
                row += entry.matrix[i][j];
                if (j < 2) row += " ";
            }
            QLabel *rowLabel = new QLabel(row);
            groupBoxLayout->addWidget(rowLabel);
        }

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
    mainWindow->show();

    // will be changed latter
    mainWindow->setUserName(this->username);
    //
    this->hide();
}
