#ifndef LICZBY_PIERWSZE_H
#define LICZBY_PIERWSZE_H

#include <vector>
#include <cmath>
//#include "chinski_test.hpp"

class czynniki
{
    public:
        long long ile;
        long long *t;
        czynniki(std::vector<long long> &);
        czynniki(const czynniki &);
        czynniki(czynniki && that);
        czynniki& operator= (czynniki && that);
        ~czynniki();
};

class liczby_pierwsze
{
    public:
        ~liczby_pierwsze();
        static bool czy_pierwsza(long long liczba);
        static czynniki czynniki_pierwsze(long long liczba);

    private:
        static const int maksimum;
        static int * inicjalizujSito(int n);
        static int *sito;
        liczby_pierwsze();
};


inline bool liczby_pierwsze::czy_pierwsza(long long liczba) {
    if (liczba < maksimum) {
        if (sito[liczba] == liczba) return true;
        return false;
    } else {
        long long i;
        for (i = 2; (i<=sqrt(liczba)); i++)
  //          if (i < maksimum && (sito[i] == i))
            if ( (i < maksimum && (sito[i] == i)) || (i >= maksimum) )
                if (liczba % i == 0) return false;
  //          if (i >= maksimum)
  //              if (poteguj(liczba,liczba) == 2) return true;
        return true;
    }
}

#endif // LICZBY_PIERWSZE_H
