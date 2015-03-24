#include <iostream>
#include <stdlib.h>
#include "pierwsze.hpp"

using namespace std;

int main(int argc, char *argv[])
{
        try {
        if (argc > 1) {
            long long liczba;

            for (int i=1; i<argc; i++) {
                liczba = atoll(argv[i]);
                czynniki e = liczby_pierwsze::czynniki_pierwsze(liczba);
    //            czynniki e2 = std::move(e);
                for (long long j=0; j<(e.ile-1); j++)
                    cout << e.t[j] << " * ";
                cout << e.t[e.ile-1] << endl;
            }
        } else {
            throw std::string("brak parametrow \n");
     /*
            //9223372036854775783
            long long tab[] = {0, -2, 30, 72, -81, 89, -9223372036854775808, 87654567};
            for (int i=0; i<(sizeof(tab)/sizeof(long long)); i++) {
                czynniki e = liczby_pierwsze::czynniki_pierwsze(tab[i]);

                for (long long j=0; j<(e.ile-1); j++)
                    cout << e.t[j] << " * ";
                cout << e.t[e.ile-1] << endl;
            }
     */
        }
    } catch (string blad) {
        cout << blad;
    }

    return 0;
}
