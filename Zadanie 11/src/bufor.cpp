#include "bufor.h"

Bufor::Bufor(int lim_prod, int rozm_buf) : limit_produkcji(lim_prod), rozmiar_bufora(rozm_buf) {
    if (lim_prod <= 0) throw std::string("niedodatni limit produkcji");
    if (rozm_buf <= 0) throw std::string("niedodatni rozmiar bufora");
    bufor = new int[rozmiar_bufora];
}

Bufor::Bufor(const Bufor& b) : limit_produkcji(b.limit_produkcji), rozmiar_bufora(b.rozmiar_bufora) {
    std::unique_lock<std::mutex> blokada(muteks);
    std::unique_lock<std::mutex> blokada2(b.muteks);
    przod = b.przod;
    tyl = b.tyl;
    licznik = b.licznik;
    bufor = new int[rozmiar_bufora];
    for (int i = 0; i<rozmiar_bufora; i++)
        bufor[i] = b.bufor[i];
    licznik_produkcji = b.licznik_produkcji;
}

Bufor::~Bufor() {
    delete[] bufor;
}

void Bufor::pobierz(int id) {
    std::unique_lock<std::mutex> blokada(muteks); // muteks.lock()

    while (licznik == 0 && (licznik_produkcji < limit_produkcji))
        oczekiwanieK.wait(blokada);
    if (licznik <= 0 ) return ; // przypadek koncowy (gdy konsumentow jest wiecej niz producentow)

    int wartosc = bufor[tyl];
    tyl = (tyl + 1) % rozmiar_bufora;
    licznik--;
    std::cout << "\t\t\t\t\t\t" << "Konsument [" << id << "] pobral " << wartosc << "\n"; //std::this_thread::get_id()

    if (licznik_produkcji != limit_produkcji)
        oczekiwanieP.notify_one();
    else
        oczekiwanieP.notify_all();
}

void Bufor::wstaw(int wartosc, int id) {
    std::unique_lock<std::mutex> blokada(muteks);

    while (licznik == rozmiar_bufora && (licznik_produkcji < limit_produkcji))
        oczekiwanieP.wait(blokada);
    if (licznik_produkcji >= limit_produkcji) { return ; } // przypadek koncowy (gdy producentow jest wiecej niz konsumentow)

    bufor[przod] = wartosc;
    przod = (przod + 1) % rozmiar_bufora;
    licznik_produkcji++;
    std::cout << "Producent [" << id << "] wyprodukowal " << wartosc << " (" << licznik_produkcji << ". element)" << "\n"; //std::this_thread::get_id()
    licznik++;

    if (licznik_produkcji != limit_produkcji)
        oczekiwanieK.notify_one();
    else
        oczekiwanieK.notify_all();
}

int Bufor::lacznie_wyprodukowano() {
    std::lock_guard<std::mutex> blokada(muteks);
    return licznik_produkcji;
}

bool Bufor::czy_pusto() {
    std::lock_guard<std::mutex> blokada(muteks);
    return (licznik <= 0);
}
