#pragma once

#include <string>
#include "symbole.h"
#include <vector>
using namespace std;

// Responsable de l'analyse lexicale : découpe l'entrée en tokens exploitables par l'analyseur syntaxique

class Lexer {
   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() ;
      Symbole * Consulter();
      void Avancer();

   protected:
      string flux; // Chaine de caractères à analyser : exemple "3*3+3"
      int tete; // Position courante dans la chaine
      Symbole * tampon; // Symbole courant
};
