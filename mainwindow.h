#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGestionEquipes_clicked();
    void on_btnGestionEmployes_clicked();
    void on_btnGestionZones_clicked();
    void on_btnGestionPoubelles_clicked();
    void on_btnGestionMateriels_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
