#include "lexer.h"

// Méthodes de la classe Lexer qui permet de découper l'entrée en tokens exploitables par l'analyseur syntaxique
Symbole * Lexer::Consulter() {
   // on ne lit un nouveau symbole que si l'ancien a été consommé
   if (!tampon) {
      // ajout du symbole de fin de chaine $
      if (tete==flux.length())
      {
         tampon = new Symbole(FIN);
         tete++;
      }
      // sinon on lit le caractère courant et on détermine le symbole terminal correspondant : création du symbole
      else
      {
         printf("flux[tete] = %c\n", flux[tete]);
         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               // si ce n'est ni un opérateur ni une parenthèse, on lit un entier ou on signale une erreur si rien ne correspond
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }
               else {
                  tete++; //Utile pour afficher l'emplacement de l'erreur plus facilement
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   // m.a.j. du tampon
   tampon = nullptr;
}

Lexer::~Lexer() {
   delete tampon;
}

