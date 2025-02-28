#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR, VARIABLE };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};


class Expr : public Symbole {
   public:
       Expr():Symbole(EXPR) {}
       virtual ~Expr() {}
       virtual double eval (const map<string,double> & valeurs) =0;
};

// E + E
class ExprPlus : public Expr {
   public:
       ExprPlus(Expr * e1, Expr * e2):Expr(),e1(e1),e2(e2) {}
       virtual ~ExprPlus() { delete e1; delete e2; }
       virtual double eval (const map<string,double> & valeurs) { return e1->eval(valeurs) + e2->eval(valeurs); }
   protected:
       Expr * e1;
       Expr * e2;
};

// E * E
class ExprMult : public Expr {
   public:
       ExprMult(Expr * e1, Expr * e2):Expr(),e1(e1),e2(e2) {}
       virtual ~ExprMult() { delete e1; delete e2; }
       virtual double eval (const map<string,double> & valeurs) { return e1->eval(valeurs) * e2->eval(valeurs); }
   protected:
       Expr * e1;
       Expr * e2;
};

// E -> ( E )
class ExprPar : public Expr {
   public:
       ExprPar(Expr * e):Expr(),e(e) {}
       virtual ~ExprPar() { delete e; }
       virtual double eval (const map<string,double> & valeurs) { return e->eval(valeurs); }
   protected:
       Expr * e;
}; 


// E -> val
class ExprVal : public Expr {
   public:
       ExprVal(int val):Expr(),val(val) {}
       virtual ~ExprVal() {}
       virtual double eval (const map<string,double> & valeurs) { return val; }
   protected:
       int val;
};
