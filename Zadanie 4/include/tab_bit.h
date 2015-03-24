//Kamil Bebenek, Kurs jezyka C++, zadanie 4, 31-03-2014
#ifndef TAB_BIT_H
#define TAB_BIT_H

#include <iostream>

using namespace std;

class tab_bit
{
        typedef unsigned long long slowo; // komorka w tablicy
        static const int rozmiarSlowa; // rozmiar slowa w bitach
        class ref; // klasa pomocnicza dla operatora indeksowania
    protected:
        int dl; // liczba bitów
        slowo *tab; // tablica bitów
    public:
        explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
        explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
        tab_bit (const tab_bit &tb); // konstruktor kopiuj¹cy
        tab_bit (tab_bit &&tb); // konstruktor przenosz¹cy
        tab_bit & operator = (const tab_bit &tb); // przypisanie kopiuj¹ce
        tab_bit & operator = (tab_bit &&tb); // przypisanie przenosz¹ce
        ~tab_bit (); // destruktor
    private:
        bool czytaj (int i) const; // metoda pomocnicza do odczytu pojedynczego bitu
        bool pisz (int i, bool b); // metoda pomocnicza do zapisu pojedynczego bitu
    public:
        bool operator[] (int i) const; // indeksowanie dla sta³ych tablic bitowych
        ref operator[] (int i); // indeksowanie dla zwyk³ych tablic bitowych
        inline int rozmiar () const { return dl; }; // rozmiar tablicy w bitach
    public:
        // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
        friend tab_bit & operator | (const tab_bit &, const tab_bit &);
        tab_bit & operator |= (const tab_bit &);
        friend tab_bit & operator & (const tab_bit &, const tab_bit &);
        tab_bit & operator &= (const tab_bit &);
        friend tab_bit & operator ^ (const tab_bit &, const tab_bit &);
        tab_bit & operator ^= (const tab_bit &);
        friend tab_bit & operator ! (const tab_bit &);
    public:
        // zaprzyjaŸnione operatory strumieniowe: << i >>
        friend istream & operator >> (istream &we, tab_bit &tb);
        friend ostream & operator << (ostream &wy, const tab_bit &tb);
};

class tab_bit::ref {
    tab_bit * tb;
    int indeks;

public:
    operator bool() const;
    ref(tab_bit* const t, const int i);
    ref& operator = (bool bit);
    ref& operator = (const ref& t);
};

#endif // TAB_BIT_H
