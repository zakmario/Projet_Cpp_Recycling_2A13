#include "gestionzones.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Appliquer le style global
    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        app.setStyleSheet(style);
        styleFile.close();
    }
    
    GestionZones window;
    window.setWindowTitle("Smart Waste Management - Gestion des Zones");
    window.resize(1175, 695);
    window.show();
    
    return app.exec();
}
