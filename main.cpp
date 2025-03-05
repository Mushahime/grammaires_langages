#include <iostream>
#include "lexer.h"
#include "automate.h"

// Fonction principale

int main(void) {
   string chaine("3*3+3");
   Lexer l(chaine);
   Automate * a = new Automate(&l);

   a->execute(); 

   delete a; 
   return 0;
}
