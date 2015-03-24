#include <iostream>
#include "operator2arg.h"

using namespace std;

int main()
{
    try {
        zmienna::dodaj("x", -0.618);
        //zmienna::dodaj("x", 1.618);

        // x
        wyrazenie *w0 = new zmienna("x");

        // 3+5
        wyrazenie *w1 = new dodaj(
            new liczba(3),
            new liczba(5)
        );

        // 2+x*7
        wyrazenie *w2 = new dodaj(
            new liczba(2),
            new mnoz(
                new zmienna("x"),
                new liczba(7)
            )
        );

        // (3+5)/(2+x*7)
        wyrazenie *w3 = new dziel(
            new dodaj(
                new liczba(3),
                new liczba(5)
            ),
            new dodaj(
                new liczba(2),
                    new mnoz(
                        new zmienna("x"),
                        new liczba(7)
                    )
            )
        );

        // ((x+1)*x)/2
        wyrazenie *w4 = new dziel(
            new mnoz (
                new dodaj (
                    new zmienna("x"),
                    new liczba(1)
                ),
                new zmienna("x")
            ),
            new liczba(2)
        );

        // przyklad: sin((x+1)*x)
        wyrazenie *w5 = new sin(
            new mnoz (
                new dodaj (
                    new zmienna("x"),
                    new liczba(1)
                ),
                new zmienna("x")
            )
        );

        // pi
        wyrazenie *w6 = new pi();

        //dzielenie przez 0
        wyrazenie *w7 = new dziel(
            new liczba(5),
            new liczba(0)
        );

        wyrazenie *w8 = new wart_bezw(
            new liczba(-5)
        );

        wyrazenie *w9 = new cos(
            new liczba(0)
        );

        wyrazenie *w10 = new modulo(
            new liczba(8),
            new liczba(3)
        );

        cout << w0->opis() << " = " << w0->oblicz() << "\n";
        cout << w1->opis() << " = " << w1->oblicz() << "\n";
        cout << w2->opis() << " = " << w2->oblicz() << "\n";
        cout << w3->opis() << " = " << w3->oblicz() << "\n";
        cout << w4->opis() << " = " << w4->oblicz() << "\n";
        cout << w5->opis() << " = " << w5->oblicz() << "\n";
        cout << w6->opis() << " = " << w6->oblicz() << "\n";
        cout << w8->opis() << " = " << w8->oblicz() << "\n";
        cout << w9->opis() << " = " << w9->oblicz() << "\n";
        cout << w10->opis() << " = " << w10->oblicz() << "\n";

        cout << w7->opis() << " = " << w7->oblicz() << "\n";

        delete w0;
        delete w1;
        delete w2;
        delete w3;
        delete w4;
        delete w5;
        delete w6;
        delete w7;
        delete w8;
        delete w9;
        zmienna::usun("x");

    } catch (string blad) {
        cerr << blad;
    };

    return 0;
}
