#ifndef GESTIONZONES_H
#define GESTIONZONES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QInputDialog>

namespace Ui {
class GestionZones;
}

class GestionZones : public QWidget
{
    Q_OBJECT

public:
    explicit GestionZones(QWidget *parent = nullptr);
    ~GestionZones();
    
    // Initialisation
    void initDatabase();
    void setupTableView();
    void loadData();
    void updateStatistics();

private slots:
    // Fonctionnalités de base (CRUD)
    void on_btn_ajouter_clicked();
    void on_btn_modifier_clicked();
    void on_btn_supprimer_clicked();
    void on_btn_effacer_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    
    // Fonctionnalités avancées - Métiers basiques
    void on_btn_actualiser_clicked();
    void on_comboBox_filtre_currentIndexChanged(int index);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_lineEdit_recherche_textChanged(const QString &text);
    void on_btn_pdf_clicked();
    
    // Fonctionnalités avancées - Métiers innovants
    void on_btn_simulation_clicked();
    void on_btn_analyse_clicked();

private:
    Ui::GestionZones *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    
    // Méthodes utilitaires
    bool validateInput();
    void clearForm();
    void fillFormFromModel(int row);
    QString getTypeZoneIcon(const QString &type);
    QColor getTypeZoneColor(const QString &type);
    
    // Méthodes métiers
    void trierParType();
    void rechercherParAdresse(const QString &adresse);
    void genererRapportPDF();
    void afficherStatistiquesParType();
    
    // Méthodes innovantes
    void simulationAmeliorationEcologique();
    void analyseComparativeRecyclage();
    double calculerScoreEcologique(const QString &type, int surface, int nbPoubelles);
    QString genererRecommandations(const QString &type, int surface, int nbPoubelles);
};

#endif // GESTIONZONES_H
