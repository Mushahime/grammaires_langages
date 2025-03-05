#include <string>
#include <iostream>
using namespace std;
#include "symbole.h"

// Définit les différents états de l'automate et leurs transitions.

class Automate; // Forward declaration


// Classe abstraite Etat : définit les méthodes de transition et de récupération du nom de l'état
class Etat {
   public:
      Etat(string name) : name(name) { }
      virtual ~Etat() { }
      virtual bool transition(Automate & automate, Symbole * s) = 0;
      virtual string getName() { return name; }
   protected:
      string name;
};

// Classes héritées de Etat : implémentent les transitions de l'automate
class E0 : public Etat {
   public:
      E0() : Etat("Etat0") { }
      ~E0() { }
      bool transition(Automate & automate, Symbole * s);
};

class E1 : public Etat {
   public:
      E1() : Etat("Etat1") { }
      ~E1() { }
      bool transition(Automate & automate, Symbole * s);
};

class E2 : public Etat {
   public:
      E2() : Etat("Etat2") { }
      ~E2() { }
      bool transition(Automate & automate, Symbole * s);
};

class E3 : public Etat {
   public:
      E3() : Etat("Etat3") { }
      ~E3() { }
      bool transition(Automate & automate, Symbole * s);
};

class E4 : public Etat {
   public:
      E4() : Etat("Etat4") { }
      ~E4() { }
      bool transition(Automate & automate, Symbole * s);
};

class E5 : public Etat {
   public:
      E5() : Etat("Etat5") { }
      ~E5() { }
      bool transition(Automate & automate, Symbole * s);
};

class E6 : public Etat {
   public:
      E6() : Etat("Etat6") { }
      ~E6() { }
      bool transition(Automate & automate, Symbole * s);
};

class E7 : public Etat {
   public:
      E7() : Etat("Etat7") { }
      ~E7() { }
      bool transition(Automate & automate, Symbole * s);
};

class E8 : public Etat {
   public:
      E8() : Etat("Etat8") { }
      ~E8() { }
      bool transition(Automate & automate, Symbole * s);
};

class E9 : public Etat {
   public:
      E9() : Etat("Etat9") { }
      ~E9() { }
      bool transition(Automate & automate, Symbole * s);
};