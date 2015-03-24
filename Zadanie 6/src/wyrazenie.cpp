#include "wyrazenie.h"
#include <sstream>

vector<pair<string,double>> zmienna::zmienne;

wyrazenie::~wyrazenie () {}

liczba::liczba (double l) : wartosc(l) {}

double liczba::oblicz () {
    return wartosc;
}

string liczba::opis () {
    ostringstream s;
    s << wartosc;
	return s.str();
//    return to_string(wartosc);
}

zmienna::zmienna (string z) : nazwa(z) {}

double zmienna::oblicz () {
    return wartosc(nazwa);
}

string zmienna::opis () {
    return nazwa;
}

void zmienna::dodaj (string n, double w) {
    for(unsigned int i = 0; i < zmienne.size(); i++)
        if(zmienne[i].first == n) {
            zmienne[i].second = w;
            return ;
        }
//    pair<string, double> zm(n, w);
//    zmienne.push_back(zm);
    zmienne.push_back(make_pair(n,w)); //emplace_back
}

double zmienna::wartosc (string n) {
    for(unsigned int i = 0; i < zmienne.size(); i++)
        if(zmienne[i].first == n)
            return zmienne[i].second;
    throw string ("nie znaleziono zmiennej");
}

void zmienna::usun (string n) {
    for(unsigned int i = 0; i < zmienne.size(); i++)
        if(zmienne[i].first == n) {
            zmienne.erase(zmienne.begin() + i);
            return ;
        }
    throw string ("nie mozna usunac zmiennej");
}
