#include "sign_screen.h"

SignScreen::SignScreen(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(standard_Width, standard_height);
    //setStyleSheet("background-color:blue;");
    main_layout = new QVBoxLayout();
    main_layout->setAlignment(Qt::AlignCenter);
    main_layout->setContentsMargins(40, 0, 40, 0); // Set margin from right and left sides
    setLayout(main_layout);

    // Header Label
    QLabel *headerLabel = new QLabel("Registration", this);
    headerLabel->setAlignment(Qt::AlignCenter);
    QFont font("Segoe UI", 24, QFont::Bold);
    headerLabel->setFont(font);
    main_layout->addWidget(headerLabel);
    main_layout->addSpacing(80);

    // Username
    QVBoxLayout *user_name_layout = new QVBoxLayout(); // Define user_name_layout
    user_name = new QLabel("Username:");
    user_name_edit = new QLineEdit();
    user_name_edit->setStyleSheet("padding: 15px;"); // Add padding
    user_name_layout->addWidget(user_name);
    user_name_layout->addWidget(user_name_edit);
    main_layout->addLayout(user_name_layout);
    main_layout->addSpacing(20);

    // Password
    QVBoxLayout *password_layout = new QVBoxLayout(); // Define password_layout
    password = new QLabel("Password:");
    password_edit = new QLineEdit();
    password_edit->setEchoMode(QLineEdit::EchoMode::Password);
    password_edit->setStyleSheet("padding: 15px;"); // Add padding
    password_layout->addWidget(password);
    password_layout->addWidget(password_edit);
    main_layout->addLayout(password_layout);
    main_layout->addSpacing(20);

    // Buttons
    QHBoxLayout *button_layout = new QHBoxLayout(); // Define button_layout
    login = new Custom_Button("login");
    signup = new Custom_Button("signup");
    login->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    signup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    button_layout->addWidget(login);
    button_layout->addWidget(signup);
    main_layout->addLayout(button_layout);

    connect(signup, &QPushButton::clicked, this, &SignScreen::signup_pressed);
    connect(login, &QPushButton::clicked, this, &SignScreen::login_pressed);
}


////////////////////////////////////
void SignScreen::signup_pressed(){
    QFile file("data.txt");

    // Try to open the file in Write-Only mode
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open the file for writing.";
    }

    // Create a QTextStream object to write to the file
    QTextStream out(&file);

    // Write data to the file
    out << user_name_edit->text() << ':' << password_edit->text() << Qt::endl;
    //out << "This is a line written to the file." << Qt::endl;

    // Close the file
    file.close();
}

////////////////////////////////////////////////
void SignScreen::login_pressed(){
    QFile file("data.txt");

    // Try to open the file in Read-Only mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading.";
    }

    // Create QStringLists to store text before ':' and after ':'
    QStringList usernames;
    QStringList passwords;

    // Create a QTextStream object to read from the file
    QTextStream in(&file);

    // Read the file line by line
    while (!in.atEnd()) {
        QString line = in.readLine();

        // Split the line into two parts based on ':'
        QStringList parts = line.split(':');

        // Ensure the line has exactly two parts
        if (parts.size() == 2) {
            usernames.append(parts[0]);
            passwords.append(parts[1]);
        } else {
            qDebug() << "Invalid line format:" << line;
        }
    }

    // Close the file
    file.close();
    QString username = user_name_edit->text();
    QString password = password_edit->text();

    int index = usernames.indexOf(username);

    if (index != 1){
        if (password == passwords[index]){
            MainScreen *mainScreen = new MainScreen();
            mainScreen->setUserName(username.toStdString());
            mainScreen->show();
            this->hide();
        }
        else{
            msgBox.setText("Wrong username or password");
            msgBox.exec();
        }

    }
    else{
        msgBox.setText("Wrong username or password");
        msgBox.exec();
    }


    // Output the contents of the arrays
    //qDebug() << "Usernames:" << usernames;
    //qDebug() << "Passwords:" << passwords;
}
