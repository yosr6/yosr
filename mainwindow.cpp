#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "chambres.h"   // Assurez-vous d'inclure la classe Chambre
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecter les boutons aux slots correspondants
    connect(ui->ajouter_chambre, &QPushButton::clicked, this, &MainWindow::ajouter_chambre_clicked);
    connect(ui->supprimer_chambre, &QPushButton::clicked, this, &MainWindow::supprimer_chambre_clicked);
    connect(ui->modifier_chambre, &QPushButton::clicked, this, &MainWindow::modifier_chambre_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot pour modifier une chambre
void MainWindow::modifier_chambre_clicked()
{
    // Vérifier si tous les champs sont remplis
    if (ui->num_chambre->text().isEmpty() ||
        ui->type_chambre->text().isEmpty() ||
        ui->statut_chambre->text().isEmpty() ||
        ui->equipement_chambre->text().isEmpty() ||
        ui->prix_chambre->text().isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Tous les champs doivent être remplis."));
        return;
    }

    // Récupérer les données modifiées des champs de l'interface utilisateur
    int num = ui->num_chambre->text().toInt();
    QString type = ui->type_chambre->text();
    QString statut = ui->statut_chambre->text();
    QString equipement = ui->equipement_chambre->text();
    double prix = ui->prix_chambre->text().toDouble();

    // Créer un objet Chambre avec les informations mises à jour
    Chambre chambre(num, type, statut, equipement, prix);

    // Tenter de modifier la chambre dans la base de données
    if (chambre.modifier(num)) {
        // Rafraîchir l'affichage pour refléter les changements
        ui->afficher->setModel(chambre.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Modification effectuée."));

        // Réinitialiser les champs
        ui->num_chambre->clear();
        ui->type_chambre->clear();
        ui->statut_chambre->clear();
        ui->equipement_chambre->clear();
        ui->prix_chambre->clear();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La modification a échoué. Assurez-vous que le numéro existe."));
    }
}

// Slot pour supprimer une chambre
void MainWindow::supprimer_chambre_clicked()
{
    // Vérifier si le champ "num_chambre" est vide
    if (ui->num_chambre->text().isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez saisir un numéro de chambre."));
        return;
    }

    int num = ui->num_chambre->text().toInt();

    // Créer un objet Chambre et définir son numéro pour suppression
    Chambre chambre;
    chambre.Setnum(num);

    // Tenter de supprimer la chambre dans la base de données
    if (chambre.supprimer(num)) {
        // Rafraîchir l'affichage si la suppression a réussi
        ui->afficher->setModel(chambre.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Suppression effectuée."));

        // Réinitialiser les champs
        ui->num_chambre->clear();
        ui->type_chambre->clear();
        ui->statut_chambre->clear();
        ui->equipement_chambre->clear();
        ui->prix_chambre->clear();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La suppression a échoué."));
    }
}

// Slot pour ajouter une chambre
void MainWindow::ajouter_chambre_clicked()
{
    // Vérifier si tous les champs sont remplis
    if (ui->num_chambre->text().isEmpty() ||
        ui->type_chambre->text().isEmpty() ||
        ui->statut_chambre->text().isEmpty() ||
        ui->equipement_chambre->text().isEmpty() ||
        ui->prix_chambre->text().isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Tous les champs doivent être remplis."));
        return;
    }

    // Récupérer les données des champs de l'interface utilisateur
    int num = ui->num_chambre->text().toInt();
    QString type = ui->type_chambre->text();
    QString statut = ui->statut_chambre->text();
    QString equipement = ui->equipement_chambre->text();
    double prix = ui->prix_chambre->text().toDouble();

    // Créer un objet Chambre avec les données récupérées
    Chambre chambre(num, type, statut, equipement, prix);

    // Tenter d'ajouter la chambre dans la base de données
    if (chambre.ajouter()) {
        // Rafraîchir l'affichage pour montrer la nouvelle entrée
        ui->afficher->setModel(chambre.afficher());  // Utiliser setModel sur QTableView
        QMessageBox::information(this, tr("Succès"), tr("Chambre ajoutée avec succès."));

        // Réinitialiser les champs
        ui->num_chambre->clear();
        ui->type_chambre->clear();
        ui->statut_chambre->clear();
        ui->equipement_chambre->clear();
        ui->prix_chambre->clear();
    }
}
