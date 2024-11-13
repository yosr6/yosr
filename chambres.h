#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"string.h"
class Chambre
{
    public:
        Chambre(); // constructeur par défaut

        Chambre(int num, QString type,QString statut,QString equipement,double prix);
        virtual~Chambre();

        int Getnum()const { return num; }
        void Setnum(int val) { num = val; }
        QString Gettype()const { return type; }
        void Settype(QString val) { type = val; }
        QString Getstatut()const { return statut; }
        void Setstatut(QString val) { statut = val; }
        QString Getequipement()const { return equipement; }
        void Setequipement(QString val) { equipement = val; }
        double Getprix() const{ return prix; }
        void Setprix(double val) { prix = val; }

        bool ajouter();
        bool modifier(int num);
        bool supprimer(int num);
        QSqlQueryModel* afficher();


    protected:

    private:
        int num;
        QString type;
        QString statut;
        QString equipement;
        double prix;
};


#endif // CHAMBRE_H
