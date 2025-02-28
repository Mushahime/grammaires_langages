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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            ///
            break;
        case MULT:
            ///
            break;
        case CLOSEPAR:
            ///
            break;
        case FIN:
            ///
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
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
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}
bool E8::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            ///
            break;
        case MULT:
            ///
            break;
        case CLOSEPAR:
            ///
            break;
        case FIN:
            ///
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}
bool E9::transition(Automate & automate, Symbole * s) {
    switch(*s) {
        case PLUS:
            ///
            break;
        case MULT:
            ///
            break;
        case CLOSEPAR:
            ///
            break;
        case FIN:
            ///
            break;
        case default:
            cout<<"Erreur de syntaxe"<<endl;
            break;
    }
    return false;
}
