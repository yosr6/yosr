#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>      // Si vous utilisez des requêtes SQL
#include <QSqlError>      // Pour les erreurs SQL

class Connection {
private:
    QSqlDatabase db;

public:
    Connection();
    bool createconnection();
    void closeConnection();
};

#endif // CONNECTION_H
