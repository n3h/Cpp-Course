#ifndef PLIKWYJSCIOWY_H
#define PLIKWYJSCIOWY_H

#include <iostream>
#include <fstream>

namespace obliczenia {
class PlikWyjsciowy
{
    public:
        PlikWyjsciowy(std::string nazwa);
        ~PlikWyjsciowy();

        bool eof() const { return plik.eof(); }

        void zapiszLinie(std::string linia);
        void zapiszZnak(char znak);
        void zapiszInt(int liczba);
        void zapiszDouble(double liczba);
        void zapiszNowaLinie();

        friend PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, std::string &napis) throw (std::ios_base::failure);
        friend PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, char &znak) throw (std::ios_base::failure);
        friend PlikWyjsciowy & operator<< (PlikWyjsciowy &wy, int &liczba)  throw (std::ios_base::failure);
        friend PlikWyjsciowy & operator<< (PlikWyjsciowy &wy,  double &liczba) throw (std::ios_base::failure);
    private:
        std::ofstream plik;
};
}
#endif // PLIKWYJSCIOWY_H
