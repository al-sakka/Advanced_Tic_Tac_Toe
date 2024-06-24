#include "database.h"

Database::Database() {
    createTable();
}

Database::~Database()
{
}

void Database::createTable()
{
    connOpen();
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS PLAYERDATA("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "USERNAME TEXT NOT NULL UNIQUE, "
               "PASSWORD TEXT NOT NULL)");

    query.clear();
    connClose();
}

void Database::createGameTable()
{
    connOpen();
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS GAMEHISTORY("
               "GameID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "USERNAME TEXT NOT NULL, "
               "matrix_column TEXT, "
               "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
               "MODE INTEGER, "
               "FOREIGN KEY(username) REFERENCES PlayerData(username))"
               );
    QSqlError last_error = query.lastError();
    qDebug() << last_error;
    query.clear();
    connClose();
}

void Database::connClose()
{
    xodb.close();
    xodb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool Database::connOpen()
{
    xodb = QSqlDatabase::addDatabase("QSQLITE");
    xodb.setDatabaseName("D:\\database1.db");

    if(!xodb.open()){
        qDebug() << "Failed to open the database "<<"\n";
        return false;
    }
    else
        qDebug() << "Connected.... "<<"\n";
    return true;
}

int Database::signup(QString username,QString password)
{
    connOpen();
    // return codes: 1-inserted succesfully , 0-Error ,2-Username is already registered
    QSqlQuery query;
    query.prepare("INSERT INTO PLAYERDATA (USERNAME , PASSWORD) VALUES (?,?)");
    query.addBindValue(username);
    query.addBindValue(password);
    if (!query.exec()){
        QSqlError last_error = query.lastError();
        if(last_error.nativeErrorCode() == "2067"){
            qDebug() << "Username is already registered";
            query.clear();
            connClose();
            return 2;
        }
        qDebug() << last_error;
        query.clear();
        connClose();
        return 0;
    }
    query.clear();
    connClose();
    return 1;
}

int Database::login(QString username, QString password)
{
    connOpen();
    QSqlQuery query;
    query.prepare( "SELECT * FROM PLAYERDATA WHERE USERNAME = '"+username+"' AND PASSWORD = '"+password+"' ");
    if (query.exec()){
        int count = 0;
        while(query.next()){
            count++;
        }
        if(count ==1){
            qDebug() << "login success";
            this->username = username;
            connClose();
            return 1;
        }
        else{
            qDebug() << "wrong username or password";
            connClose();
            return 0;
        }
    }
}

void Database::addGameHistory(const QString &username, const char matrix[3][3], int mode)
{
    connOpen();
    QJsonArray jsonArray;
    for (int i = 0; i < 3; ++i) {
        QJsonArray rowArray;
        for (int j = 0; j < 3; ++j) {
            rowArray.append(QString(matrix[i][j]));
        }
        jsonArray.append(rowArray);
    }
    QJsonDocument jsonDoc(jsonArray);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);

    QSqlQuery query;
    query.prepare("INSERT INTO GameHistory (username, matrix_column, mode) VALUES (?,?,?)");
    query.addBindValue(username);
    query.addBindValue(jsonString);
    query.addBindValue(mode);
    if (!query.exec()) {
        qDebug() << "Failed to insert game history:" << query.lastError();
    }
    query.clear();
    connClose();
}

QList<Database::GameHistoryEntry> Database::getAllGameHistory(){
    connOpen();
    QList<GameHistoryEntry> history;
    QSqlQuery query("SELECT username, matrix_column, timestamp FROM GameHistory");

    if (!query.exec()) {
        qDebug() << "Failed to retrieve game history:" << query.lastError();
        return history;
    }

    while (query.next()) {
        GameHistoryEntry entry;
        entry.username = query.value(0).toString();
        QString jsonString = query.value(1).toString();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        QJsonArray jsonArray = jsonDoc.array();

        for (int i = 0; i < 3; ++i) {
            QJsonArray rowArray = jsonArray[i].toArray();
            for (int j = 0; j < 3; ++j) {
                entry.matrix[i][j] = rowArray[j].toString().at(0).toLatin1();
            }
        }

        entry.timestamp = query.value(2).toString();
        history.append(entry);
    }
    connClose();
    //query.clear();
    return history;

}



