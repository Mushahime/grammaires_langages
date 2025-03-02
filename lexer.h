#pragma once

#include <string>
#include "symbole.h"
#include <vector>
using namespace std;

//extern vector<Symbole *> S;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() ;

      Symbole * Consulter();
      void Avancer();
      void TeteMoinsUn() { tete--; }

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
