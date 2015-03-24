//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#include <iostream>
#include <string>
#include <cmath>
#include "odcinek2D.h"

using namespace std;

odcinek2D::odcinek2D (punkt2D &a, punkt2D &b) {
    p = a;
    q = b;
    if (p.x==q.x && p.y==q.y) throw string("odcinek o zerowej dlugosci");
}

void odcinek2D::przesun (double a, double b) {
    p.przesun(a, b);
    q.przesun(a, b);
}

int odcinek2D::dlugosc() {
    return sqrt( pow(p.x - q.x, 2) + pow(p.y - q.y, 2) );
}

punkt2D odcinek2D::punkt_srodkowy() {
    punkt2D punkt( (p.x + q.x)/2, (p.y + q.y)/2 );
    return punkt;
}

bool odcinek2D::czy_lezy_punkt(punkt2D &a) {
    double odleglosc_pa = sqrt( pow(p.x - a.x, 2) + pow(p.y - a.y, 2) );
    double odleglosc_aq = sqrt( pow(a.x - q.x, 2) + pow(a.y - q.y, 2) );
    return ((odleglosc_pa+odleglosc_aq) <= (dlugosc() + blad));
}

void odcinek2D::wypisz() {
    cout << "Obecne wspolrzedne odcinka to: P=(" << p.x << ", " << p.y << ")" << ", Q=(" << q.x << ", " << q.y << ")" << endl;
}
