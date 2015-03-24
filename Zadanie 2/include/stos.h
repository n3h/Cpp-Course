#ifndef STOS_H
#define STOS_H

#include <string>
using namespace std;

class stos
{
    public:
        const int rozmiar; //rozmiar stosu
        stos();
        stos(int rozmiar);
        stos(const stos &);
        ~stos();

        void wloz (string); //kladziemy napis na stos
        string sciagnij (); //sciagamy napis ze stosu
        string sprawdz (); //sprawdzamy jaki napis lezy na wierzchu
        int zapelnienie (); //liczba wszystkich elementow na stosie

        // dodatkowe:
        void wypisz ();

    private:
        string *stosT;
        int ile; //liczba elementow wlozonych na stos
};

#endif // STOS_H
