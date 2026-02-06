# 🚀 Guide d'Installation Rapide - Gestion des Zones

## 📋 Prérequis

Avant de commencer, assurez-vous d'avoir installé :
- **Qt 6.x** (avec Qt Creator recommandé)
- **Compilateur C++17** (MinGW sur Windows, GCC/Clang sur Linux)
- **CMake 3.16+** (optionnel si vous utilisez Qt Creator)

## 🛠️ Méthode 1 : Avec Qt Creator (RECOMMANDÉ)

### Étape 1 : Ouvrir le projet
1. Lancez **Qt Creator**
2. Allez dans **Fichier → Ouvrir un fichier ou un projet**
3. Sélectionnez le fichier **GestionZones.pro**

### Étape 2 : Configurer le kit
1. Qt Creator détecte automatiquement votre kit Qt
2. Sélectionnez **Desktop Qt 6.x.x MinGW 64-bit** (ou équivalent)
3. Cliquez sur **Configure Project**

### Étape 3 : Compiler et exécuter
1. Cliquez sur le bouton **▶️ Exécuter** (ou appuyez sur `Ctrl+R`)
2. Le projet se compile automatiquement
3. L'application se lance !

### ✅ C'est tout ! L'application devrait s'ouvrir.

---

## 🛠️ Méthode 2 : En ligne de commande avec CMake

### Sous Windows (PowerShell ou CMD)

```powershell
# Créer un dossier de build
mkdir build
cd build

# Configurer avec CMake (adaptez le chemin Qt selon votre installation)
cmake .. -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.5.0/mingw_64"

# Compiler
cmake --build .

# Exécuter
./GestionZones.exe
```

### Sous Linux

```bash
# Créer un dossier de build
mkdir build
cd build

# Configurer avec CMake
cmake ..

# Compiler
make

# Exécuter
./GestionZones
```

---

## 🛠️ Méthode 3 : Avec qmake

```bash
# Générer le Makefile
qmake GestionZones.pro

# Compiler
make  # ou mingw32-make sur Windows

# Exécuter
./GestionZones  # ou GestionZones.exe sur Windows
```

---

## ⚠️ Résolution des Problèmes Courants

### Erreur : "undefined reference to WinMain"
**Solution** : Le fichier `main.cpp` est manquant ou mal configuré.
- Vérifiez que `main.cpp` est bien dans le dossier du projet
- Vérifiez qu'il est listé dans `GestionZones.pro` ou `CMakeLists.txt`

### Erreur : "ui_gestion_zones.h: No such file or directory"
**Solution** : Le fichier .ui n'a pas été compilé.
- Avec Qt Creator : Rebuild tout le projet
- En ligne de commande : Supprimez le dossier `build` et recommencez

### Erreur : "cannot find -lQt6Charts"
**Solution** : Qt Charts n'est pas installé ou pas nécessaire.
- Dans Qt Maintenance Tool, installez Qt Charts
- OU enlevez `charts` de la ligne `QT += ...` dans le fichier .pro

### L'application compile mais ne trouve pas background.jpg
**Solution** : Le fichier de ressources n'est pas compilé.
- Vérifiez que `resources.qrc` est dans le projet
- Vérifiez que `background.jpg` est dans le même dossier
- Rebuild le projet complètement

### Erreur de base de données
**Solution** : SQLite n'est pas inclus.
- SQLite est normalement inclus avec Qt
- Vérifiez que `QT += sql` est présent dans le .pro

---

## 📁 Structure des Fichiers

Vérifiez que vous avez tous ces fichiers :

```
GestionZones/
├── main.cpp                    ✅ Point d'entrée de l'application
├── gestionzones.h             ✅ En-tête de la classe
├── gestionzones.cpp           ✅ Implémentation
├── gestion_zones.ui           ✅ Interface graphique
├── resources.qrc              ✅ Fichier de ressources Qt
├── background.jpg             ✅ Image de fond
├── GestionZones.pro           ✅ Fichier projet Qt (recommandé)
├── CMakeLists.txt             ✅ Fichier projet CMake (alternatif)
├── README.md                  📖 Documentation
└── init_zones.sql             📊 Données d'exemple
```

---

## 🎯 Vérification Rapide

Pour vérifier que tout est en ordre avant de compiler :

### Checklist ✓
- [ ] Qt 6.x est installé
- [ ] Qt Creator est lancé (ou CMake/qmake disponible en ligne de commande)
- [ ] Tous les fichiers (.cpp, .h, .ui, .qrc, .jpg) sont présents
- [ ] Le fichier de projet (.pro ou CMakeLists.txt) est correct

---

## 🎨 Premiers Pas après Installation

Une fois l'application lancée :

1. **Testez l'ajout d'une zone** :
   - Remplissez le formulaire à gauche
   - Cliquez sur "➕ Ajouter"

2. **Importez les données d'exemple** :
   - Utilisez le fichier `init_zones.sql`
   - Ou ajoutez manuellement quelques zones

3. **Explorez les fonctionnalités** :
   - Recherche par adresse
   - Tri par type
   - Génération de rapport PDF
   - Simulation écologique
   - Analyse comparative

---

## 📞 Support

En cas de problème :

1. Vérifiez que tous les fichiers sont présents
2. Vérifiez la version de Qt (6.x minimum)
3. Consultez la section "Résolution des Problèmes" ci-dessus
4. Vérifiez les logs de compilation dans Qt Creator

---

## 🎉 Bon développement !

Une fois l'installation réussie, consultez le **README.md** pour le guide d'utilisation complet et la **Gestion_Zones_Documentation.pdf** pour la documentation technique détaillée.
