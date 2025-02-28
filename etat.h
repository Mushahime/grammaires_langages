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