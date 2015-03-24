//Kamil Bebenek, Kurs jezyka C++, zadanie 4, 31-03-2014
#include <iostream>
#include "tab_bit.h"

using namespace std;

int main()
{
    try {
        cout << "Zawartosc tablic z tresci zadania: " << endl;
        tab_bit t(46); // tablica 46-bitowa
        tab_bit u(45ull); // tablica 64-bitowa (sizeof(long long)*8)
        tab_bit v(t); // tablica 46-bitowa (skopiowana z t)
        tab_bit w(tab_bit(8)); // tablica 8-bitowa (wykradnieta obiektowi tymczasowemu)
        v[0] = 1; // ustawienie bitu 0-go bitu na 1
        t[45] = true; // ustawienie bitu 45-go bitu na 1
        bool e = v[1]; // odczytanie bitu 1-go
        u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
        cout << t << " t" << endl; // wyswietlenie zawartosci tablicy bitów na ekranie
        cout << u << " u" << endl;
        cout << v << " v" << endl;
        cout << w << " w" << endl;
        cout << e << " e (wartosc bool)" << endl;

        cout << endl << "Testy: " << endl;
        tab_bit pusty(72);
        cout << "============ 1. Tworzenie, wypelnianie tablic ============" << endl;

        tab_bit x(72);
        x[40] = 1;
        x[70] = x[20] = x[13] = x[3] = x[39] = x[37] = x[1] = x[40];
        cout << endl <<"Zapelnienie bitow: 1, 3, 13, 20, 37, 39, 40, 70" << endl;
        cout << x << " x - " << x.rozmiar() << " bity" << endl;

        tab_bit y(72);
        y[50] = 1;
        y[65] = y[21] = y[18] = y[3] = y[17] = y[32] = y[1] = y[50];
        cout << endl << "Zapelnienie bitow: 1, 3, 17, 18, 21, 32, 50, 65" << endl;
        cout << y << " y - " << y.rozmiar() << " bity" << endl;

        cout << endl << "============ 2. Kopiowanie, przenoszenie ============" << endl;
        tab_bit pom(x);
        cout << endl << pom << " pom = kopia x (konstruktorem)" << endl;

        pom = y;
        cout << pom << " pom = kopia y (przypisaniem)" << endl;

        tab_bit z(72);
        cout << endl << z << " z - pusta tablica" << endl;
        swap(z,y);
        cout << endl << y << " y - po wykradnieciu przez z (swap)" << endl;
        cout << z << " z - po wykradnieciu od y (swap)" << endl;

        tab_bit p(move(z));
        cout << endl << z << " z - po wykradnieciu przez p (konstruktor)" << endl;
        cout << p << " p - po wykradnieciu od z (konstruktor)" << endl;

        z = move(p);
        cout << endl << z << " z - po wykradnieciu od p (przypisaniem)" << endl;
        cout << p << " p - po wykradnieciu przez z (przypisaniem)" << endl;

        cout << endl << "============ 3. Operatory bitowe ============" << endl;
        cout << x << " x" << endl;
        cout << z << " z" << endl;
        pom = x;
        pom |= z;
        cout << endl << pom << " x |= z" << endl;

        pom = pusty;
        pom = x | z;
        cout << endl << pom << " x | z" << endl;

        pom = x;
        pom &= z;
        cout << endl << pom << " x &= z" << endl;

        pom = pusty;
        pom = x & z;
        cout << endl << pom << " x & z" << endl;

        pom = x;
        pom ^= z;
        cout << endl << pom << " x ^= z" << endl;

        pom = pusty;
        pom = x ^ z;
        cout << endl << pom << " x ^ z" << endl;

        pom = pusty;
        pom = !x;
        cout << endl << pom << " !x" << endl;

        cout << endl << "============ 4. operator >> (wpisz zawartosc tablicy - maksymalnie 72 elementy) ============" << endl;
        pom = pusty;
        cin >> pom;
        cout << endl << pom << " >>" << endl;

    } catch (string blad) {
        cout << blad;
    }

    return 0;
}
