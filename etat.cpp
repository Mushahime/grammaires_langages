#include "symbole.h"
#include "automate.h"
#include <iostream>

//Se référer à l'automate LALR(1) pour comprendre les transitions

//E0 : Etat initial
bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR: // Symbole non terminal -> transition simple
            automate.transitionsimple(s, new E1);
            break;
        default: // Erreur si le symbole n'est pas un entier, une parenthèse ou un symbole non terminal
            automate.erreur();
            return true;
    }
    return false;
}

//E1
bool E1::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case MULT:
            automate.decalage(s, new E5);
            break;
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case FIN: // Expression correcte : on retourne true -> fin de l'analyse
            automate.accepte();
            return true;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E2
bool E2::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E6);
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E3
bool E3::transition(Automate & automate, Symbole * s) {
    Entier * e = nullptr;
    Expr * s1 = nullptr;
    switch(*s) {
        case PLUS: // Réduction E->INT
            e = (Entier*) automate.popSymbol(); // On récupère l'entier

            s1 = new ExprVal(e->getValeur()); // On crée une expression avec cet entier

            automate.reduction(1, s1); // On réduit l'expression avec l'entier : -1 symbole car on a supprimé l'entier

            delete e;
            break;
        case MULT:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            delete e;
            break;
        case CLOSEPAR:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            delete e;
            break;
        case FIN:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            delete e;
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E4
bool E4::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E7);
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E5
bool E5::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E8);
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E6
bool E6::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E7
bool E7::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    switch(*s) {
        case PLUS: // Réduction E->E+E
            s1 = (Expr *) automate.popSymbol(); // On récupère le premier opérande
            automate.popAndDestroySymbol(); // On supprime le symbole '+'
            s2 = (Expr *) automate.popSymbol(); // On récupère le deuxième opérande
            automate.reduction(3, new ExprPlus(s2, s1)); // On réduit l'expression : -3 symboles car on a supprimé 3 symboles
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
            break;
        case FIN:
            s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E8
bool E8::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    switch(*s) {
        case PLUS: // Réduction E->E*E
            s1 = (Expr*) automate.popSymbol(); // On récupère le premier opérande
            automate.popAndDestroySymbol(); // On supprime le symbole '*'
            s2 = (Expr*) automate.popSymbol(); // On récupère le deuxième opérande
            automate.reduction(3, new ExprMult(s2,s1)); // On réduit l'expression : -3 symboles car on a supprimé 3 symboles
            break;
        case MULT:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        case CLOSEPAR:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        case FIN:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}

//E9
bool E9::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    switch(*s) {
        case PLUS: // Réduction E->(E)
            automate.popAndDestroySymbol(); // On supprime la parenthèse fermante
            s1 = (Expr*) automate.popSymbol(); // On récupère l'expression
            automate.popAndDestroySymbol(); // On supprime la parenthèse ouvrante
            automate.reduction(3, new ExprPar(s1)); // On réduit l'expression : -3 symboles car on a supprimé 3 symboles
            break;
        case MULT:
            automate.popAndDestroySymbol();
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, new ExprPar(s1));
            break;
        case CLOSEPAR: 
            automate.popAndDestroySymbol();
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, new ExprPar(s1));
            break;
        case FIN:
            automate.popAndDestroySymbol();
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, new ExprPar(s1));
            break;
        default:
            automate.erreur();
            return true;
    }
    return false;
}
