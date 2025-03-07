#include "automate.h"
#include <iostream>

// Reduit n symboles en un seul symbole s -> depilement de etats. Applique ensuite la transition de l'état courant avec ce symbole
void Automate::reduction(int n,Symbole * s) {
    for (int i=0; i<n; i++)
    {
        delete(etats.back());
        etats.pop_back();
    }
    

    etats.back()->transition(*this,s);
}

// Ajoute un symbole s et un état e à la pile sans réduire ni avancer dans le lexer (cas où l'on n'a pas traité le symbole du lexer : symbole non terminal)
void Automate::transitionsimple(Symbole * s, Etat * e) {
    symboles.push_back(s);
    etats.push_back(e);
}

// Ajoute un symbole s et un état e à la pile et avance dans le lexer (décalage <=> on a traité le symbole du lexer)
void Automate::decalage(Symbole * s, Etat * e) {
    symboles.push_back(s);

    etats.push_back(e);
    lexer->Avancer();
}

// Récupère le dernier symbole de la pile de symboles (cas où l'on veut récupérer le symbole pour le traiter : un entier par exemple)
Symbole * Automate::popSymbol() {
    Symbole * s = symboles.back();
    symboles.pop_back();
    return s;
}

// Supprime le dernier symbole de la pile de symboles (cas où l'on veut supprimer le symbole sans le traiter : un opérateur par exemple)
void Automate::popAndDestroySymbol() {
    delete symboles.back();
    symboles.pop_back();
}

// Accepte l'expression si elle est correcte et affiche le résultat
void Automate::accepte() {
    cout << "Expression correcte" << endl;

    cout << endl;
    if (!symboles.empty() && dynamic_cast<Expr*>(symboles.back())) {
        cout << "Résultat : " << dynamic_cast<Expr*>(symboles.back())->eval({}) << endl;
    }
}

// Affiche une erreur de syntaxe
void Automate::erreur() {
    Symbole *s = lexer->Consulter();
    if (!symboles.empty()) {
        if (symboles.back()->getIdent() == PLUS || symboles.back()->getIdent() == MULT ) {
            cout<<"[ERREUR] Après un + ou un *, vous devez mettre '(' ou un entier" << endl;
            cout<<"Vous avez entré: ";
            cout << lexer->getCurrent() <<endl;
        }
    }
    else {
            cout<<"[ERREUR] Vous avez rentrer un caractère invalide (qui n'est ni un symbole accepté ni un entier) : ";
            cout << lexer->getCurrent() <<endl;
        }
    
}

// Exécute l'automate : on récupère le symbole courant, on applique la transition de l'état courant avec ce symbole
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

// Destructeur de l'automate
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
