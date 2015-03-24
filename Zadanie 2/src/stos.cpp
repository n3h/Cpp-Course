#include "stos.h"
#include <iostream>
//#include <cstring>

stos::stos(int r) : rozmiar(r)
{
    if (rozmiar < 1)
        throw string("niedodatnia wielkosc stosu \n");
    stosT = new string[rozmiar];
    ile = 0;
}

stos::stos() : rozmiar(1)
{
    stosT = new string[rozmiar];
    ile = 0;
}

stos::stos(const stos &s) : rozmiar(s.rozmiar)
{
    stosT = new string[rozmiar];
    ile = s.ile;
    for (int i = 0; i < ile; i++) {
        stosT[i] = s.stosT[i];
    }
    //lub
    //copy(s.stosT, s.stosT+s.ile, stosT);
    //memcpy(stosT, s.stosT, sizeof(s.stosT)*ile);

    /*
    ile = 0;
    for (int i = 0; i < s.ile; i++) {
        this->wloz(s.stosT[i]);
    }
    */
}

stos::~stos()
{
    delete[] stosT;
}

void stos::wloz (string element) {
    if (rozmiar == ile)
        throw string("stos jest pelny, nie mozna wlozyc nowego elementu \n");
    stosT[ile] = element;
    ile++;

}

string stos::sciagnij () {
    if (ile == 0) throw string("stos pusty, brak mozliwosci sciagniecia elementu \n");
    ile--;
    return stosT[ile];
}

string stos::sprawdz () {
    if (ile == 0) throw string("brak elementow na stosie \n");
    return stosT[ile-1];
}

int stos::zapelnienie () {
    return ile;
}

//dodatkowe
void stos::wypisz () {
    if (ile == 0) throw string("stos pusty \n");
    for (int i = 0; i < ile; i++) std::cout << stosT[i] << " ";
}
