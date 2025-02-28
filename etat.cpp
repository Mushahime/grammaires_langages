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