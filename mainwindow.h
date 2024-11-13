#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:

    Ui::MainWindow *ui;
    private slots:
    void ajouter_chambre_clicked();
    void modifier_chambre_clicked();
    void supprimer_chambre_clicked();

};
#endif // MAINWINDOW_H
