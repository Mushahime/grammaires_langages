#include "automate.h"
#include <iostream>

void Automate::reduction(int n,Symbole * s) {
    for (int i=0; i<n; i++)
    {
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}

void Automate::transitionsimple(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
}

void Automate::decalage(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer();
}