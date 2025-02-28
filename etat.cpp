#include "expr.h"
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
    switch(*s) {
        case PLUS:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprVal(s1));
            break;
        case MULT:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprVal(s1));
            break;
        case CLOSEPAR:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprVal(s1));
            break;
        case FIN:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprVal(s1));
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
    switch(*s) {
        case PLUS:
            Expr * s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            Expr * s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
            break;
        case FIN:
            Expr * s1 = (Expr *) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr *) automate.popSymbol();
            automate.reduction(3, new ExprPlus(s2, s1));
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}
bool E8::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        case MULT:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        case CLOSEPAR:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        case FIN:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr * s2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}
bool E9::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case MULT:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case CLOSEPAR:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        case FIN:
            Expr * s1 = (Expr*) automate.popSymbol();
            automate.reduction(1, new ExprPar(s1));
            break;
        default:
            automate.erreur();
            break;
    }
    return false;
}
