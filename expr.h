#include <iostream>
#include "symbole.h"

class Expr : public Symbole {
    public:
        Expr():Symbole(EXPR) {}
        virtual ~Expr() {}
        virtual double eval (const map<string,double> & valeurs) =0;
};