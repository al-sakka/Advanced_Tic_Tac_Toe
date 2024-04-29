#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


using namespace std;
class Database
{
public:
    Database();
    ~Database();
    void createTable();
    void connClose();
    bool connOpen();
    int signup(QString username,QString password);
    int login(QString username,QString password);
private:
    QSqlDatabase xodb;
};

#endif // DATABASE_H
