/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_logo;
    QPushButton *btnGestionEquipes;
    QPushButton *btnGestionEmployes;
    QPushButton *btnGestionZones;
    QPushButton *btnGestionPoubelles;
    QPushButton *btnGestionMateriels;
    QStackedWidget *stackedWidget;
    QWidget *pageMateriels;
    QLabel *titre_materiels;
    QGroupBox *groupBox_form;
    QLabel *lbl_id;
    QLineEdit *lineEdit_id;
    QLabel *lbl_type;
    QLabel *lbl_quantite;
    QLabel *lbl_plaque;
    QLabel *lbl_km;
    QLineEdit *lineEdit_km;
    QLabel *lbl_etat;
    QLabel *lbl_achat;
    QPushButton *btn_ajouter;
    QPushButton *btn_modifier;
    QPushButton *btn_supprimer;
    QPushButton *btn_export_csv;
    QLineEdit *lineEdit_id_2;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_recherche;
    QPushButton *btn_rechercher;
    QPushButton *btn_actualiser;
    QTableView *tableView;
    QGroupBox *groupBox_stats;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 750);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #E8F5F3;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    border-image: url(:/background.jpg) 0 0 0 0 stretch stretch;\n"
"}"));
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(20, 15, 170, 45));
        label_logo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background-color: rgba(0, 128, 128, 180);\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"}"));
        label_logo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnGestionEquipes = new QPushButton(centralwidget);
        btnGestionEquipes->setObjectName("btnGestionEquipes");
        btnGestionEquipes->setGeometry(QRect(20, 75, 170, 50));
        btnGestionEquipes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(46, 125, 50, 240);\n"
"    border: 2px solid #2E7D32;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 12px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(76, 175, 80, 255);\n"
"    border: 2px solid #66BB6A;\n"
"}"));
        btnGestionEmployes = new QPushButton(centralwidget);
        btnGestionEmployes->setObjectName("btnGestionEmployes");
        btnGestionEmployes->setGeometry(QRect(20, 135, 170, 50));
        btnGestionEmployes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 150, 136, 220);\n"
"    border: 2px solid #00897B;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 12px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 137, 123, 255);\n"
"    border: 2px solid #4DB6AC;\n"
"}"));
        btnGestionZones = new QPushButton(centralwidget);
        btnGestionZones->setObjectName("btnGestionZones");
        btnGestionZones->setGeometry(QRect(20, 195, 170, 50));
        btnGestionZones->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 150, 136, 220);\n"
"    border: 2px solid #00897B;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 12px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 137, 123, 255);\n"
"    border: 2px solid #4DB6AC;\n"
"}"));
        btnGestionPoubelles = new QPushButton(centralwidget);
        btnGestionPoubelles->setObjectName("btnGestionPoubelles");
        btnGestionPoubelles->setGeometry(QRect(20, 255, 170, 50));
        btnGestionPoubelles->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 150, 136, 220);\n"
"    border: 2px solid #00897B;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 12px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 137, 123, 255);\n"
"    border: 2px solid #4DB6AC;\n"
"}"));
        btnGestionMateriels = new QPushButton(centralwidget);
        btnGestionMateriels->setObjectName("btnGestionMateriels");
        btnGestionMateriels->setGeometry(QRect(20, 315, 170, 50));
        btnGestionMateriels->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 150, 136, 220);\n"
"    border: 2px solid #00897B;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 12px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 137, 123, 255);\n"
"    border: 2px solid #4DB6AC;\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(205, 10, 1175, 695));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"    border-radius: 15px;\n"
"}"));
        pageMateriels = new QWidget();
        pageMateriels->setObjectName("pageMateriels");
        pageMateriels->setStyleSheet(QString::fromUtf8("QWidget#pageMateriels {\n"
"    background-color: transparent;\n"
"}"));
        titre_materiels = new QLabel(pageMateriels);
        titre_materiels->setObjectName("titre_materiels");
        titre_materiels->setGeometry(QRect(20, 8, 450, 45));
        titre_materiels->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #004D40;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    background-color: rgba(255, 255, 255, 200);\n"
"    border-radius: 12px;\n"
"    padding: 8px 15px;\n"
"}"));
        groupBox_form = new QGroupBox(pageMateriels);
        groupBox_form->setObjectName("groupBox_form");
        groupBox_form->setGeometry(QRect(20, 60, 400, 570));
        groupBox_form->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid rgba(0, 137, 123, 180);\n"
"    border-radius: 15px;\n"
"    margin-top: 12px;\n"
"    background-color: rgba(255, 255, 255, 40);\n"
"    padding-top: 15px;\n"
"    font-weight: bold;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 20px;\n"
"    padding: 0 15px;\n"
"    color: #004D40;\n"
"    background-color: rgba(255, 255, 255, 180);\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"}"));
        lbl_id = new QLabel(groupBox_form);
        lbl_id->setObjectName("lbl_id");
        lbl_id->setGeometry(QRect(20, 40, 110, 25));
        lbl_id->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lineEdit_id = new QLineEdit(groupBox_form);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(159, 35, 221, 38));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #26A69A;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    background-color: #FFFFFF;\n"
"    font-size: 13px;\n"
"    color: #004D40;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00897B;\n"
"    background-color: #E0F2F1;\n"
"}"));
        lbl_type = new QLabel(groupBox_form);
        lbl_type->setObjectName("lbl_type");
        lbl_type->setGeometry(QRect(20, 85, 110, 25));
        lbl_type->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lbl_quantite = new QLabel(groupBox_form);
        lbl_quantite->setObjectName("lbl_quantite");
        lbl_quantite->setGeometry(QRect(20, 130, 110, 25));
        lbl_quantite->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lbl_plaque = new QLabel(groupBox_form);
        lbl_plaque->setObjectName("lbl_plaque");
        lbl_plaque->setGeometry(QRect(10, 170, 121, 31));
        lbl_plaque->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lbl_km = new QLabel(groupBox_form);
        lbl_km->setObjectName("lbl_km");
        lbl_km->setGeometry(QRect(10, 220, 131, 25));
        lbl_km->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lineEdit_km = new QLineEdit(groupBox_form);
        lineEdit_km->setObjectName("lineEdit_km");
        lineEdit_km->setGeometry(QRect(159, 215, 221, 38));
        lineEdit_km->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #26A69A;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    background-color: #FFFFFF;\n"
"    font-size: 13px;\n"
"    color: #004D40;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00897B;\n"
"    background-color: #E0F2F1;\n"
"}"));
        lbl_etat = new QLabel(groupBox_form);
        lbl_etat->setObjectName("lbl_etat");
        lbl_etat->setGeometry(QRect(10, 250, 141, 51));
        lbl_etat->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        lbl_achat = new QLabel(groupBox_form);
        lbl_achat->setObjectName("lbl_achat");
        lbl_achat->setGeometry(QRect(20, 310, 110, 25));
        lbl_achat->setStyleSheet(QString::fromUtf8("color: #004D40; font-weight: bold; font-size: 13px; background: transparent;"));
        btn_ajouter = new QPushButton(groupBox_form);
        btn_ajouter->setObjectName("btn_ajouter");
        btn_ajouter->setGeometry(QRect(20, 450, 115, 45));
        btn_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43A047;\n"
"}"));
        btn_modifier = new QPushButton(groupBox_form);
        btn_modifier->setObjectName("btn_modifier");
        btn_modifier->setGeometry(QRect(145, 450, 115, 45));
        btn_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00897B;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #26A69A;\n"
"}"));
        btn_supprimer = new QPushButton(groupBox_form);
        btn_supprimer->setObjectName("btn_supprimer");
        btn_supprimer->setGeometry(QRect(270, 450, 115, 45));
        btn_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00695C;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00897B;\n"
"}"));
        btn_export_csv = new QPushButton(groupBox_form);
        btn_export_csv->setObjectName("btn_export_csv");
        btn_export_csv->setGeometry(QRect(120, 510, 175, 45));
        btn_export_csv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00897B;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #26A69A;\n"
"}"));
        lineEdit_id_2 = new QLineEdit(groupBox_form);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(159, 80, 221, 38));
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #26A69A;\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    background-color: #FFFFFF;\n"
"    font-size: 13px;\n"
"    color: #004D40;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00897B;\n"
"    background-color: #E0F2F1;\n"
"}"));
        comboBox = new QComboBox(groupBox_form);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 130, 221, 31));
        spinBox = new QSpinBox(groupBox_form);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(160, 170, 221, 31));
        comboBox_2 = new QComboBox(groupBox_form);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(160, 260, 221, 31));
        lineEdit_recherche = new QLineEdit(pageMateriels);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(440, 60, 181, 42));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #26A69A;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    background-color: rgba(255, 255, 255, 230);\n"
"    font-size: 13px;\n"
"    color: #004D40;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #00897B;\n"
"    background-color: #FFFFFF;\n"
"}"));
        btn_rechercher = new QPushButton(pageMateriels);
        btn_rechercher->setObjectName("btn_rechercher");
        btn_rechercher->setGeometry(QRect(760, 60, 120, 42));
        btn_rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43A047;\n"
"}"));
        btn_actualiser = new QPushButton(pageMateriels);
        btn_actualiser->setObjectName("btn_actualiser");
        btn_actualiser->setGeometry(QRect(1050, 60, 100, 42));
        btn_actualiser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32;\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43A047;\n"
"}"));
        tableView = new QTableView(pageMateriels);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(440, 115, 710, 410));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: rgba(255, 255, 255, 240);\n"
"    border: 2px solid #00897B;\n"
"    border-radius: 12px;\n"
"    gridline-color: #B2DFDB;\n"
"    color: #004D40;\n"
"    font-size: 13px;\n"
"}\n"
"QTableView::item {\n"
"    padding: 8px;\n"
"}\n"
"QTableView::item:selected {\n"
"    background-color: #26A69A;\n"
"    color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #00897B;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"}"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        groupBox_stats = new QGroupBox(pageMateriels);
        groupBox_stats->setObjectName("groupBox_stats");
        groupBox_stats->setGeometry(QRect(440, 540, 710, 90));
        groupBox_stats->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid rgba(0, 137, 123, 180);\n"
"    border-radius: 12px;\n"
"    margin-top: 10px;\n"
"    background-color: rgba(255, 255, 255, 40);\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 20px;\n"
"    padding: 0 15px;\n"
"    color: #004D40;\n"
"    background-color: rgba(255, 255, 255, 180);\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"}"));
        comboBox_3 = new QComboBox(pageMateriels);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(630, 65, 111, 31));
        comboBox_4 = new QComboBox(pageMateriels);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(900, 65, 131, 31));
        stackedWidget->addWidget(pageMateriels);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Waste Management - Gestion Intelligente des D\303\251chets", nullptr));
        label_logo->setText(QCoreApplication::translate("MainWindow", "\360\237\214\277 Smart Waste", nullptr));
        btnGestionEquipes->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 Gestion \303\211quipes", nullptr));
        btnGestionEmployes->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244 Gestion Employ\303\251s", nullptr));
        btnGestionZones->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Gestion Zones", nullptr));
        btnGestionPoubelles->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Gestion Poubelles", nullptr));
        btnGestionMateriels->setText(QCoreApplication::translate("MainWindow", "\360\237\232\233 Gestion Mat\303\251riels", nullptr));
        titre_materiels->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 Gestion des \303\251quipes", nullptr));
        groupBox_form->setTitle(QCoreApplication::translate("MainWindow", "Informations de l'\303\251quipe", nullptr));
        lbl_id->setText(QCoreApplication::translate("MainWindow", "ID \303\251quipe ", nullptr));
        lbl_type->setText(QCoreApplication::translate("MainWindow", "nom \303\251quipe", nullptr));
        lbl_quantite->setText(QCoreApplication::translate("MainWindow", "specialit\303\251", nullptr));
        lbl_plaque->setText(QCoreApplication::translate("MainWindow", "nombre employ\303\251", nullptr));
        lbl_km->setText(QCoreApplication::translate("MainWindow", "responsable \303\251quipe", nullptr));
        lbl_etat->setText(QCoreApplication::translate("MainWindow", "ressources assign\303\251es", nullptr));
        lbl_achat->setText(QString());
        btn_ajouter->setText(QCoreApplication::translate("MainWindow", "\342\234\232 Ajouter", nullptr));
        btn_modifier->setText(QCoreApplication::translate("MainWindow", "\342\234\216 Modifier", nullptr));
        btn_supprimer->setText(QCoreApplication::translate("MainWindow", "\342\234\226 Supprimer", nullptr));
        btn_export_csv->setText(QCoreApplication::translate("MainWindow", "\360\237\223\244 Export PDF", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "-- S\303\251lectionner --", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Collecte d\303\251chets m\303\251nagers", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Collecte d\303\251chets recyclables", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Maintenance des bacs", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Nettoyage urbain", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "-- S\303\251lectionner --", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Camion de collecte", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Camionnette", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Bacs roulants", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "\303\211quipements de protection", nullptr));

        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Rechercher...", nullptr));
        btn_rechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        btn_actualiser->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
        groupBox_stats->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Par ID", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Par Nom", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Par Sp\303\251cialit\303\251", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "Par Responsable", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Aucun tri", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Par Sp\303\251cialit\303\251", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "Par Nom (A-Z)", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "Par Nb. Employ\303\251s", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("MainWindow", "Par Score \342\255\220", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
