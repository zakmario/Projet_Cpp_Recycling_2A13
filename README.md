# 📍 Gestion des Zones - Smart Waste Management

## 🌿 Description
Application moderne de gestion des zones de collecte des déchets avec interface graphique Qt. 
Développée dans le cadre du système "Smart Waste Management - Gestion Intelligente des Déchets".

## ✨ Fonctionnalités

### 🔧 Fonctionnalités de Base (CRUD)
- ➕ **Ajouter une zone** : Création de nouvelles zones avec toutes les informations
- ✏️ **Modifier une zone** : Mise à jour des informations d'une zone existante
- 🗑️ **Supprimer une zone** : Suppression avec confirmation
- 👁️ **Consulter une zone** : Visualisation des détails dans le formulaire
- 🔄 **Effacer le formulaire** : Réinitialisation rapide

### 📊 Fonctionnalités Avancées - Métiers Basiques
1. **Trier les zones par type** : Organisation par type de zone (Résidentielle, Commerciale, etc.)
2. **Rechercher une zone par adresse** : Recherche en temps réel
3. **Générer un rapport PDF** : Export professionnel avec statistiques
4. **Statistiques par type de zone** : Visualisation en temps réel

### 🚀 Fonctionnalités Innovantes
1. **🌱 Simulation d'amélioration écologique**
   - Calcul du score écologique actuel
   - Projection d'un scénario optimisé
   - Recommandations personnalisées
   - Analyse coût/bénéfice

2. **📊 Analyse comparative des performances de recyclage**
   - Comparaison entre types de zones
   - Classement par performance
   - Identification des zones à améliorer
   - Recommandations stratégiques

## 🎨 Design

### Palette de Couleurs
- **Primaire** : #00897B (Vert émeraude)
- **Secondaire** : #26A69A (Turquoise)
- **Accent** : #2E7D32 (Vert foncé)
- **Arrière-plan** : Transparence avec fond d'image
- **Texte** : #004D40 (Vert très foncé)

### Icônes
- 📍 Zone
- 🏘️ Résidentielle
- 🏢 Commerciale
- 🏭 Industrielle
- 🏫 Scolaire
- 🏥 Hospitalière
- 🌱 Écologique

## 📁 Structure des Données

### Table : `zones`
```sql
CREATE TABLE zones (
    idZone TEXT PRIMARY KEY,
    nomZone TEXT NOT NULL,
    adresse TEXT NOT NULL,
    surface REAL NOT NULL,
    nombrePoubelles INTEGER NOT NULL,
    typeZone TEXT NOT NULL,
    statut TEXT NOT NULL
);
```

### Types de Zones
- Résidentielle
- Commerciale
- Industrielle
- Scolaire
- Hospitalière
- Autre

### Statuts
- Active
- Inactive
- En maintenance

## 🛠️ Installation

### Prérequis
- Qt 6.x
- CMake 3.16+
- Compilateur C++17
- SQLite (inclus avec Qt)

### Compilation

```bash
# Créer un dossier de build
mkdir build
cd build

# Configurer avec CMake
cmake ..

# Compiler
cmake --build .

# Exécuter
./GestionZones
```

## 💻 Utilisation

### Ajouter une Zone
1. Remplir tous les champs du formulaire
2. Sélectionner le type et le statut
3. Cliquer sur "➕ Ajouter"

### Modifier une Zone
1. Sélectionner la zone dans le tableau
2. Modifier les informations dans le formulaire
3. Cliquer sur "✏️ Modifier"

### Rechercher
- Utiliser la barre de recherche pour filtrer par adresse
- Utiliser les filtres par type
- Utiliser le tri personnalisé

### Générer un Rapport PDF
1. Cliquer sur "📄 Rapport PDF"
2. Choisir l'emplacement de sauvegarde
3. Le rapport contient :
   - Statistiques globales
   - Liste complète des zones
   - Analyses par type

### Simulation Écologique
1. Sélectionner une zone
2. Cliquer sur "🌱 Simulation Éco"
3. Analyser les résultats :
   - Score actuel
   - Score optimisé
   - Recommandations personnalisées

### Analyse Comparative
1. Cliquer sur "📊 Analyse Comparative Recyclage"
2. Consulter :
   - Performance par type de zone
   - Classement des zones
   - Recommandations d'amélioration

## 📊 Algorithme de Score Écologique

Le score écologique (0-100) est calculé selon :

### Composantes du Score
1. **Score de base** : 50 points
2. **Bonus type de zone** :
   - Résidentielle : +15
   - Commerciale : +10
   - Scolaire : +12
   - Hospitalière : +8
   - Industrielle : +5

3. **Ratio poubelles/surface** (optimal: 1/100m²) :
   - Écart < 20% : +20 points
   - Écart < 50% : +10 points
   - Écart < 100% : +5 points

4. **Nombre de poubelles** :
   - ≥ 5 poubelles : +10 points
   - ≥ 3 poubelles : +5 points

### Formule
```
Score = min(100, max(0, ScoreBase + BonusType + BonusRatio + BonusNombre))
```

## 🎯 Recommandations Générées

### Par Type de Zone

**Résidentielle** :
- Système de tri sélectif (3+ conteneurs)
- Campagnes de sensibilisation mensuelles

**Commerciale** :
- Bacs de tri papier/carton
- Partenariats avec recycleurs

**Industrielle** :
- Gestion déchets dangereux
- Optimisation traitement production

**Toutes zones** :
- Panneaux d'information
- Calendrier de collecte optimisé

## 🔐 Rôles et Autorisations

### Utilisateurs Autorisés
- **Administrateur** : Accès complet
- **Responsable Logistique** : Accès complet

## 📈 Statistiques Affichées

- 📍 **Total Zones** : Nombre total de zones
- 🏘️ **Résidentielles** : Zones résidentielles
- 🏢 **Commerciales** : Zones commerciales
- 🏭 **Industrielles** : Zones industrielles
- 📌 **Autres** : Zones scolaires, hospitalières, autres

## 🎨 Captures d'Écran

L'interface comprend :
- **Panneau gauche** : Formulaire de saisie avec tous les champs
- **Panneau droit** : Tableau de données avec statistiques
- **Boutons d'action** : Design moderne avec icônes
- **Statistiques** : Affichage en temps réel

## 🔧 Personnalisation

### Modifier les Couleurs
Éditer les styles dans `gestion_zones.ui` :
```css
QGroupBox {
    border: 2px solid rgba(0, 137, 123, 180);
    background-color: rgba(255, 255, 255, 40);
}
```

### Ajouter des Types de Zones
Modifier `comboBox_typeZone` dans le fichier `.ui`

### Modifier l'Algorithme de Score
Éditer `calculerScoreEcologique()` dans `gestionzones.cpp`

## 📝 Notes Techniques

### Base de Données
- SQLite embarqué
- Fichier : `gestion_dechets.db`
- Création automatique au premier lancement

### Performance
- Recherche en temps réel optimisée
- Rafraîchissement automatique des statistiques
- Gestion efficace de grandes quantités de données

### Sécurité
- Validation des entrées
- Confirmation avant suppression
- Protection contre les doublons d'ID

## 🤝 Intégration

Ce module s'intègre parfaitement avec :
- Gestion des Équipes
- Gestion des Employés
- Gestion des Poubelles
- Gestion des Matériels

## 📄 Licence

Projet universitaire - Gestion Intelligente des Déchets 2025

## 👥 Auteurs

Développé pour le système Smart Waste Management

## 🆘 Support

Pour toute question ou problème :
1. Vérifier la base de données SQLite
2. Vérifier les logs d'erreur Qt
3. Consulter la documentation Qt

## 🚀 Évolutions Futures

- [ ] Cartographie interactive des zones
- [ ] Prédiction IA des besoins en poubelles
- [ ] Intégration IoT pour monitoring en temps réel
- [ ] Application mobile compagnon
- [ ] Alertes automatiques de maintenance
- [ ] Export vers formats multiples (Excel, JSON)

---

**Version** : 1.0  
**Date** : Février 2025  
**Framework** : Qt 6  
**Langage** : C++17
