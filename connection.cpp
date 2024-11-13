#include "connection.h"
#include <QMainWindow>
#include "chambres.h"
#include <QSqlError>
#include <QSqlQuery>

Connection::Connection()
{

}

bool Connection::createconnection()
{
 db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");//inserer le nom de la source de données
db.setUserName("yoser");//inserer nom de l'utilisateur
db.setPassword("oracle");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;
return test;
if (!db.open()) {
qDebug() << "Database Error: " << db.lastError().text();
    // Handle the error, return false or show an error message
    return false;
}
}
