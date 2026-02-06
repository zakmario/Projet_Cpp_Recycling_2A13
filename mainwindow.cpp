#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Les autres boutons ne font rien
void MainWindow::on_btnGestionEquipes_clicked() { }
void MainWindow::on_btnGestionEmployes_clicked() { }
void MainWindow::on_btnGestionZones_clicked() { }
void MainWindow::on_btnGestionPoubelles_clicked() { }

void MainWindow::on_btnGestionMateriels_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
