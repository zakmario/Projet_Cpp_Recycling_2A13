# 🔗 Guide d'Intégration dans le Projet Principal

## Intégrer le module Gestion des Zones dans GestionFinal2

Si vous souhaitez ajouter ce module à votre projet principal existant (celui avec mainwindow), suivez ces étapes :

### Méthode 1 : Intégration comme Page dans le StackedWidget

#### Étape 1 : Copier les fichiers dans votre projet

Copiez ces fichiers dans le dossier de votre projet `GestionFinal2` :
```
gestionzones.h
gestionzones.cpp
gestion_zones.ui
```

#### Étape 2 : Modifier votre fichier .pro

Ajoutez ces lignes dans `GestionFinal2.pro` :

```qmake
SOURCES += \
    gestionzones.cpp \
    # ... vos autres fichiers

HEADERS += \
    gestionzones.h \
    # ... vos autres fichiers

FORMS += \
    gestion_zones.ui \
    # ... vos autres fichiers
```

#### Étape 3 : Modifier mainwindow.h

Ajoutez l'include et la variable membre :

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestionzones.h"  // ← AJOUTER CETTE LIGNE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGestionZones_clicked();  // ← AJOUTER CETTE LIGNE

private:
    Ui::MainWindow *ui;
    GestionZones *gestionZonesWidget;  // ← AJOUTER CETTE LIGNE
};

#endif // MAINWINDOW_H
```

#### Étape 4 : Modifier mainwindow.cpp

Ajoutez l'initialisation et la connexion :

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Créer et ajouter le widget GestionZones au StackedWidget
    gestionZonesWidget = new GestionZones(this);
    ui->stackedWidget->addWidget(gestionZonesWidget);
    
    // Connecter le bouton (si ce n'est pas déjà fait automatiquement)
    connect(ui->btnGestionZones, &QPushButton::clicked, 
            this, &MainWindow::on_btnGestionZones_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGestionZones_clicked()
{
    // Afficher la page Gestion des Zones
    ui->stackedWidget->setCurrentWidget(gestionZonesWidget);
}
```

#### Étape 5 : Vérifier mainwindow.ui

Assurez-vous que le bouton existe déjà dans votre `mainwindow.ui` :
```xml
<widget class="QPushButton" name="btnGestionZones">
    <!-- ... -->
</widget>
```

Si le bouton existe déjà (comme dans votre fichier original), vous n'avez rien à modifier dans le .ui !

---

### Méthode 2 : Module Standalone avec Bouton de Lancement

Si vous préférez garder le module séparé :

#### Dans mainwindow.cpp :

```cpp
void MainWindow::on_btnGestionZones_clicked()
{
    GestionZones *zonesWindow = new GestionZones();
    zonesWindow->setAttribute(Qt::WA_DeleteOnClose);
    zonesWindow->setWindowTitle("Gestion des Zones");
    zonesWindow->resize(1175, 695);
    zonesWindow->show();
}
```

---

## 🗄️ Base de Données Partagée

Le module utilise la même base de données `gestion_dechets.db` que votre projet principal.

### Table créée automatiquement :

```sql
CREATE TABLE IF NOT EXISTS zones (
    idZone TEXT PRIMARY KEY,
    nomZone TEXT NOT NULL,
    adresse TEXT NOT NULL,
    surface REAL NOT NULL,
    nombrePoubelles INTEGER NOT NULL,
    typeZone TEXT NOT NULL,
    statut TEXT NOT NULL
);
```

### Importer les données d'exemple :

```bash
sqlite3 gestion_dechets.db < init_zones.sql
```

Ou depuis Qt Creator, dans le terminal :
```bash
sqlite3 gestion_dechets.db ".read init_zones.sql"
```

---

## 🎨 Adaptation du Design

Le module utilise automatiquement le background de votre projet via `resources.qrc`.

Si vous avez déjà un fichier `resources.qrc` dans votre projet, ajoutez simplement :

```xml
<RCC>
    <qresource prefix="/">
        <file>background.jpg</file>
        <!-- vos autres ressources -->
    </qresource>
</RCC>
```

---

## ✅ Checklist d'Intégration

- [ ] Fichiers copiés dans le dossier du projet
- [ ] `.pro` mis à jour avec les nouveaux fichiers
- [ ] `mainwindow.h` : include et variable membre ajoutés
- [ ] `mainwindow.cpp` : widget créé et ajouté au stackedWidget
- [ ] Connexion du bouton configurée
- [ ] Projet recompilé (`Ctrl+R` dans Qt Creator)
- [ ] Test de navigation vers la page Zones

---

## 🧪 Test de l'Intégration

1. **Lancez l'application principale**
2. **Cliquez sur le bouton "📍 Gestion Zones"**
3. **Vérifiez que la page s'affiche correctement**
4. **Testez l'ajout d'une zone**
5. **Testez les autres fonctionnalités**

---

## 🔧 Compilation

Après l'intégration :

```bash
# Dans Qt Creator
# 1. Clic droit sur le projet → "Exécuter qmake"
# 2. Build → Rebuild All
# 3. Exécuter (Ctrl+R)
```

---

## 🚨 Problèmes Potentiels

### "undefined reference to vtable"
**Solution** : 
```bash
# Dans Qt Creator :
Build → Clean All
Build → Run qmake
Build → Build All
```

### "ui_gestion_zones.h not found"
**Solution** : Le fichier .ui n'est pas dans le projet
- Vérifiez que `gestion_zones.ui` est dans FORMS dans le .pro
- Clean et Rebuild

### Les boutons ne fonctionnent pas
**Solution** : Vérifiez les noms des objets dans le .ui
- Assurez-vous que les noms correspondent exactement aux slots
- Format : `on_nomBouton_clicked()`

---

## 📱 Exemple d'Utilisation dans le Projet Principal

Voici comment votre `MainWindow` devrait ressembler après l'intégration :

```cpp
// mainwindow.h
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGestionEquipes_clicked();
    void on_btnGestionEmployes_clicked();
    void on_btnGestionZones_clicked();      // ← Votre nouveau module
    void on_btnGestionPoubelles_clicked();
    void on_btnGestionMateriels_clicked();

private:
    Ui::MainWindow *ui;
    // ... autres widgets
    GestionZones *gestionZonesWidget;       // ← Votre nouveau widget
};
```

---

## 🎉 Intégration Réussie !

Une fois l'intégration terminée, vous aurez un système complet avec :
- ✅ Gestion des Zones fonctionnelle
- ✅ Navigation fluide via le menu latéral
- ✅ Design cohérent avec le reste du projet
- ✅ Base de données partagée
- ✅ Toutes les fonctionnalités métiers et innovantes

Bon développement ! 🚀
