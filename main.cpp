#include "mainwindow.h"

#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Police d'application
    QFont appFont("Segoe UI", 10);
    appFont.setStyleStrategy(QFont::PreferAntialias);
    a.setFont(appFont);

    a.setApplicationName("EcoGest");
    a.setOrganizationName("EcoGest");
    a.setApplicationVersion("2.0");

    MainWindow w;
    w.show();
    return a.exec();
}
