#include <iostream>

#include "pierwsze.hpp"
#include <string>

const int liczby_pierwsze::maksimum = 1 << 21;
int * liczby_pierwsze::sito = inicjalizujSito(maksimum);

int * liczby_pierwsze::inicjalizujSito(int n) {
    if (n < 1)
        throw std::string("niedodatnia wielkosc sita \n");
    int* s = new int[n];
    int i;

    for (i = 2; i <= sqrt(n); i++) {
        if (s[i]!=0)
            continue;
        for (int j = i*2; j < n; j += i)
            if (s[j] == 0) s[j] = i;
    }

    for (i = 0; i < n; i++)
        if (s[i] == 0) s[i] = i;
    return s;
}

//liczby_pierwsze::liczby_pierwsze() { }

liczby_pierwsze::~liczby_pierwsze() {
    delete[] sito;
}

czynniki liczby_pierwsze::czynniki_pierwsze(long long liczba) {
    std::vector<long long> c;
   // unsigned long long liczba2;

    if (liczba == -1) {
        c.push_back(-1);
    } else if (liczba == 0) {
        c.push_back(0);
    } else if (liczba == 1) {
        c.push_back(1);
    } else {
        if (liczba == -9223372036854775808) {
            c.push_back(-1);
            c.push_back(2);
            liczba /= -2;
        } else if (liczba < 0) {
            c.push_back(-1);
            liczba *= -1;
        }
        if (czy_pierwsza(liczba) == true) {
            c.push_back(liczba);
        } else {
            while(liczba >= maksimum) {
                for (long long k = 2; k <= sqrt(liczba); k++) {
                    if ((czy_pierwsza(k) == true) && (liczba % k == 0)) {
                        liczba /= k;
                        c.push_back(k);
                        break;
                    }
                }
            }

            if (liczba > maksimum) {
                c.push_back(liczba);
                liczba = 1;
            } else {
                while(liczba > 1) {
                    c.push_back(sito[liczba]);
                    liczba /= sito[liczba];
                }
            }
        }
    }

    czynniki ret(c);
    return ret;
}

czynniki::czynniki(std::vector<long long> &c) {
    if (c.size() < 1)
        throw std::string("wektor ma niedodatnia wielkosc \n");
    ile = c.size();
    t = new long long[ile];
    for (long long i=0; i<ile; i++)
    {
        t[i]=c[i];
    }
}

czynniki::~czynniki() {
    delete[] t;
}

czynniki::czynniki(czynniki && that) {
    t = that.t;
    ile = that.ile;
    that.ile = 0;
    that.t = nullptr;
}

czynniki& czynniki::operator= (czynniki && that) {
    std::swap(t, that.t);
    return *this;
}


czynniki::czynniki(const czynniki & k) {
    ile = k.ile;
    t = new long long[ile];
    for (int i = 0; i < ile; i++) {
        t[i] = k.t[i];
    }
}

