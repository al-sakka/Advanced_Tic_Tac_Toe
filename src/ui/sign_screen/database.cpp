#include "database.h"

Database::Database() {

}

Database::~Database()
{
}

void Database::createTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS PLAYERDATA("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "USERNAME TEXT NOT NULL UNIQUE, "
               "PASSWORD TEXT NOT NULL)");

}

void Database::connClose()
{
    xodb.close();
    xodb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool Database::connOpen()
{
    xodb = QSqlDatabase::addDatabase("QSQLITE");
    xodb.setDatabaseName("D:\\study\\Programming\\Qt\\Qt Playlist\\XO\\DB\\database1.db");

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




