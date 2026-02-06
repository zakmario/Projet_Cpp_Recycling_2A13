-- ============================================
-- Script d'initialisation de la base de données
-- Gestion des Zones - Smart Waste Management
-- ============================================

-- Création de la table zones
CREATE TABLE IF NOT EXISTS zones (
    idZone TEXT PRIMARY KEY,
    nomZone TEXT NOT NULL,
    adresse TEXT NOT NULL,
    surface REAL NOT NULL,
    nombrePoubelles INTEGER NOT NULL,
    typeZone TEXT NOT NULL,
    statut TEXT NOT NULL
);

-- ============================================
-- Données d'exemple
-- ============================================

-- Zones Résidentielles
INSERT INTO zones VALUES ('Z001', 'Centre Ville Nord', 'Avenue Habib Bourguiba', 15000, 45, 'Résidentielle', 'Active');
INSERT INTO zones VALUES ('Z002', 'Quartier Résidentiel Sud', 'Rue de la République', 12000, 35, 'Résidentielle', 'Active');
INSERT INTO zones VALUES ('Z003', 'Cité El Khadra', 'Boulevard Mohamed V', 18000, 55, 'Résidentielle', 'Active');
INSERT INTO zones VALUES ('Z004', 'Résidence Les Palmiers', 'Avenue de Carthage', 8500, 25, 'Résidentielle', 'Active');
INSERT INTO zones VALUES ('Z005', 'Quartier Populaire Est', 'Rue Mongi Slim', 22000, 65, 'Résidentielle', 'Active');

-- Zones Commerciales
INSERT INTO zones VALUES ('Z006', 'Centre Commercial Tunisia Mall', 'Zone Commerciale Nord', 25000, 80, 'Commerciale', 'Active');
INSERT INTO zones VALUES ('Z007', 'Marché Central', 'Place du Marché', 8000, 40, 'Commerciale', 'Active');
INSERT INTO zones VALUES ('Z008', 'Zone d''Activités Commerciales', 'Route de La Marsa', 30000, 90, 'Commerciale', 'Active');
INSERT INTO zones VALUES ('Z009', 'Centre d''Affaires', 'Avenue de France', 12000, 50, 'Commerciale', 'Active');
INSERT INTO zones VALUES ('Z010', 'Galerie Marchande', 'Rue Ibn Khaldoun', 6000, 25, 'Commerciale', 'En maintenance');

-- Zones Industrielles
INSERT INTO zones VALUES ('Z011', 'Zone Industrielle Ben Arous', 'Route de Ben Arous', 50000, 120, 'Industrielle', 'Active');
INSERT INTO zones VALUES ('Z012', 'Parc Technologique', 'Avenue de la Technologie', 35000, 85, 'Industrielle', 'Active');
INSERT INTO zones VALUES ('Z013', 'Zone Artisanale', 'Rue de l''Industrie', 28000, 70, 'Industrielle', 'Active');
INSERT INTO zones VALUES ('Z014', 'Complexe Industriel Sud', 'Route de Sfax', 60000, 150, 'Industrielle', 'Active');

-- Zones Scolaires
INSERT INTO zones VALUES ('Z015', 'Campus Universitaire', 'Avenue de l''Université', 45000, 100, 'Scolaire', 'Active');
INSERT INTO zones VALUES ('Z016', 'Lycée Pilote', 'Rue de l''Éducation', 12000, 40, 'Scolaire', 'Active');
INSERT INTO zones VALUES ('Z017', 'Complexe Scolaire Primaire', 'Avenue des Écoles', 8000, 30, 'Scolaire', 'Active');
INSERT INTO zones VALUES ('Z018', 'École Technique', 'Boulevard de la Formation', 15000, 45, 'Scolaire', 'Active');

-- Zones Hospitalières
INSERT INTO zones VALUES ('Z019', 'Hôpital Charles Nicolle', 'Boulevard 9 Avril 1938', 20000, 75, 'Hospitalière', 'Active');
INSERT INTO zones VALUES ('Z020', 'Clinique Privée du Lac', 'Avenue du Lac', 10000, 45, 'Hospitalière', 'Active');
INSERT INTO zones VALUES ('Z021', 'Centre de Santé de Base', 'Rue de la Santé', 5000, 20, 'Hospitalière', 'Active');

-- Autres zones
INSERT INTO zones VALUES ('Z022', 'Parc Municipal', 'Avenue de la Liberté', 35000, 70, 'Autre', 'Active');
INSERT INTO zones VALUES ('Z023', 'Stade Municipal', 'Route Sportive', 40000, 60, 'Autre', 'Active');
INSERT INTO zones VALUES ('Z024', 'Gare Routière', 'Place de la Gare', 8000, 35, 'Autre', 'Active');
INSERT INTO zones VALUES ('Z025', 'Aéroport Zone Publique', 'Route de l''Aéroport', 25000, 80, 'Autre', 'Active');

-- ============================================
-- Requêtes utiles pour l'analyse
-- ============================================

-- Statistiques globales
-- SELECT 
--     COUNT(*) as total_zones,
--     SUM(surface) as surface_totale,
--     SUM(nombrePoubelles) as total_poubelles,
--     AVG(nombrePoubelles) as moyenne_poubelles
-- FROM zones;

-- Statistiques par type
-- SELECT 
--     typeZone,
--     COUNT(*) as nombre,
--     SUM(surface) as surface_totale,
--     AVG(nombrePoubelles) as moyenne_poubelles,
--     SUM(nombrePoubelles) as total_poubelles
-- FROM zones
-- GROUP BY typeZone
-- ORDER BY total_poubelles DESC;

-- Zones nécessitant une maintenance
-- SELECT * FROM zones 
-- WHERE statut = 'En maintenance'
-- ORDER BY nomZone;

-- Top 5 des zones par surface
-- SELECT idZone, nomZone, surface, typeZone
-- FROM zones
-- ORDER BY surface DESC
-- LIMIT 5;

-- Top 5 des zones par nombre de poubelles
-- SELECT idZone, nomZone, nombrePoubelles, typeZone
-- FROM zones
-- ORDER BY nombrePoubelles DESC
-- LIMIT 5;

-- Ratio poubelles/surface (densité)
-- SELECT 
--     idZone, 
--     nomZone, 
--     typeZone,
--     nombrePoubelles,
--     surface,
--     ROUND(nombrePoubelles * 1000.0 / surface, 2) as poubelles_par_1000m2
-- FROM zones
-- ORDER BY poubelles_par_1000m2 DESC;

-- Zones sous-équipées (moins de 1 poubelle / 500m²)
-- SELECT 
--     idZone, 
--     nomZone, 
--     nombrePoubelles,
--     surface,
--     ROUND(surface / nombrePoubelles, 0) as m2_par_poubelle
-- FROM zones
-- WHERE surface / nombrePoubelles > 500
-- ORDER BY m2_par_poubelle DESC;

-- ============================================
-- Notes d'utilisation
-- ============================================

-- Ce fichier contient :
-- 1. La structure de la table zones
-- 2. 25 zones d'exemple variées
-- 3. Des requêtes SQL utiles pour l'analyse
--
-- Pour utiliser ce fichier :
-- sqlite3 gestion_dechets.db < init_zones.sql
--
-- Ou depuis l'application, la table sera créée automatiquement
-- et vous pourrez importer les données d'exemple si nécessaire
