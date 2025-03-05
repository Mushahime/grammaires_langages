#pragma once

#include <string>
#include <map>
#include <iostream>
using namespace std;

// Représente les éléments syntaxiques du langage (valeurs, opérateurs, parenthèses, etc.).

// Enumération des identificateurs des symboles : utile pour les reconnaître dans l'analyseur syntaxique et les afficher
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };
const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

// Classe abstraite Symbole : définit les méthodes d'affichage des symboles
class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident; // Identificateur du symbole
};

// Classe Entier : hérite de Symbole et représente un entier -> permet de stocker la valeur de l'entier
class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur() {return valeur;}
   protected:
      int valeur; // Valeur de l'entier
};

// Classe Expr : hérite de Symbole et représente une expression : permet d'évaluer l'expression
class Expr : public Symbole {
   public:
       Expr():Symbole(EXPR) {}
       virtual ~Expr() {}
       virtual double eval (const map<string,double> & valeurs) =0;
       virtual void Affiche() { cout << "EXPR"; }
};

// Classe ExprPlus : hérite de Expr et représente une addition : permet d'évaluer l'addition E->E+E et de retourner le résultat 
class ExprPlus : public Expr {
   public:
       ExprPlus(Expr * e1, Expr * e2):Expr(),e1(e1),e2(e2) {}
       virtual ~ExprPlus() { delete e1; delete e2; }
       virtual double eval (const map<string,double> & valeurs) { return e1->eval(valeurs) + e2->eval(valeurs); }
   protected:
       Expr * e1; // Opérande gauche
       Expr * e2; // Opérande droit
};

// Classe ExprMult : hérite de Expr et représente une multiplication : permet d'évaluer la multiplication E->E*E et de retourner le résultat
class ExprMult : public Expr {
   public:
       ExprMult(Expr * e1, Expr * e2):Expr(),e1(e1),e2(e2) {}
       virtual ~ExprMult() { delete e1; delete e2; }
       virtual double eval (const map<string,double> & valeurs) { return e1->eval(valeurs) * e2->eval(valeurs); }
   protected:
       Expr * e1; // Opérande gauche
       Expr * e2; // Opérande droit
};

// Classe ExprPar : hérite de Expr et représente une parenthèse : permet d'évaluer l'expression entre parenthèses E->(E) et de retourner le résultat (utile pour les priorités)
class ExprPar : public Expr {
   public:
       ExprPar(Expr * e):Expr(),e(e) {}
       virtual ~ExprPar() { delete e; }
       virtual double eval (const map<string,double> & valeurs) { return e->eval(valeurs); }
   protected:
       Expr * e; // Expression entre parenthèses
}; 


// Classe ExprVal : hérite de Expr et représente une valeur : permet de stocker la valeur de l'entier (E->INT) et de retourner le résultat
class ExprVal : public Expr {
   public:
       ExprVal(int val):Expr(),val(val) {}
       virtual ~ExprVal() {}
       virtual double eval (const map<string,double> & valeurs) { return val; }
   protected:
       int val; // Valeur de l'entier
};
