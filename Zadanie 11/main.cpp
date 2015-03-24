#include "bufor.h"
#include <iostream>
#include <string>
#include <random>
#include <thread>

const int ilosc_producentow = 3;
const int ilosc_konsumentow = 4;
const int czas_produkcji = 600;
const int czas_konsumpcji = 750;
const int limit_produkcji = 30;
const int rozmiar_bufora = 3;

int losujLiczbe() {
    static std::default_random_engine e{};
    static std::uniform_int_distribution<int> l{1,200000};
    return l(e);
}

void producentBufor(Bufor &b, unsigned int id) {
    while(b.lacznie_wyprodukowano() < limit_produkcji) {
        b.wstaw(losujLiczbe(), id);
        std::this_thread::sleep_for(std::chrono::milliseconds(czas_produkcji));
    }
}

void konsumentBufor(Bufor &b, unsigned int id) {
    while(b.lacznie_wyprodukowano() < limit_produkcji || !b.czy_pusto()) {
        b.pobierz(id);
        std::this_thread::sleep_for(std::chrono::milliseconds(czas_konsumpcji));
    }
}

int main()
{
    try {
        Bufor b(limit_produkcji, rozmiar_bufora);

        std::thread producenci[ilosc_producentow];
        std::thread konsumenci[ilosc_konsumentow];

        for (int i = 0; i < ilosc_producentow; i++)
            producenci[i] = std::thread(producentBufor, std::ref(b), i+1);
        for (int i = 0; i < ilosc_konsumentow; i++)
            konsumenci[i] = std::thread(konsumentBufor, std::ref(b), i+1);

        for (int i = 0; i < ilosc_producentow; i++) {
            producenci[i].join();
        }
        for (int i = 0; i < ilosc_konsumentow; i++)
            konsumenci[i].join();

    //Bufor b2 = b;
    //std::cout << b2.test();

    } catch (std::string w) {
        std::cout << "Wyjatek: " << w;
    }

    return 0;
}
