cmake_minimum_required(VERSION 3.16)
project(GestionZones VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql PrintSupport Charts)

# Activer le traitement automatique de Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Fichiers sources
set(PROJECT_SOURCES
    main.cpp
    gestionzones.cpp
    gestionzones.h
    gestion_zones.ui
    resources.qrc
)

# Créer l'exécutable
add_executable(GestionZones ${PROJECT_SOURCES})

# Lier les bibliothèques Qt
target_link_libraries(GestionZones PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
    Qt6::PrintSupport
    Qt6::Charts
)

# Installation
install(TARGETS GestionZones
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
