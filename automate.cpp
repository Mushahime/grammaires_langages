#include "automate.h"
#include <iostream>

void Automate::reduction(int n,Symbole * s) {
    for (int i=0; i<n; i++)
    {
        delete(etats.back());
        etats.pop_back();
    }
    etats.back()->transition(*this,s);
}

void Automate::transitionsimple(Symbole * s, Etat * e) {
    symboles.push_back(s);
    etats.push_back(e);
}

void Automate::decalage(Symbole * s, Etat * e) {
    symboles.push_back(s);
    etats.push_back(e);
    lexer->Avancer();
}

Symbole * Automate::popSymbol() {
    Symbole * s = symboles.back();
    symboles.pop_back();
    return s;
}

void Automate::popAndDestroySymbol() {
    delete symboles.back();
    symboles.pop_back();
}

void Automate::accepte() {
    cout<<"Expression correcte"<<endl;
}

void Automate::erreur() {
    cout<<"Erreur de syntaxe"<<endl;
}