#include "form.h"

Form::Form(QWidget *parent)
    : QWidget{parent}
{
    //setFixedSize(300,300);
    //setStyleSheet("background-color:blue;");
    main_layout = new QVBoxLayout();
    main_layout->setAlignment(Qt::AlignCenter);
    setLayout(main_layout);


    row1 = new QHBoxLayout();
    user_name = new QLabel("username : ");
    user_name_edit = new QLineEdit();
    row1->setSpacing(50);
    row1->addWidget(user_name);
    row1->addWidget(user_name_edit);
    main_layout->addLayout(row1);


    row2 = new QHBoxLayout();
    password = new QLabel("Password : ");
    password_edit = new QLineEdit();
    password_edit->setEchoMode(QLineEdit::EchoMode::Password);
    row2->setSpacing(50);
    row2->addWidget(password);
    row2->addWidget(password_edit);
    main_layout->addLayout(row2);


    row3 = new QHBoxLayout();
    login = new Custom_Button("login");
    signup = new Custom_Button("signup");
    login->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    signup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    row3->addStretch();
    row3->addWidget(login);
    row3->addWidget(signup);
    main_layout->addLayout(row3);

    connect(signup,&QPushButton::clicked,this,&Form::signup_pressed);
    connect(login,&QPushButton::clicked,this,&Form::login_pressed);

}
void Form::signup_pressed(){
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

void Form::login_pressed(){
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
            msgBox.setText("Welcome");
            msgBox.exec();
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
