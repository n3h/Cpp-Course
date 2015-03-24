//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#include <iostream>
#include "punkt2D.h"
#include "odcinek2D.h"
#include "funkcje_globalne.h"

using namespace std;

int main()
{
    double wsp_x, wsp_y;
    int i;

    cout << "Wprowadz wspolrzedne punktu (X, Y): ";
    cin >> wsp_x >> wsp_y;
    punkt2D punkt(wsp_x, wsp_y);
    punkt.wypisz();

    cout << endl << "Podaj wektor przesuniecia punktu (X, Y): ";
    cin >> wsp_x >> wsp_y;
    punkt.przesun(wsp_x, wsp_y);
    punkt.wypisz();

    cout << endl << "---Tworzenie odcinka---" << endl;
    cout << "Podaj druga wsporzedna odcinka (X,Y) (pierwsza wspolrzednia to wszesniej utworzony punkt przesuniety o wektor): ";
    cin >> wsp_x >> wsp_y;
    punkt2D punkt2(wsp_x, wsp_y);
    odcinek2D odcinek(punkt, punkt2);
    odcinek.wypisz();

    cout << endl << "Podaj wektor przesuniecia odcinka (X, Y): ";
    cin >> wsp_x >> wsp_y;
    odcinek.przesun(wsp_x, wsp_y);
    odcinek.wypisz();

    cout << endl << "Dlugosc odcinka to: " << odcinek.dlugosc() << endl;

    punkt2D srodek = odcinek.punkt_srodkowy();
    cout << endl << "Punkt srodkowy odcinka: ";
    srodek.wypisz();

    for(i=0; i<3; i++) {
        cout << endl << "Podaj wspolrzedne punktu, aby sprawdzic czy nalezy on do odcinka: ";
        cin >> wsp_x >> wsp_y;
        punkt.x=wsp_x;
        punkt.y=wsp_y;
        cout << "Odpowiedz: " << (odcinek.czy_lezy_punkt(punkt) ? "TAK" : "NIE") << endl;
    }

    cout << endl << "-Sprawdzenie czy drugi odcinek jest rownolegly, prostopadly, czy sie przecinaja-" << endl;

    for(i=0; i<7; i++) {
        cout << endl << "Podaj wspolrzedne pierwszego punktu drugiego odcinka P=(X,Y): ";
        cin >> wsp_x >> wsp_y;
        punkt.x=wsp_x;
        punkt.y=wsp_y;
        cout << endl << "Podaj wspolrzedne drugiego punktu drugiego odcinka Q=(X,Y): ";
        cin >> wsp_x >> wsp_y;
        punkt2.x=wsp_x;
        punkt2.y=wsp_y;
        odcinek2D odcinek2(punkt, punkt2);
        cout << "Czy sa rownolegle: " << (czy_rownolegle(odcinek, odcinek2) ? "TAK" : "NIE") << endl;
        cout << "Czy sa prostopadle: " << (czy_prostopadle(odcinek, odcinek2) ? "TAK" : "NIE") << endl;
        cout << "Czy sie przecinaja: " << (czy_przecinaja_sie(odcinek, odcinek2) ? "TAK" : "NIE") << endl;
    }

    return 0;
}
