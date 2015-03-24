//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#ifndef ODCINEK2D_H
#define ODCINEK2D_H

#include "punkt2D.h"

const double blad = 0.1;

class odcinek2D
{
    public:
        punkt2D p, q;
        odcinek2D (punkt2D &a, punkt2D &b);
        void przesun(double a, double b);
        int dlugosc();
        punkt2D punkt_srodkowy();
        bool czy_lezy_punkt(punkt2D &a);
        void wypisz();
};

#endif // ODCINEK2D_H
