#include "etat.h"
#include "symbole.h"
#include <vector>
#include "lexer.h"

class Automate {
   public:
      Automate(Lexer * lexer) {etats.push_back(new E0);
                              this->lexer = lexer;}
        virtual ~Automate();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void transitionsimple(Symbole * s, Etat * e);
        void accepte();
        void erreur();
        Symbole * popSymbol();
        void popAndDestroySymbol();
        double execute();
   protected:
        vector<Symbole *> symboles;
        vector<Etat *> etats;
        Lexer * lexer;
};