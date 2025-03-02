#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(10+3)*4");
   Lexer l(chaine);
   Automate * a = new Automate(&l);

   a->execute(); 

   delete a; 
   return 0;
}
