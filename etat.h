#include <string>
using namespace std;

class Etat {
   public:
      Etat(string name) : name(name) { }
      virtual ~Etat() { }
      virtual bool transition(Automate & automate, Symbole * s) = 0;
      virtual string getName() { return name; }
      virtual print() const { cout << name; }
   protected:
      string name;
};

class Etat0 : public Etat {
   public:
      Etat0() : Etat("Etat0") { }
      ~Etat0() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat1 : public Etat {
   public:
      Etat1() : Etat("Etat1") { }
      ~Etat1() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat2 : public Etat {
   public:
      Etat2() : Etat("Etat2") { }
      ~Etat2() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat3 : public Etat {
   public:
      Etat3() : Etat("Etat3") { }
      ~Etat3() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat4 : public Etat {
   public:
      Etat4() : Etat("Etat4") { }
      ~Etat4() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat5 : public Etat {
   public:
      Etat5() : Etat("Etat5") { }
      ~Etat5() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat6 : public Etat {
   public:
      Etat6() : Etat("Etat6") { }
      ~Etat6() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat7 : public Etat {
   public:
      Etat7() : Etat("Etat7") { }
      ~Etat7() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat8 : public Etat {
   public:
      Etat8() : Etat("Etat8") { }
      ~Etat8() { }
      bool transition(Automate & automate, Symbole * s);
};

class Etat9 : public Etat {
   public:
      Etat9() : Etat("Etat9") { }
      ~Etat9() { }
      bool transition(Automate & automate, Symbole * s);
};