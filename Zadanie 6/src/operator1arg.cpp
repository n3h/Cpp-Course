#include "operator1arg.h"
#include <cmath>

operator1arg::operator1arg(wyrazenie *w) : argument1(w) {}

operator1arg::~operator1arg() {
    delete argument1;
}

przec_znak::przec_znak(wyrazenie *w) : operator1arg(w) { }

double przec_znak::oblicz() {
    return -1 * argument1->oblicz();
}

string przec_znak::opis() {
    return "-(" + argument1->opis() + ")";
}

wart_bezw::wart_bezw(wyrazenie *w) : operator1arg(w) { }

double wart_bezw::oblicz() {
    return abs(argument1->oblicz());
}

string wart_bezw::opis() {
    return "|" + argument1->opis() + "|";
}

sin::sin(wyrazenie *w) : operator1arg(w) { }

double sin::oblicz() {
    return std::sin(argument1->oblicz());
}

string sin::opis() {
    return "sin(" + argument1->opis() + ")";
}

cos::cos(wyrazenie *w) : operator1arg(w) { }

double cos::oblicz() {
    return std::cos(argument1->oblicz());
}

string cos::opis() {
    return "cos(" + argument1->opis() + ")";
}
