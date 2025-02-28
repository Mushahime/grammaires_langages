# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(GrammaireLangages)

# Spécifie le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les répertoires contenant les fichiers d'en-tête
include_directories(${CMAKE_SOURCE_DIR})

# Ajouter les fichiers source
set(SOURCES
    lexer.cpp
    main.cpp
    symbole.cpp
    etat.cpp
    expr.cpp
    etat.cpp
    )

# Créer un exécutable avec les sources définies
add_executable(gl ${SOURCES})
