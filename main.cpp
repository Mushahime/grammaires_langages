#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   Automate * a = new Automate(&l);

   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }

   

   return 0;
}

