#include "gestionzones.h"
#include "ui_gestion_zones.h"
#include <QDebug>
#include <QDateTime>
#include <QTextDocument>

GestionZones::GestionZones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestionZones)
{
    ui->setupUi(this);
    initDatabase();
    setupTableView();
    loadData();
    updateStatistics();
}

GestionZones::~GestionZones()
{
    delete ui;
    if(db.isOpen()) {
        db.close();
    }
}

// ============= INITIALISATION =============

void GestionZones::initDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gestion_dechets.db");
    
    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données: " + db.lastError().text());
        return;
    }
    
    // Créer la table si elle n'existe pas
    QSqlQuery query;
    QString createTable = "CREATE TABLE IF NOT EXISTS zones ("
                         "idZone TEXT PRIMARY KEY, "
                         "nomZone TEXT NOT NULL, "
                         "adresse TEXT NOT NULL, "
                         "surface REAL NOT NULL, "
                         "nombrePoubelles INTEGER NOT NULL, "
                         "typeZone TEXT NOT NULL, "
                         "statut TEXT NOT NULL)";
    
    if (!query.exec(createTable)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la création de la table: " + query.lastError().text());
    }
}

void GestionZones::setupTableView()
{
    model = new QSqlTableModel(this, db);
    model->setTable("zones");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    
    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, "ID Zone");
    model->setHeaderData(1, Qt::Horizontal, "Nom Zone");
    model->setHeaderData(2, Qt::Horizontal, "Adresse");
    model->setHeaderData(3, Qt::Horizontal, "Surface (m²)");
    model->setHeaderData(4, Qt::Horizontal, "Nb Poubelles");
    model->setHeaderData(5, Qt::Horizontal, "Type");
    model->setHeaderData(6, Qt::Horizontal, "Statut");
    
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void GestionZones::loadData()
{
    model->select();
    updateStatistics();
}

void GestionZones::updateStatistics()
{
    QSqlQuery query(db);
    
    // Total des zones
    query.exec("SELECT COUNT(*) FROM zones");
    int total = 0;
    if (query.next()) {
        total = query.value(0).toInt();
    }
    ui->lbl_stat_total->setText(QString("📍 Total Zones: %1").arg(total));
    
    // Par type
    query.exec("SELECT COUNT(*) FROM zones WHERE typeZone='Résidentielle'");
    if (query.next()) {
        ui->lbl_stat_residentielle->setText(QString("🏘️ Résid.: %1").arg(query.value(0).toInt()));
    }
    
    query.exec("SELECT COUNT(*) FROM zones WHERE typeZone='Commerciale'");
    if (query.next()) {
        ui->lbl_stat_commerciale->setText(QString("🏢 Comm.: %1").arg(query.value(0).toInt()));
    }
    
    query.exec("SELECT COUNT(*) FROM zones WHERE typeZone='Industrielle'");
    if (query.next()) {
        ui->lbl_stat_industrielle->setText(QString("🏭 Indust.: %1").arg(query.value(0).toInt()));
    }
    
    query.exec("SELECT COUNT(*) FROM zones WHERE typeZone IN ('Scolaire', 'Hospitalière', 'Autre')");
    if (query.next()) {
        ui->lbl_stat_autre->setText(QString("📌 Autres: %1").arg(query.value(0).toInt()));
    }
}

// ============= FONCTIONNALITÉS DE BASE (CRUD) =============

void GestionZones::on_btn_ajouter_clicked()
{
    if (!validateInput()) {
        return;
    }
    
    QString idZone = ui->lineEdit_idZone->text().trimmed();
    
    // Vérifier si l'ID existe déjà
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT idZone FROM zones WHERE idZone = ?");
    checkQuery.addBindValue(idZone);
    
    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Une zone avec cet ID existe déjà!");
        return;
    }
    
    // Insérer la nouvelle zone
    QSqlQuery query(db);
    query.prepare("INSERT INTO zones (idZone, nomZone, adresse, surface, nombrePoubelles, typeZone, statut) "
                 "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(idZone);
    query.addBindValue(ui->lineEdit_nomZone->text().trimmed());
    query.addBindValue(ui->lineEdit_adresse->text().trimmed());
    query.addBindValue(ui->spinBox_surface->value());
    query.addBindValue(ui->spinBox_nombrePoubelles->value());
    query.addBindValue(ui->comboBox_typeZone->currentText());
    query.addBindValue(ui->comboBox_statut->currentText());
    
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Zone ajoutée avec succès!");
        loadData();
        clearForm();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout: " + query.lastError().text());
    }
}

void GestionZones::on_btn_modifier_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une zone à modifier!");
        return;
    }
    
    if (!validateInput()) {
        return;
    }
    
    QString idZone = ui->lineEdit_idZone->text().trimmed();
    
    QSqlQuery query(db);
    query.prepare("UPDATE zones SET nomZone=?, adresse=?, surface=?, nombrePoubelles=?, typeZone=?, statut=? "
                 "WHERE idZone=?");
    query.addBindValue(ui->lineEdit_nomZone->text().trimmed());
    query.addBindValue(ui->lineEdit_adresse->text().trimmed());
    query.addBindValue(ui->spinBox_surface->value());
    query.addBindValue(ui->spinBox_nombrePoubelles->value());
    query.addBindValue(ui->comboBox_typeZone->currentText());
    query.addBindValue(ui->comboBox_statut->currentText());
    query.addBindValue(idZone);
    
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Zone modifiée avec succès!");
        loadData();
        clearForm();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification: " + query.lastError().text());
    }
}

void GestionZones::on_btn_supprimer_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une zone à supprimer!");
        return;
    }
    
    QString idZone = model->data(model->index(index.row(), 0)).toString();
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, 
        "Confirmation", 
        QString("Êtes-vous sûr de vouloir supprimer la zone %1?").arg(idZone),
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        QSqlQuery query(db);
        query.prepare("DELETE FROM zones WHERE idZone = ?");
        query.addBindValue(idZone);
        
        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Zone supprimée avec succès!");
            loadData();
            clearForm();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + query.lastError().text());
        }
    }
}

void GestionZones::on_btn_effacer_clicked()
{
    clearForm();
}

void GestionZones::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        fillFormFromModel(index.row());
    }
}

// ============= FONCTIONNALITÉS AVANCÉES - MÉTIERS BASIQUES =============

void GestionZones::on_btn_actualiser_clicked()
{
    loadData();
    ui->lineEdit_recherche->clear();
    ui->comboBox_filtre->setCurrentIndex(0);
    ui->comboBox_tri->setCurrentIndex(0);
    QMessageBox::information(this, "Info", "Données actualisées!");
}

void GestionZones::on_comboBox_filtre_currentIndexChanged(int index)
{
    QString filter = "";
    
    if (index > 0) {
        QString type = ui->comboBox_filtre->currentText();
        filter = QString("typeZone = '%1'").arg(type);
    }
    
    model->setFilter(filter);
    model->select();
    updateStatistics();
}

void GestionZones::on_comboBox_tri_currentIndexChanged(int index)
{
    QString sortColumn;
    
    switch (index) {
        case 0: // Trier par Type
            sortColumn = "typeZone";
            break;
        case 1: // Trier par Surface
            sortColumn = "surface";
            break;
        case 2: // Trier par Poubelles
            sortColumn = "nombrePoubelles";
            break;
        case 3: // Trier par Statut
            sortColumn = "statut";
            break;
        default:
            sortColumn = "idZone";
    }
    
    model->setSort(model->fieldIndex(sortColumn), Qt::AscendingOrder);
    model->select();
}

void GestionZones::on_lineEdit_recherche_textChanged(const QString &text)
{
    if (text.isEmpty()) {
        model->setFilter("");
    } else {
        QString filter = QString("adresse LIKE '%%1%'").arg(text);
        model->setFilter(filter);
    }
    model->select();
}

void GestionZones::on_btn_pdf_clicked()
{
    genererRapportPDF();
}

void GestionZones::genererRapportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le rapport", 
                                                    QString("rapport_zones_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")),
                                                    "PDF Files (*.pdf)");
    
    if (fileName.isEmpty()) {
        return;
    }
    
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize::A4);
    printer.setPageMargins(QMarginsF(20, 20, 20, 20), QPageLayout::Millimeter);
    
    QTextDocument doc;
    QString html = "<html><head><style>"
                  "body { font-family: Arial, sans-serif; }"
                  "h1 { color: #00897B; text-align: center; border-bottom: 3px solid #26A69A; padding-bottom: 10px; }"
                  "h2 { color: #004D40; margin-top: 20px; }"
                  "table { width: 100%; border-collapse: collapse; margin-top: 15px; }"
                  "th { background-color: #00897B; color: white; padding: 12px; text-align: left; }"
                  "td { border: 1px solid #B2DFDB; padding: 10px; }"
                  "tr:nth-child(even) { background-color: #E0F2F1; }"
                  ".stats { background-color: #E8F5F3; padding: 15px; border-radius: 8px; margin: 20px 0; }"
                  ".footer { text-align: center; color: #607D8B; font-size: 10pt; margin-top: 30px; }"
                  "</style></head><body>";
    
    html += "<h1>🌿 Rapport de Gestion des Zones</h1>";
    html += QString("<p style='text-align: center; color: #607D8B;'>Généré le %1</p>")
            .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy à hh:mm"));
    
    // Statistiques
    html += "<div class='stats'>";
    html += "<h2>📊 Statistiques Globales</h2>";
    
    QSqlQuery statsQuery(db);
    statsQuery.exec("SELECT COUNT(*) as total, "
                   "SUM(CASE WHEN typeZone='Résidentielle' THEN 1 ELSE 0 END) as resid, "
                   "SUM(CASE WHEN typeZone='Commerciale' THEN 1 ELSE 0 END) as comm, "
                   "SUM(CASE WHEN typeZone='Industrielle' THEN 1 ELSE 0 END) as indust, "
                   "SUM(surface) as surfaceTotale, "
                   "SUM(nombrePoubelles) as poubellesTotales "
                   "FROM zones");
    
    if (statsQuery.next()) {
        html += "<ul>";
        html += QString("<li><b>Total de zones:</b> %1</li>").arg(statsQuery.value(0).toInt());
        html += QString("<li><b>Zones résidentielles:</b> %1</li>").arg(statsQuery.value(1).toInt());
        html += QString("<li><b>Zones commerciales:</b> %1</li>").arg(statsQuery.value(2).toInt());
        html += QString("<li><b>Zones industrielles:</b> %1</li>").arg(statsQuery.value(3).toInt());
        html += QString("<li><b>Surface totale couverte:</b> %1 m²</li>").arg(statsQuery.value(4).toDouble(), 0, 'f', 2);
        html += QString("<li><b>Nombre total de poubelles:</b> %1</li>").arg(statsQuery.value(5).toInt());
        html += "</ul>";
    }
    html += "</div>";
    
    // Tableau des zones
    html += "<h2>📋 Liste des Zones</h2>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Nom</th><th>Adresse</th><th>Surface (m²)</th><th>Poubelles</th><th>Type</th><th>Statut</th></tr>";
    
    QSqlQuery query("SELECT * FROM zones ORDER BY typeZone, idZone", db);
    while (query.next()) {
        html += "<tr>";
        html += QString("<td>%1</td>").arg(query.value(0).toString());
        html += QString("<td>%1</td>").arg(query.value(1).toString());
        html += QString("<td>%1</td>").arg(query.value(2).toString());
        html += QString("<td>%1</td>").arg(query.value(3).toDouble(), 0, 'f', 2);
        html += QString("<td>%1</td>").arg(query.value(4).toInt());
        html += QString("<td>%1</td>").arg(query.value(5).toString());
        html += QString("<td>%1</td>").arg(query.value(6).toString());
        html += "</tr>";
    }
    
    html += "</table>";
    html += "<div class='footer'>© 2025 Smart Waste Management System - Gestion Intelligente des Déchets</div>";
    html += "</body></html>";
    
    doc.setHtml(html);
    doc.print(&printer);
    
    QMessageBox::information(this, "Succès", QString("Rapport PDF généré avec succès!\n%1").arg(fileName));
}

// ============= FONCTIONNALITÉS INNOVANTES =============

void GestionZones::on_btn_simulation_clicked()
{
    simulationAmeliorationEcologique();
}

void GestionZones::simulationAmeliorationEcologique()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une zone pour la simulation!");
        return;
    }
    
    int row = index.row();
    QString idZone = model->data(model->index(row, 0)).toString();
    QString nomZone = model->data(model->index(row, 1)).toString();
    QString typeZone = model->data(model->index(row, 5)).toString();
    double surface = model->data(model->index(row, 3)).toDouble();
    int nbPoubelles = model->data(model->index(row, 4)).toInt();
    
    // Calcul du score écologique actuel
    double scoreActuel = calculerScoreEcologique(typeZone, surface, nbPoubelles);
    
    // Simulation d'améliorations
    int nbPoubellesOptimal = qMax(int(surface / 100), 5); // 1 poubelle par 100m²
    double scoreAmeliore = calculerScoreEcologique(typeZone, surface, nbPoubellesOptimal);
    double amelioration = ((scoreAmeliore - scoreActuel) / scoreActuel) * 100;
    
    // Recommandations
    QString recommendations = genererRecommandations(typeZone, surface, nbPoubelles);
    
    QString message = QString("<html><body style='font-family: Arial;'>"
                            "<h2 style='color: #00897B;'>🌱 Simulation d'Amélioration Écologique</h2>"
                            "<p><b>Zone:</b> %1 (%2)</p>"
                            "<p><b>Type:</b> %3</p>"
                            "<p><b>Surface:</b> %4 m²</p>"
                            "<hr>"
                            "<h3 style='color: #2E7D32;'>📊 Analyse Actuelle</h3>"
                            "<p><b>Nombre de poubelles actuel:</b> %5</p>"
                            "<p><b>Score écologique actuel:</b> %6/100</p>"
                            "<hr>"
                            "<h3 style='color: #43A047;'>✨ Scénario Optimisé</h3>"
                            "<p><b>Nombre de poubelles recommandé:</b> %7</p>"
                            "<p><b>Score écologique projeté:</b> %8/100</p>"
                            "<p><b>Amélioration potentielle:</b> <span style='color: %9; font-weight: bold;'>%10%</span></p>"
                            "<hr>"
                            "<h3 style='color: #1B5E20;'>💡 Recommandations</h3>"
                            "%11"
                            "</body></html>")
                     .arg(nomZone).arg(idZone).arg(typeZone).arg(surface, 0, 'f', 2)
                     .arg(nbPoubelles).arg(scoreActuel, 0, 'f', 1)
                     .arg(nbPoubellesOptimal).arg(scoreAmeliore, 0, 'f', 1)
                     .arg(amelioration > 0 ? "#2E7D32" : "#D32F2F")
                     .arg(amelioration > 0 ? "+" : "").arg(amelioration, 0, 'f', 1)
                     .arg(recommendations);
    
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Simulation Écologique");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void GestionZones::on_btn_analyse_clicked()
{
    analyseComparativeRecyclage();
}

void GestionZones::analyseComparativeRecyclage()
{
    QSqlQuery query(db);
    query.exec("SELECT typeZone, COUNT(*) as nombre, AVG(nombrePoubelles) as moyPoubelles, "
              "SUM(surface) as surfaceTotale FROM zones GROUP BY typeZone");
    
    QString analyse = "<html><body style='font-family: Arial;'>"
                     "<h2 style='color: #00897B;'>📊 Analyse Comparative des Performances de Recyclage</h2>"
                     "<p style='color: #607D8B;'><i>Comparaison des performances par type de zone</i></p><hr>";
    
    struct ZonePerf {
        QString type;
        int nombre;
        double moyPoubelles;
        double surface;
        double ratio;
        double score;
    };
    
    QVector<ZonePerf> performances;
    
    while (query.next()) {
        ZonePerf perf;
        perf.type = query.value(0).toString();
        perf.nombre = query.value(1).toInt();
        perf.moyPoubelles = query.value(2).toDouble();
        perf.surface = query.value(3).toDouble();
        perf.ratio = perf.surface > 0 ? perf.moyPoubelles / (perf.surface / 1000.0) : 0;
        perf.score = calculerScoreEcologique(perf.type, perf.surface / perf.nombre, perf.moyPoubelles);
        performances.append(perf);
    }
    
    // Trier par score décroissant
    std::sort(performances.begin(), performances.end(), 
              [](const ZonePerf &a, const ZonePerf &b) { return a.score > b.score; });
    
    for (int i = 0; i < performances.size(); ++i) {
        const ZonePerf &perf = performances[i];
        QString medal = i == 0 ? "🥇" : (i == 1 ? "🥈" : (i == 2 ? "🥉" : "📌"));
        QString color = i == 0 ? "#2E7D32" : (i == 1 ? "#F57C00" : "#1565C0");
        
        analyse += QString("<div style='background-color: #E8F5F3; padding: 15px; margin: 10px 0; border-left: 5px solid %1; border-radius: 5px;'>")
                  .arg(color);
        analyse += QString("<h3 style='color: %1;'>%2 Type: %3</h3>").arg(color).arg(medal).arg(perf.type);
        analyse += QString("<ul>");
        analyse += QString("<li><b>Nombre de zones:</b> %1</li>").arg(perf.nombre);
        analyse += QString("<li><b>Surface totale:</b> %1 m²</li>").arg(perf.surface, 0, 'f', 0);
        analyse += QString("<li><b>Moyenne de poubelles:</b> %1</li>").arg(perf.moyPoubelles, 0, 'f', 1);
        analyse += QString("<li><b>Ratio poubelles/1000m²:</b> %1</li>").arg(perf.ratio, 0, 'f', 2);
        analyse += QString("<li><b>Score de performance:</b> <span style='color: %1; font-weight: bold;'>%2/100</span></li>")
                  .arg(color).arg(perf.score, 0, 'f', 1);
        analyse += "</ul></div>";
    }
    
    analyse += "<hr><h3 style='color: #1B5E20;'>🎯 Conclusions</h3><ul>";
    
    if (!performances.isEmpty()) {
        analyse += QString("<li>Le type <b>%1</b> présente les meilleures performances avec un score de %2/100</li>")
                  .arg(performances[0].type).arg(performances[0].score, 0, 'f', 1);
        
        if (performances.size() > 1) {
            analyse += QString("<li>Amélioration potentielle pour le type <b>%1</b> (score: %2/100)</li>")
                      .arg(performances.last().type).arg(performances.last().score, 0, 'f', 1);
        }
        
        double moyenneGlobale = 0;
        for (const auto &perf : performances) {
            moyenneGlobale += perf.score;
        }
        moyenneGlobale /= performances.size();
        analyse += QString("<li>Score moyen global: <b>%1/100</b></li>").arg(moyenneGlobale, 0, 'f', 1);
    }
    
    analyse += "</ul></body></html>";
    
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Analyse Comparative");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(analyse);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

double GestionZones::calculerScoreEcologique(const QString &type, int surface, int nbPoubelles)
{
    double score = 50.0; // Score de base
    
    // Bonus selon le type de zone
    if (type == "Résidentielle") score += 15;
    else if (type == "Commerciale") score += 10;
    else if (type == "Industrielle") score += 5;
    else if (type == "Scolaire") score += 12;
    else if (type == "Hospitalière") score += 8;
    
    // Ratio poubelles/surface (optimal: 1 poubelle / 100m²)
    double ratioOptimal = surface / 100.0;
    double ratioActuel = nbPoubelles;
    double ecartRatio = qAbs(ratioActuel - ratioOptimal) / qMax(ratioOptimal, 1.0);
    
    if (ecartRatio < 0.2) score += 20; // Très bon
    else if (ecartRatio < 0.5) score += 10; // Bon
    else if (ecartRatio < 1.0) score += 5; // Acceptable
    // Sinon, pas de bonus
    
    // Bonus pour nombre suffisant de poubelles
    if (nbPoubelles >= 5) score += 10;
    else if (nbPoubelles >= 3) score += 5;
    
    return qMin(100.0, qMax(0.0, score));
}

QString GestionZones::genererRecommandations(const QString &type, int surface, int nbPoubelles)
{
    QString reco = "<ul style='color: #004D40;'>";
    
    int optimal = qMax(int(surface / 100), 5);
    
    if (nbPoubelles < optimal) {
        reco += QString("<li><b style='color: #D32F2F;'>⚠️ Augmenter le nombre de poubelles:</b> "
                       "Passer de %1 à %2 poubelles (+%3)</li>")
               .arg(nbPoubelles).arg(optimal).arg(optimal - nbPoubelles);
    } else if (nbPoubelles > optimal * 1.5) {
        reco += QString("<li><b style='color: #F57C00;'>💡 Optimiser la distribution:</b> "
                       "Réduire à %1 poubelles pour éviter le surdimensionnement</li>")
               .arg(optimal);
    } else {
        reco += "<li><b style='color: #2E7D32;'>✅ Nombre de poubelles optimal</b></li>";
    }
    
    if (type == "Résidentielle") {
        reco += "<li>Mettre en place un système de tri sélectif avec 3 conteneurs minimum</li>";
        reco += "<li>Organiser des campagnes de sensibilisation mensuelles</li>";
    } else if (type == "Commerciale") {
        reco += "<li>Installer des bacs de tri pour papier/carton (recyclage commercial)</li>";
        reco += "<li>Créer des partenariats avec des entreprises de recyclage</li>";
    } else if (type == "Industrielle") {
        reco += "<li>Mettre en place une gestion des déchets dangereux</li>";
        reco += "<li>Optimiser le traitement des déchets de production</li>";
    }
    
    reco += "<li>Installer des panneaux d'information sur le recyclage</li>";
    reco += "<li>Prévoir un calendrier de collecte optimisé</li>";
    reco += "</ul>";
    
    return reco;
}

// ============= MÉTHODES UTILITAIRES =============

bool GestionZones::validateInput()
{
    if (ui->lineEdit_idZone->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir l'ID de la zone!");
        return false;
    }
    
    if (ui->lineEdit_nomZone->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir le nom de la zone!");
        return false;
    }
    
    if (ui->lineEdit_adresse->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir l'adresse de la zone!");
        return false;
    }
    
    if (ui->spinBox_surface->value() <= 0) {
        QMessageBox::warning(this, "Validation", "La surface doit être supérieure à 0!");
        return false;
    }
    
    return true;
}

void GestionZones::clearForm()
{
    ui->lineEdit_idZone->clear();
    ui->lineEdit_nomZone->clear();
    ui->lineEdit_adresse->clear();
    ui->spinBox_surface->setValue(0);
    ui->spinBox_nombrePoubelles->setValue(0);
    ui->comboBox_typeZone->setCurrentIndex(0);
    ui->comboBox_statut->setCurrentIndex(0);
    ui->lineEdit_idZone->setFocus();
}

void GestionZones::fillFormFromModel(int row)
{
    ui->lineEdit_idZone->setText(model->data(model->index(row, 0)).toString());
    ui->lineEdit_nomZone->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_adresse->setText(model->data(model->index(row, 2)).toString());
    ui->spinBox_surface->setValue(model->data(model->index(row, 3)).toDouble());
    ui->spinBox_nombrePoubelles->setValue(model->data(model->index(row, 4)).toInt());
    
    QString type = model->data(model->index(row, 5)).toString();
    int typeIndex = ui->comboBox_typeZone->findText(type);
    if (typeIndex >= 0) {
        ui->comboBox_typeZone->setCurrentIndex(typeIndex);
    }
    
    QString statut = model->data(model->index(row, 6)).toString();
    int statutIndex = ui->comboBox_statut->findText(statut);
    if (statutIndex >= 0) {
        ui->comboBox_statut->setCurrentIndex(statutIndex);
    }
}
