#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("((5*3)+(8*4))+5*2");
   Lexer l(chaine);
   Automate * a = new Automate(&l);

   a->execute(); 

   delete a; 
   return 0;
}
