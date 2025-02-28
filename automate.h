#include "etat.h"
#include "symbole.h"
#include <stack>

class Automate {
   public:
      Automate();
        virtual ~Automate();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void transitionsimple(Symbole * s, Etat * e);
        void accepte();
        void erreur();
   protected:
        stack<Symbole *> symboles;
        stack<Etat *> etats;
};