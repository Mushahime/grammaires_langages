#include "etat.h"
#include "symbole.h"
#include <vector>
#include "lexer.h"

// Gère l'exécution de l'analyse syntaxique en appliquant les règles de transition entre les états.  

class Automate {
   public:
        Automate(Lexer * lexer) {etats.push_back(new E0); this->lexer = lexer;} // Initialisation de l'automate avec l'état initial E0
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
        vector<Symbole *> symboles; // Pile de symboles de l'automate ascendant
        vector<Etat *> etats; // Pile d'états de l'automate ascendant
        Lexer * lexer; // Lexer
};