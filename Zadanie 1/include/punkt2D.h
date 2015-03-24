//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#ifndef PUNKT2D_H
#define PUNKT2D_H

class punkt2D {
    public:
        double x, y;
        punkt2D ();
        punkt2D (double a, double b);
        void przesun (double a, double b);
        void wypisz();
};

#endif // PUNKT2D_H
