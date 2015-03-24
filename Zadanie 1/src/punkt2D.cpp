//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#include <iostream>
#include "punkt2D.h"

using namespace std;

punkt2D::punkt2D() {
    x=0;
    y=0;
}

punkt2D::punkt2D(double a, double b) {
    x = a;
    y = b;
}

void punkt2D::przesun (double a, double b) {
    x += a;
    y += b;
}

void punkt2D::wypisz () {
    cout << "Obecne wspolrzedne punktu to: (" << x << ", " << y << ")" << endl;
}
