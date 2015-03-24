#ifndef BUFOR_H
#define BUFOR_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Bufor {
    private:
        const int limit_produkcji;
        const int rozmiar_bufora;
        int przod = 0, tyl = 0, licznik = 0;
        int* bufor;
        mutable std::mutex muteks;
        std::condition_variable oczekiwanieK, oczekiwanieP;
        int licznik_produkcji = 0;

    public:
        Bufor(const int lim_prod, int rozm_buf);
        Bufor(const Bufor&);
        Bufor& operator=(const Bufor&) = delete;
        Bufor (Bufor &&tb) = delete;
        Bufor & operator = (Bufor &&tb) = delete;
        ~Bufor();
        void pobierz(int id);
        void wstaw(int wartosc, int id);
        int lacznie_wyprodukowano();
        bool czy_pusto();
        //int test() { return bufor[2]; }
};

#endif // BUFOR_H
