#include "symbole.h"
#include "automate.h"
#include <iostream>

bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case VARIABLE:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E1);
        default:
            automate.erreur();
            break;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case MULT:
            automate.decalage(s, new E5);
            break;
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case FIN:
            automate.accepte();
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case VARIABLE:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E6);
        default:
            automate.erreur();
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    Entier * e = nullptr;
    Expr * s1 = nullptr;
    switch(*s) {
        case PLUS:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            //delete e;
            break;
        case MULT:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            //delete e;
            break;
        case CLOSEPAR:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            //delete e;
            break;
        case FIN:
            e = (Entier*) automate.popSymbol();
            s1 = new ExprVal(e->getValeur());
            automate.reduction(1, s1);
            //delete e;
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case VARIABLE:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E7);
        default:
            automate.erreur();
            break;
    }
    return false;
}
bool E5::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case VARIABLE:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.transitionsimple(s, new E8);
        default:
            automate.erreur();
            break;
    }
    return false;
}
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
            break;
    }
    return false;
}
bool E7::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    switch(*s) {
        case PLUS:
            s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
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
            break;
    }
    return false;
}
bool E8::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    switch(*s) {
        case PLUS:
            s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
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
            break;
    }
    return false;
}
bool E9::transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    switch(*s) {
        case PLUS:
            s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case MULT:
            s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case CLOSEPAR:
            s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case FIN:
            s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}
