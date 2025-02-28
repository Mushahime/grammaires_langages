#include "etat.h"
#include "symbole.h"
#include <vector>
#include "lexer.h"

class Automate {
   public:
      Automate();
        virtual ~Automate();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void transitionsimple(Symbole * s, Etat * e);
        void accepte();
        void erreur();
         Symbole * popSymbol();
         void popAndDestroySymbol();
   protected:
        vector<Symbole *> symboles;
        vector<Etat *> etats;
        Lexer * lexer;
};