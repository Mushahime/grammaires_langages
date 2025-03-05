#include "symbole.h"
#include <iostream>

// Methodes d'affichage des symboles et des entiers

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}