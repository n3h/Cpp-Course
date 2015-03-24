#include <iostream>
#include "macierz.h"

using namespace std;

int main()
{
    try {
        cout << "Macierz jednostkowa: " << "\n";
        Macierz m1 = Macierz(3);
        cout << m1;

        cout << "Macierz prostokatna: " << "\n";
        Macierz m2 = Macierz(3,3,2.5,3,3);
        cout << m2;

        cout << "M1 + M2: " << "\n";
        Macierz m3 = m1 + m2;
        cout << m3;

        cout << "M4 += M1: " << "\n";
        Macierz m4 = Macierz(3);
        m4 += m1;
        cout << m4;

        cout << "M5 += move(M1): " << "\n";
        Macierz m5 = Macierz(3);
        m5 += move(m1);
        cout << m5;

        cout << "M1: " << "\n";
        cout << m1 << "\n";

        cout << "M5 *= 3 " << "\n";
        m5 *= 3;
        cout << m5;

        cout << "M10 = move(M5) " << "\n";
        Macierz m10 = move(m5);
        cout << m10;

        cout << "M5: " << "\n";
        cout << m5 << "\n";

        cout << "M5 = M1" << "\n";
        m5 = m1;
        cout << m5;

        cout << "M5 = move(M10) " << "\n";
        m5 = move(m10);
        cout << m5;

        cout << "M10: " << "\n";
        cout << m10;

        //Macierz mpp = Macierz(-2,1);

/*
        cout << "Mnozenie: " << "\n";
        Macierz m1x = Macierz(2,3);
        cin >> m1x;
        Macierz m2x = Macierz(3,2);
        cin >> m2x;
        Macierz m3x = m1x * m2x;
        cout << m3x;
*/
/*
        cout << "Wczytaj M6: " << "\n";
        Macierz m6 = Macierz(3);
        cin >> m6;

        cout << "Wypisz M6: " << "\n";
        cout << m6;

        cout << "M5 = !M6 " << "\n";
        m5 = !m6;
        cout << m5;

        cout << "!M5" << "\n";
        !m5;
        cout << m5;

        cout << "Wyznacznik macierzy M5: ";
        double w1 = m5.wyznacznik();
        cout << w1 << "\n";

        cout << "Macierz odwrotna do M5" << "\n";
        Macierz m7 = m5.odwrotna();
        cout << m7;
*/
        //Macierz mzz = Macierz(-2);

        cout << "Podaj rozmiar macierzy do wczytania: ";
        int rozm;
        cin >> rozm;
        cout << "Wczytaj MA: " << "\n";
        Macierz ma = Macierz(rozm);
        cin >> ma;

        cout << "Wypisz MA: " << "\n";
        cout << ma;

        cout << "Wyznacznik macierzy MA: ";
        double wa = ma.wyznacznik();
        cout << wa << "\n";

        cout << "Macierz odwrotna do MA" << "\n";
        Macierz mb = ma.odwrotna();
        cout << mb;


    } catch (rozmiary_nie_pasuja& e) {
        cerr << "Wystapil wyjatek \"rozmiary_nie_pasuja\"" << "\n";
        cerr << e.what() << "\n";
    } catch (ujemny_rozmiar& e) {
        cerr << "Wystapil wyjatek \"ujemny_rozmiar\"" << "\n";
        cerr << e.what() << "\n";
    } catch (nie_jest_kwadratowa& e) {
        cerr << "Wystapil wyjatek \"nie_jest_kwadratowa\"" << "\n";
        cerr << e.what() << "\n";
    } catch (bledne_wspolrzedne& e) {
        cerr << "Wystapil wyjatek \"bledne_wspolrzedne\"" << "\n";
        cerr << e.what() << "\n";
    } catch (zerowy_wyznacznik& e) {
        cerr << "Wystapil wyjatek \"zerowy_wyznacznik\"" << "\n";
        cerr << e.what() << "\n";
    } catch (nieprawidlowe_wejscie& e) {
        cerr << "Wystapil wyjatek \"nieprawidlowe_wejscie\"" << "\n";
        cerr << e.what() << "\n";
    } catch (zly_rozmiar& e) {
        cerr << "Wystapil wyjatek \"zly_rozmiar\"" << "\n";
        cerr << e.what() << "\n";
    } catch (std::exception& e) {
        cerr << e.what() << "\n";
    }
    return 0;
}
