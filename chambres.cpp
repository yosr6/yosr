#include"chambres.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

Chambre::Chambre() : num(0), type(""), statut(""), equipement(""), prix(0.0) {}

Chambre::Chambre(int num, QString type, QString statut, QString equipement, double prix)
    : num(num), type(type), statut(statut), equipement(equipement), prix(prix) {}

Chambre::~Chambre() {}

bool Chambre::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO chambre (num, type, statut, equipement, prix) "
                  "VALUES (:num, :type, :statut, :equipement, :prix)");
    query.bindValue(":num", num);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":equipement", equipement);
    query.bindValue(":prix", prix);

    if (!query.exec()) {
           qDebug() << "Erreur lors de l'ajout de la chambre:" << query.lastError().text();
           return false;
       }
       return true;
}

bool Chambre::modifier(int num) {
    QSqlQuery query;
    query.prepare("UPDATE chambre SET type = :type, statut = :statut, equipement = :equipement, prix = :prix "
                  "WHERE num = :num");
    query.bindValue(":num", num);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":equipement", equipement);
    query.bindValue(":prix", prix);

    return query.exec();
}

bool Chambre::supprimer(int num) {
    QSqlQuery query;
    query.prepare("DELETE FROM chambre WHERE num = :num");
    query.bindValue(":num", num);

    return query.exec();
}

QSqlQueryModel* Chambre::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM chambre");
    return model;
}
