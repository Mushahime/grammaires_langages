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

    //lexer->TeteMoinsUn();
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
    cout << "Expression correcte" << endl;

    cout << endl;
    if (!symboles.empty() && dynamic_cast<Expr*>(symboles.back())) {
        cout << "Résultat : " << dynamic_cast<Expr*>(symboles.back())->eval({}) << endl;
    }
}

void Automate::erreur() {
    cout<<"Erreur de syntaxe"<<endl;
    exit(1);
}

double Automate::execute() {
    while (true) {
        printf("--------------------\n");
        Symbole *s = lexer->Consulter();

        printf("Symbole lu : ");
        s->Affiche();
        printf("\n");
        
        Etat * etat_current = etats.back();
        
        if (etat_current->transition(*this, s)) {
            break;
        }

        //lexer->Avancer();

        printf("Liste des états : ");
        for (auto etat : etats) {
            cout << etat->getName() << " ";
        }
        cout << endl;

        printf("Contenu de la pile : ");
        for (auto symbole : symboles) {
            symbole->Affiche();
            cout << " ";
        }
        cout << endl;
        printf("--------------------\n");
        
    }

    return 0;
}

Automate::~Automate() {

    for (auto symbole : symboles) {
        delete symbole;
    }
    symboles.clear();

    for (auto etat : etats) {
        delete etat;
    }
    etats.clear();
}
