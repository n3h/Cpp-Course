#include "operator2arg.h"
#include <cmath>

operator2arg::operator2arg(wyrazenie *w1, wyrazenie *w2) : operator1arg(w1), argument2(w2) {}

operator2arg::~operator2arg() {
    delete argument2;
}

dodaj::dodaj (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double dodaj::oblicz() {
    return argument1->oblicz()+argument2->oblicz();
}

string dodaj::opis() {
    return "(" + argument1->opis() + "+" + argument2->opis() + ")";
}

logarytm::logarytm (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double logarytm::oblicz() {
    if((argument1->oblicz() <= 0) || (argument2->oblicz()) <= 0 || (argument1->oblicz() == 1))
        throw string ("wartosci musza byc dodatnie, bledny logarytm");
    return log(argument2->oblicz())/log(argument1->oblicz());
}

string logarytm::opis() {
    return "log(" + argument1->opis() + ", " + argument2->opis() + ")";
}

odejmij::odejmij (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double odejmij::oblicz() {
    return argument1->oblicz()-argument2->oblicz();
}

string odejmij::opis() {
    return "(" + argument1->opis() + "-" + argument2->opis() + ")";
}

modulo::modulo (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double modulo::oblicz() {
    //w
    return fmod(argument1->oblicz(), argument2->oblicz());
}

string modulo::opis() {
    return "(" + argument1->opis() + "%" + argument2->opis() + ")";
}

mnoz::mnoz (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double mnoz::oblicz() {
    return argument1->oblicz() * argument2->oblicz();
}

string mnoz::opis() {
    return "(" + argument1->opis() + "*" + argument2->opis() + ")";
}

potega::potega (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double potega::oblicz() {
    return pow(argument1->oblicz(), argument2->oblicz());
}

string potega::opis() {
    return "(" + argument1->opis() + "^" + argument2->opis() + ")";
}

dziel::dziel (wyrazenie *w1, wyrazenie *w2) : operator2arg(w1,w2) {}

double dziel::oblicz() {
    if (argument2->oblicz() == 0)
        throw string("nie mozna dzielic przez 0");
    return argument1->oblicz() / argument2->oblicz();
}

string dziel::opis() {
    return "(" + argument1->opis() + "/" + argument2->opis() + ")";
}
