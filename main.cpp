#include <iostream>
#include "lexer.h"
#include "automate.h"

// Fonction principale

int main(void) {
   string chaine;
   cout << "Veuillez entrer une expression à calculer (sans espaces)" << endl;
   cin >> chaine;
   Lexer l(chaine);
   Automate * a = new Automate(&l);

   a->execute(); 

   delete a; 
   return 0;
}
