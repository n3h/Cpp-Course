#include <iostream>
#include <iomanip>

#include "macierz.h"

using namespace std;

Macierz::Macierz() {
    kolumny = 0;
    wiersze = 0;
    macierz = nullptr;
}

Macierz::Macierz(int rozmiar) {
    if (rozmiar < 0) throw ujemny_rozmiar("Ujemny rozmiar, nie mozna stworzyc obiektu");
    kolumny = rozmiar;
    wiersze = rozmiar;
    macierz = new double*[wiersze];
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = new double[kolumny];
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = (i == j) ? 1 : 0;
        }
    }
}

Macierz::Macierz(int w, int k, double wartosc, int wier, int kol) {
    if (w < 0 || k < 0) throw ujemny_rozmiar("Ujemny rozmiar, nie mozna stworzyc obiektu");
    kolumny = k;
    wiersze = w;
    macierz = new double*[wiersze];
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = new double[kolumny];
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = ((i == wier-1) && (j == kol-1)) ? wartosc : 0;
        }
    }
}

Macierz::~Macierz() {
    for (int i = 0; i < wiersze; i++)
        delete[] macierz[i];
    delete[] macierz;
    macierz = nullptr;
}

Macierz::Macierz(const Macierz& m) {
    kolumny = m.kolumny;
    wiersze = m.wiersze;
    macierz = new double*[kolumny];
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = new double[kolumny];
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = m.macierz[i][j];
        }
    }
}

Macierz& Macierz::operator=(const Macierz& m) {
    if (this == &m) return *this;

    if (kolumny != m.kolumny || wiersze != m.wiersze) {
        this->~Macierz();
        kolumny = m.kolumny;
        wiersze = m.wiersze;
        macierz = new double*[kolumny];
        for (int i = 0; i < wiersze; i++) {
            macierz[i] = new double[kolumny];
        }
    }

    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = m.macierz[i][j];
        }
    }
    return *this;
}

Macierz::Macierz(Macierz&& m) {
    kolumny = m.kolumny;
    wiersze = m.wiersze;
    macierz = m.macierz;
    m.kolumny = 0;
    m.wiersze = 0;
    m.macierz = nullptr;
}

Macierz& Macierz::operator=(Macierz&& m) {
    swap(kolumny, m.kolumny);
    swap(wiersze, m.wiersze);
    swap(macierz, m.macierz);
    return *this;
}

Macierz operator+ (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (x.wiersze != y. wiersze || x.kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    Macierz m = Macierz(x);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            m.macierz[i][j] += y.macierz[i][j];
        }
    }
    return m;
}

Macierz & Macierz::operator+= (const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (wiersze != y. wiersze || kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] += y.macierz[i][j];
        }
    }
    return *this;
}

Macierz & Macierz::operator+= (Macierz &&y) throw (rozmiary_nie_pasuja) {
    if (wiersze != y. wiersze || kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] += move(y.macierz[i][j]);
        }
    }
    return *this;
}

Macierz operator- (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (x.wiersze != y. wiersze || x.kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    Macierz m = Macierz(x);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            m.macierz[i][j] -= y.macierz[i][j];
        }
    }
    return m;
}

Macierz & Macierz::operator-= (const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (wiersze != y. wiersze || kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] -= y.macierz[i][j];
        }
    }
    return *this;
}

Macierz & Macierz::operator-= (Macierz &&y) throw (rozmiary_nie_pasuja) {
    if (wiersze != y. wiersze || kolumny != y.kolumny) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] -= move(y.macierz[i][j]);
        }
    }
    return *this;
}

Macierz operator* (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (x.kolumny != y.wiersze) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    Macierz m = Macierz(x.wiersze, y.kolumny);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            for (int k = 0; k < x.kolumny; k++) {
                m.macierz[i][j] += x.macierz[i][k] * y.macierz[k][j];
            }
        }
    }
    return m;
}

Macierz & Macierz::operator*= (const Macierz &y) throw (rozmiary_nie_pasuja) {
    if (kolumny != y.wiersze) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    Macierz m = Macierz(wiersze, y.kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            for (int k = 0; k < kolumny; k++) {
                macierz[i][j] += macierz[i][k] * y.macierz[k][j];
            }
        }
    }
    return *this;
}

Macierz & Macierz::operator*= (Macierz &&y) throw (rozmiary_nie_pasuja) {
    if (kolumny != y.wiersze) throw rozmiary_nie_pasuja("Rozmiary macierzy nie pasuja");
    Macierz m = Macierz(wiersze, y.kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            for (int k = 0; k < kolumny; k++) {
                macierz[i][j] += macierz[i][k] * move(y.macierz[k][j]);
            }
        }
    }
    return *this;
}

Macierz operator* (const Macierz &x, double skalar) noexcept {
    Macierz m = Macierz(x);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            m.macierz[i][j] *= skalar;
        }
    }
    return m;
}

Macierz operator* (double skalar, const Macierz &x) noexcept {
    return x*skalar;
}

Macierz & Macierz::operator*= (double skalar) noexcept {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] *= skalar;
        }
    }
    return *this;
}

Macierz operator! (const Macierz &x) noexcept {
    Macierz m = Macierz(x);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            m.macierz[i][j] = x.macierz[j][i];
        }
    }
    return m;
}

Macierz Macierz::operator! () noexcept {
    Macierz pom = Macierz(*this);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = pom.macierz[j][i];
        }
    }
    return *this;
}

istream& operator>> (istream &we, Macierz &x) {
    //ustalenie rozmiaru macierzy (dla macierzy pustej o wymiarach 0x0)
    if (x.wiersze == 0 && x.kolumny == 0) {
        x.~Macierz();
        cout << "Podaj ilosc wierszy: ";

        if (!(cin >> x.wiersze)) {
            throw nieprawidlowe_wejscie("Nieprawidlowe wejscie");
        }
        cout << "Podaj ilosc kolumn: ";
        if (!(cin >> x.kolumny)) {
            throw nieprawidlowe_wejscie("Nieprawidlowe wejscie");
        }

        x.macierz = new double*[x.kolumny];
        for (int i = 0; i < x.wiersze; i++) {
            x.macierz[i] = new double[x.kolumny];
        }
    }

    // wypelnianie macierzy
    for (int i = 0; i < x.wiersze; i++) {
        for (int j = 0; j < x.kolumny; j++) {
            if (!(we >> x.macierz[i][j])) {
                throw nieprawidlowe_wejscie("Nieprawidlowe wejscie");
            }
        }
    }
    return we;
}

ostream& operator<< (ostream &wy, const Macierz &x) {
    if (x.wiersze == 0 || x.kolumny == 0) {
        wy << "[ ]";
    } else {
        for (int i = 0; i < x.wiersze; i++) {
        for (int j = 0; j < x.kolumny; j++) {
            wy << setw(6) << setprecision(2+1) << x.macierz[i][j] << " ";
        }
        wy << "\n";
        }
    }
    return wy;
}

double& Macierz::operator()(const int w, const int k) throw(bledne_wspolrzedne) {
    if (w < 1 || w > wiersze || k < 1 || k > kolumny) throw bledne_wspolrzedne("Nie mozna odczytac wartosci z macierzy");
    return macierz[w-1][k-1];
}

Macierz Macierz::odwrotna() throw(zerowy_wyznacznik, nie_jest_kwadratowa) {
    if (wiersze != kolumny) throw nie_jest_kwadratowa("Macierz nie jest kwadratowa, brak wyznacznika");

    double wyzn = wyznacznik();
    if (wyzn == 0) throw zerowy_wyznacznik("Wyznacznik rowny 0, brak macierzy odwrotnej");

    Macierz m;

    if (wiersze == 1) {
        m = Macierz(1, 1, 1/(*this)(1,1), 1, 1);
    } else if (wiersze == 2) {
        m = Macierz(wiersze, kolumny);
        m(1,1) = (*this)(2,2);//
        m(1,2) = -(*this)(1,2);//
        m(2,1) = -(*this)(2,1);//
        m(2,2) = (*this)(1,1);//
        m = m*(1/wyzn);
    } else {

        m = Macierz(wiersze); // macierz jednostkowa
        for (int i = 1; i <= wiersze; i++) {
            m(i,i) = 1;
        }

        Macierz kopia = (*this); //

        // elementy na przek¹tnej powinny byc niezerowe, a jesli sa to zamieniamy wiersz z wierszem nizej
        for (int k = 1; k <= kolumny; k++) {
            int w = k;
            while (w <= wiersze && kopia(w,k) == 0) w++;

            //zamieniamy wiersze, jesli jest taka potrzeba
            if (w != k) {
                for (int s = 1; s <= kolumny; s++) {
                    std::swap(kopia(k,s), kopia(w,s));
                    std::swap(m(k,s), m(w,s));
                }
            }

            // czyscimy pozostale wiersze z niezerowych wartosci
            for (int w = 1; w <= wiersze; w++) { //do wyznacznika wystarczy od w = k
                if(w != k) {
                    if (kopia(w,k) != 0) {
                        double wsp = - kopia(w,k) / kopia(k,k);//

                        for (int s = 1; s <= kolumny; s++) {
                            kopia(w,s) += wsp * kopia(k,s);//
                            m(w,s) += wsp * m(k,s);
                        }
                    }
                } else { // a wiersz k przerabiamy tak, aby z lewej strony miec 1 (przy wyznaczniku nie mozna tego robic)
                    double wsp = kopia(k,k);
                    for (int s = 1; s <= kolumny; s++) {
                        kopia(w,s) /= wsp;
                        m(w,s) /= wsp;
                    }
                }
            }
        }
    }
    return m;
}

double Macierz::wyznacznik() throw(nie_jest_kwadratowa) {
    if (wiersze != kolumny) throw nie_jest_kwadratowa("Macierz nie jest kwadratowa, brak wyznacznika");
    double wyzn = 1;
    Macierz t = *this;

    if (wiersze == 1) {
        return t(1,1);
    } else if (wiersze == 2) {
        return t(1,1)*t(2,2)-t(2,1)*t(1,2);
    } else {
        Macierz kopia = t;

        // elementy na przek¹tnej powinny byc niezerowe, a jesli sa to zamieniamy wiersz z wierszem nizej
        for (int k = 1; k <= kolumny; k++) {
            int w = k;
            while (w <= wiersze && kopia(w,k) == 0) w++;

            //zamieniamy wiersze, jesli jest taka potrzeba
            if (w != k) {
                for (int s = 1; s <= kolumny; s++) {
                    std::swap(kopia(k,s), kopia(w,s));
                }
            }

            // czyscimy pozostale wiersze z niezerowych wartosci
            for (int w = k+1; w <= wiersze; w++) {
                if (kopia(w,k) != 0) {
                    double wsp = - kopia(w,k) / kopia(k,k);//

                    for (int s = 1; s <= kolumny; s++) {
                        kopia(w,s) += wsp * kopia(k,s);//
                    }
                }
            }
        }
        for (int i = 1; i <= wiersze; i++)
            wyzn *= kopia(i,i);
    }

    return wyzn;
}

/*
Macierz operator+ (const Macierz &x, const Macierz &y) throw (rozmiary_nie_pasuja) {
    Macierz *m = new Macierz(x);
    for (int i = 0; i < m->wiersze; i++) {
        for (int j = 0; j < m->kolumny; j++) {
            m->macierz[i][j] += y.macierz[i][j];
        }
    }
    return *m;
}
*/

/*
Macierz operator* (double skalar, const Macierz &x) noexcept {
    Macierz m = Macierz(x);
    for (int i = 0; i < m.wiersze; i++) {
        for (int j = 0; j < m.kolumny; j++) {
            m.macierz[i][j] *= skalar;
        }
    }
    return m;
}
*/

/*
Macierz & Macierz::operator!= (const Macierz &y) noexcept {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = y.macierz[j][i];
        }
    }
    return *this;
}

Macierz & Macierz::operator!= (Macierz &&y) throw noexcept {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = move(y.macierz[j][i]);
        }
    }
    return *this;
}
*/
