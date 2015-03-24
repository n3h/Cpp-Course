#include "plikwyjsciowy.h"

namespace obliczenia {

    PlikWyjsciowy::PlikWyjsciowy(std::string nazwa) {
        plik.exceptions(std::ios::failbit | std::ios::badbit);
        plik.open(nazwa.c_str(), std::ios::out | std::ios::trunc);
        if(!plik.is_open()) throw std::ios_base::failure("Nie mozna otworzyc pliku");
    }

    PlikWyjsciowy::~PlikWyjsciowy() {
        plik.close(); // if(plik.is_open())
    }

    void PlikWyjsciowy::zapiszLinie(std::string linia) {
        plik << linia;
    }

    void PlikWyjsciowy::zapiszZnak(char znak) {
        plik.put(znak);
    }

    void PlikWyjsciowy::zapiszInt(int liczba) {
        plik << liczba;
    }

    void PlikWyjsciowy::zapiszDouble(double liczba) {
        plik << liczba;
    }

    void PlikWyjsciowy::zapiszNowaLinie() {
        plik << "\n";
    }

    //std::ostream
    PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, std::string &napis) throw (std::ios_base::failure) {
        wy.zapiszLinie(napis);
        return wy;
    }

    PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, char &znak) throw (std::ios_base::failure) {
        wy.zapiszZnak(znak);
        return wy;
    }

    PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, int &liczba)  throw (std::ios_base::failure) {
        wy.zapiszInt(liczba);
        return wy;
    }

    PlikWyjsciowy & operator<< (PlikWyjsciowy &wy,  double &liczba) throw (std::ios_base::failure) {
        wy.zapiszDouble(liczba);
        return wy;
    }

}
