# Grammaires et langages : Projet d'Analyse Syntaxique et Évaluation d'Expression Arithmétique

## Auteurs
- **MARIAT Quentin**
- **CLOUSCARD Théo**
- **CATHERINE Noam**

## Description du projet
Ce projet consiste en l'implémentation d'un analyseur syntaxique basé sur un automate **LALR(1)** pour évaluer des expressions arithmétiques. L'objectif principal est de construire et d'interpréter ces expressions tout en appliquant les règles de priorité et d'associativité définies (Projet fait dans le cadre du cours Grammaires et langages à l'INSA Lyon).

## Installation et Compilation (requiert linux et C++)
### 1. Génération des fichiers avec CMake :
```sh
mkdir build
cd build
cmake ..
```

#### Si vous souhaitez activer l'option Valgrind, utilisez
```sh
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

### 2. Compilation
```sh
cd build #Si vous n'êtes pas déja dans le répertoire build
make
```

### 3. Execution
```sh
./gl
```

#### Pour exécuter avec Valgrind (détection des fuites mémoire)
```sh
valgrind --leak-check=full --track-origins=yes ./gl
```

## Grammaire mise en place
```
E' → E
E → E + E
E → E * E
E → ( E )
E → val
```

Note : - L'addition (+) et la multiplication (*) sont associatives à gauche.  
- La multiplication a une priorité plus élevée que l'addition.  
- L'analyseur suit une approche LALR(1) et résout les conflits en faveur de l'opérateur de plus haute priorité.  

## Architecture du projet 

Le projet est structuré autour de plusieurs modules :      

📌 Automate (automate.cpp, automate.h)
Gère l'exécution de l'analyse syntaxique en appliquant les règles de transition entre les états.  
  
🔄 États (etat.cpp, etat.h)
Définit les différents états de l'automate et leurs transitions.  
  
🔍 Lexer (lexer.cpp, lexer.h)
Responsable de l'analyse lexicale : découpe l'entrée en tokens exploitables par l'analyseur syntaxique.  
  
🔠 Symboles (symbole.cpp, symbole.h)
Représente les éléments syntaxiques du langage (valeurs, opérateurs, parenthèses, etc.).  
  
🚀 Main (main.cpp)
Point d'entrée du programme, gère l'exécution globale et orchestre les interactions entre les différents modules.  
  
Note : certaines méthodes ont été codées en inline (voir .h)


