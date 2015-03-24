#include <iostream>
#include "stos.h"

using namespace std;

void testuj_stos(stos &s);

int main()
{
    string wybor;
    cout << "Menu programu \"STOS NAPISOW\": \n"
         << "1. nowy() - tworzy stos bezparametrowy o rozmiarze 1 \n"
         << "2. nowy x - tworzy nowy stos o rozmiarze x \n"
         << "3. wyjscie - konczy dzialanie programu \n \n";

        while(true) {
            try {
                cin >> wybor;

                if ((wybor == "nowy()") || (wybor == "1")) {
                    stos *s = new stos();
                    testuj_stos(*s);
                    delete s;
                    s = nullptr;
                    continue;
                }

                if ((wybor == "nowy") || (wybor == "2")) {
                    int r;
                    cin >> r;
                    stos *s = new stos(r);
                    testuj_stos(*s);
                    delete s;
                    s = nullptr;
                    continue;
                }

                if ((wybor == "wyjscie") || (wybor == "3")) {
                    break;
                }

                cout << "Niepoprawne polecenie!\n";

            } catch (string blad) {
                cout << blad;
            }
        }
    return 0;
}

void testuj_stos(stos &s) {
    string wybor;

    cout << "\n"
         << "Mozliwosci testowania stosu: \n"
         << "1. wloz napis -  kladzie napis na stos \n"
         << "2. sciagnij - sciaga napis ze stosu \n"
         << "3. sprawdz - sprawdza jaki napis lezy na wierzchu stosu \n"
         << "4. zapelnienie - zwraca liczbe wszystkich elementow na stosie \n"
         << "5. kopiuj - tworzy kopie stosu i wywoluje na niej funkcje testujaca \n"
         << "6. wyjscie - usuwa obecny stos \n"
         << "inne: 7. wypisz, 8. rozmiar \n";

    while(true) {
        try {
            cout << ">> ";
            cin >> wybor;

            if ((wybor == "wloz") || (wybor == "1")) {
                string napis;
                cin >> napis;
                //cala linia
                //getline(cin, napis);
                //napis.erase(0,1);
                s.wloz(napis);
                cout << "Wlozono napis! \n";
                continue;
            }

            if ((wybor == "sciagnij") || (wybor == "2")) {
                cout << s.sciagnij() << endl;
                continue;
            }

            if ((wybor == "sprawdz") || (wybor == "3")) {
                cout << s.sprawdz() << endl;
                continue;
            }

            if ((wybor == "zapelnienie") || (wybor == "4")) {
                cout << s.zapelnienie() << endl;
                continue;
            }

            if ((wybor == "kopiuj") || (wybor == "5")) {
                stos *s2 = new stos(s);
                testuj_stos(*s2);
                continue;
            }

            if ((wybor == "wyjscie") || (wybor == "6")) {
                cout << "Usunieto stos! \n";
                break;
            }

            // dodatkowe
            if ((wybor == "wypisz") || (wybor == "7")) {
                s.wypisz();
                cout << endl;
                continue;
            }

            if ((wybor == "rozmiar") || (wybor == "8")) {
                cout << s.rozmiar << endl;
                continue;
            }

            cout << "Niepoprawne polecenie!\n";

        } catch (string blad) {
            cout << blad;
        }
    }
}
