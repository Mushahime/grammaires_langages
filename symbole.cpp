#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
   Symbole::Affiche();
}

void ExprPlus::Affiche() {
   e1->Affiche();
   cout<<"+";
   e2->Affiche();
}

void ExprMult::Affiche() {
   e1->Affiche();
   cout<<"*";
   e2->Affiche();
}

void ExprPar::Affiche() {
   cout<<"(";
   e->Affiche();
   cout<<")";
}

void ExprVal::Affiche() {
   cout<<val;
}