# ⚡ Démarrage Rapide - Gestion des Zones

## 🎯 En 3 Minutes Chrono !

### Option A : Avec Qt Creator (LA PLUS SIMPLE) ⭐

```
1. Ouvrir Qt Creator
2. Fichier → Ouvrir un fichier ou un projet
3. Sélectionner "GestionZones.pro"
4. Cliquer sur "Configure Project"
5. Appuyer sur le bouton Exécuter (▶️)
```

✅ **TERMINÉ !** L'application se lance automatiquement.

---

### Option B : Ligne de Commande (Pour les Experts) 🚀

#### Windows
```cmd
qmake GestionZones.pro
mingw32-make
GestionZones.exe
```

#### Linux/Mac
```bash
qmake GestionZones.pro
make
./GestionZones
```

---

## 📦 Fichiers Nécessaires (Checklist)

Vérifiez que vous avez TOUS ces fichiers dans le même dossier :

```
✅ main.cpp                  (Point d'entrée)
✅ gestionzones.h           (En-tête)
✅ gestionzones.cpp         (Code source)
✅ gestion_zones.ui         (Interface)
✅ resources.qrc            (Ressources)
✅ background.jpg           (Image de fond)
✅ GestionZones.pro         (Fichier projet)
```

**Manque un fichier ?** L'application ne compilera pas !

---

## 🐛 Dépannage Ultra-Rapide

| Problème | Solution |
|----------|----------|
| ❌ Erreur WinMain | Il manque `main.cpp` |
| ❌ ui_gestion_zones.h not found | Faire "Clean All" puis "Rebuild" |
| ❌ Background ne s'affiche pas | Vérifier que `background.jpg` et `resources.qrc` sont présents |
| ❌ Erreur Qt6Charts | Enlever `charts` de la ligne `QT +=` dans le .pro |

---

## 🎨 Premier Test

Une fois lancé, testez ceci :

1. **Remplissez le formulaire** à gauche :
   - ID Zone : `Z001`
   - Nom : `Test Centre Ville`
   - Adresse : `Avenue Test`
   - Surface : `10000`
   - Nb Poubelles : `30`
   - Type : `Résidentielle`
   - Statut : `Active`

2. **Cliquez sur "➕ Ajouter"**

3. **Vérifiez** que la zone apparaît dans le tableau à droite

✅ **Ça marche ?** Parfait ! Vous êtes prêt à utiliser l'application.

❌ **Problème ?** Consultez `INSTALLATION.md` pour plus de détails.

---

## 🚀 Étapes Suivantes

- 📖 Lisez `README.md` pour le guide complet
- 🔗 Consultez `INTEGRATION.md` pour l'intégrer à votre projet
- 📊 Importez les données avec `init_zones.sql`
- 📄 Ouvrez `Gestion_Zones_Documentation.pdf` pour la doc technique

---

## 💡 Astuces Pro

- **Raccourci Qt Creator** : `Ctrl + R` = Compiler + Exécuter
- **Rebuild complet** : `Ctrl + Shift + B` puis `Ctrl + R`
- **Vue du code UI** : Double-clic sur `gestion_zones.ui`

---

## 📞 Besoin d'Aide ?

1. ✅ Vérifiez la checklist des fichiers ci-dessus
2. 📖 Consultez `INSTALLATION.md` pour plus de détails
3. 🐛 Regardez la section "Dépannage" ci-dessus

---

**Temps estimé** : 3-5 minutes pour avoir l'application qui tourne ! ⚡

Bon développement ! 🎉
