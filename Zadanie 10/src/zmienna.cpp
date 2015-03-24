#include "zmienna.h"

std::map<std::string,double> zmienna::zmienne = { };

zmienna::zmienna(std::string s, double d) {
    zmienne[s] = d;
}

zmienna::~zmienna()
{
    //dtor
}
