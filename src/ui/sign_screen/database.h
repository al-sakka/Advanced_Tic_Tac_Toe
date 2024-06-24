#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVariant>


using namespace std;
class Database
{
public:
    Database();
    ~Database();
    QString username;
    struct GameHistoryEntry {
        QString username;
        QString timestamp;
        char matrix[3][3];
    };
    QList<GameHistoryEntry> getAllGameHistory();
    void createTable();
    void createGameTable();
    void connClose();
    bool connOpen();
    int signup(QString username,QString password);
    int login(QString username,QString password);
    void addGameHistory(const QString &username, const char matrix[3][3],int mode);

private:
    QSqlDatabase xodb;



};

#endif // DATABASE_H
