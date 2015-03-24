#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include "wyjatki.h"

class Macierz
{
    public:
        Macierz();
        Macierz(int rozmiar);
        Macierz(int wiersze, int kolumny, double wartosc = 0, int wier = 1, int kol = 1);

        ~Macierz();

        Macierz(const Macierz& m);
        Macierz& operator=(const Macierz& m);

        Macierz (Macierz &&m);
        Macierz& operator=(Macierz&& m);

        friend Macierz operator+ (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator+= (const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator+= (Macierz &&y) throw (rozmiary_nie_pasuja);

        friend Macierz operator- (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator-= (const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator-= (Macierz &&y) throw (rozmiary_nie_pasuja);

        friend Macierz operator* (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator*= (const Macierz &y) throw (rozmiary_nie_pasuja);
        Macierz & operator*= (Macierz &&y) throw (rozmiary_nie_pasuja);

        friend Macierz operator* (const Macierz &x, double skalar) noexcept;
        friend Macierz operator* (double skalar, const Macierz &x) noexcept;
        Macierz & operator*= (double skalar) noexcept;

        friend Macierz operator! (const Macierz &x) noexcept ;
        Macierz operator! () noexcept;
        //Macierz & operator!= (const Macierz &y) noexcept;
        //Macierz & operator!= (Macierz &&y) noexcept;

        friend std::istream& operator>> (std::istream &we, Macierz &x);
        friend std::ostream& operator<< (std::ostream &wy, const Macierz &x);

        double wyznacznik() throw(nie_jest_kwadratowa);
        Macierz odwrotna() throw(zerowy_wyznacznik, nie_jest_kwadratowa);

        double& operator()(const int w, const int k) throw(bledne_wspolrzedne);

    private:
        int wiersze;
        int kolumny;
        double **macierz;
};

#endif // MACIERZ_H
