#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDate>
#include <QTableWidgetItem>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Navigation: connect sidebar buttons to page switching
    connect(ui->btnNavDashboard, &QPushButton::clicked, this, [this]() { navigateTo(0); });
    connect(ui->btnNavPoubelles, &QPushButton::clicked, this, [this]() { navigateTo(1); });
    connect(ui->btnNavStats,     &QPushButton::clicked, this, [this]() { navigateTo(2); });
    connect(ui->btnNavHistorique,&QPushButton::clicked, this, [this]() { navigateTo(3); });

    // Set initial page
    navigateTo(0);

    // Fill tables with sample data
    fillSampleData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::navigateTo(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

    // Update header title
    static const QStringList titles = {
        "Tableau de Bord",
        "Gestion des Poubelles",
        "Statistiques",
        "Historique"
    };
    if (index >= 0 && index < titles.size())
        ui->headerTitle->setText(titles[index]);

    // Update checked state on nav buttons
    QList<QPushButton*> navBtns = {
        ui->btnNavDashboard,
        ui->btnNavPoubelles,
        ui->btnNavStats,
        ui->btnNavHistorique
    };
    for (int i = 0; i < navBtns.size(); ++i) {
        navBtns[i]->setChecked(i == index);
    }
}

void MainWindow::fillSampleData()
{
    // ===== Table Poubelles (Page 1) =====
    struct PoubelleData {
        QString adresse, type, capacite, niveau, etat, collecte;
    };
    QList<PoubelleData> data = {
        {"Av. Habib Bourguiba, Tunis",    "Organique",  "240", "85", "Fonctionnel",     "2025-06-10"},
        {"Rue de Marseille, Tunis",       "Plastique",  "360", "45", "Fonctionnel",     "2025-06-09"},
        {"Av. de la Liberté, Tunis",      "Verre",      "120", "90", "Pleine",          "2025-06-08"},
        {"Rue Ibn Khaldoun, Tunis",       "Papier",     "240", "30", "Fonctionnel",     "2025-06-11"},
        {"Place Barcelone, Tunis",        "Métal",      "120", "70", "Fonctionnel",     "2025-06-07"},
        {"Av. Mohamed V, Tunis",          "Mixte",      "660", "55", "En maintenance",  "2025-06-06"},
        {"Rue de Rome, Tunis",            "Organique",  "240", "95", "Pleine",          "2025-06-05"},
        {"Rue Charles de Gaulle, Tunis",  "Plastique",  "360", "20", "Fonctionnel",     "2025-06-10"},
        {"Av. Farhat Hached, Sousse",     "Organique",  "240", "60", "Fonctionnel",     "2025-06-09"},
        {"Rue Ali Belhouane, Sfax",       "Verre",      "120", "80", "Pleine",          "2025-06-08"},
        {"Av. Taieb Mehiri, Sousse",      "Papier",     "240", "40", "Fonctionnel",     "2025-06-07"},
        {"Centre-ville, Monastir",        "Organique",  "360", "75", "Fonctionnel",     "2025-06-06"},
        {"Zone Industrielle, Sfax",       "Métal",      "660", "50", "En maintenance",  "2025-06-05"},
        {"Médina, Tunis",                 "Mixte",      "120", "88", "Pleine",          "2025-06-04"},
        {"Corniche, Bizerte",             "Organique",  "240", "15", "Fonctionnel",     "2025-06-11"},
        {"Rue de la Kasbah, Tunis",       "Plastique",  "240", "35", "Fonctionnel",     "2025-06-10"},
        {"Av. Jugurtha, Tunis",           "Papier",     "120", "92", "Pleine",          "2025-06-03"},
        {"Port de Pêche, Mahdia",         "Verre",      "240", "10", "En panne",        "2025-06-01"},
    };

    ui->tablePoubelles->setRowCount(data.size());
    for (int r = 0; r < data.size(); ++r) {
        const auto &d = data[r];
        ui->tablePoubelles->setItem(r, 0, new QTableWidgetItem(d.adresse));
        ui->tablePoubelles->setItem(r, 1, new QTableWidgetItem(d.type));
        ui->tablePoubelles->setItem(r, 2, new QTableWidgetItem(d.capacite));
        ui->tablePoubelles->setItem(r, 3, new QTableWidgetItem(d.niveau));
        ui->tablePoubelles->setItem(r, 4, new QTableWidgetItem(d.etat));
        ui->tablePoubelles->setItem(r, 5, new QTableWidgetItem(d.collecte));
        ui->tablePoubelles->setRowHeight(r, 44);
    }
    ui->tablePoubelles->horizontalHeader()->setStretchLastSection(true);
    ui->tablePoubelles->setColumnWidth(0, 250);
    ui->tablePoubelles->setColumnWidth(1, 120);
    ui->tablePoubelles->setColumnWidth(2, 110);
    ui->tablePoubelles->setColumnWidth(3, 100);
    ui->tablePoubelles->setColumnWidth(4, 130);

    // ===== Table Recent (Dashboard) =====
    struct RecentData {
        QString date, action, poubelle, details;
    };
    QList<RecentData> recent = {
        {"2025-06-11", "Collecte",     "Av. Habib Bourguiba",  "Niveau ramené à 0%"},
        {"2025-06-11", "Ajout",        "Corniche, Bizerte",    "Nouvelle poubelle organique"},
        {"2025-06-10", "Modification", "Rue de Marseille",     "Capacité: 240L → 360L"},
        {"2025-06-10", "Collecte",     "Rue Charles de Gaulle","Niveau ramené à 0%"},
        {"2025-06-09", "Collecte",     "Av. Farhat Hached",    "Niveau ramené à 0%"},
    };
    ui->tableRecent->setRowCount(recent.size());
    for (int r = 0; r < recent.size(); ++r) {
        const auto &d = recent[r];
        ui->tableRecent->setItem(r, 0, new QTableWidgetItem(d.date));
        ui->tableRecent->setItem(r, 1, new QTableWidgetItem(d.action));
        ui->tableRecent->setItem(r, 2, new QTableWidgetItem(d.poubelle));
        ui->tableRecent->setItem(r, 3, new QTableWidgetItem(d.details));
        ui->tableRecent->setRowHeight(r, 40);
    }
    ui->tableRecent->setColumnWidth(0, 110);
    ui->tableRecent->setColumnWidth(1, 120);
    ui->tableRecent->setColumnWidth(2, 200);

    // ===== Table Historique (Page 3) =====
    QList<RecentData> hist = {
        {"2025-06-11", "Collecte",     "Av. Habib Bourguiba, Tunis",  "Niveau: 85% → 0%"},
        {"2025-06-11", "Ajout",        "Corniche, Bizerte",           "Organique, 240L"},
        {"2025-06-10", "Modification", "Rue de Marseille, Tunis",     "Capacité: 240L → 360L"},
        {"2025-06-10", "Collecte",     "Rue Charles de Gaulle, Tunis","Niveau: 65% → 0%"},
        {"2025-06-09", "Collecte",     "Av. Farhat Hached, Sousse",   "Niveau: 60% → 0%"},
        {"2025-06-09", "Modification", "Zone Industrielle, Sfax",     "État: Fonctionnel → Maintenance"},
        {"2025-06-08", "Collecte",     "Av. de la Liberté, Tunis",    "Niveau: 90% → 0%"},
        {"2025-06-08", "Suppression",  "Ancienne poubelle, Gabès",    "Poubelle retirée"},
        {"2025-06-07", "Collecte",     "Place Barcelone, Tunis",      "Niveau: 70% → 0%"},
        {"2025-06-06", "Modification", "Av. Mohamed V, Tunis",        "État: Fonctionnel → Maintenance"},
    };
    ui->tableHistorique->setRowCount(hist.size());
    for (int r = 0; r < hist.size(); ++r) {
        const auto &d = hist[r];
        ui->tableHistorique->setItem(r, 0, new QTableWidgetItem(d.date));
        ui->tableHistorique->setItem(r, 1, new QTableWidgetItem(d.action));
        ui->tableHistorique->setItem(r, 2, new QTableWidgetItem(d.poubelle));
        ui->tableHistorique->setItem(r, 3, new QTableWidgetItem(d.details));
        ui->tableHistorique->setRowHeight(r, 40);
    }
    ui->tableHistorique->setColumnWidth(0, 110);
    ui->tableHistorique->setColumnWidth(1, 120);
    ui->tableHistorique->setColumnWidth(2, 250);
}
