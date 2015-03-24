#ifndef PLIKWEJSCIOWY_H
#define PLIKWEJSCIOWY_H

#include <iostream>
#include <fstream>

namespace obliczenia {
    class PlikWejsciowy
    {
    public:
        PlikWejsciowy(std::string nazwa); // throw (std::ios_base::failure)
        ~PlikWejsciowy();

        bool eof() const { return plik.eof(); }

        std::string pobierzLinie();
        char pobierzZnak();
        int pobierzInt();
        double pobierzDouble();

        //bool good(){ return plik.good(); }

        int dalej() {
            return plik.peek();
        }

        friend PlikWejsciowy & operator>> (PlikWejsciowy &we, std::string &napis) throw (std::ios_base::failure);
        friend PlikWejsciowy & operator>> (PlikWejsciowy &we, char &znak) throw (std::ios_base::failure);
        friend PlikWejsciowy & operator>> (PlikWejsciowy &we, int &liczba)  throw (std::ios_base::failure);
        friend PlikWejsciowy & operator>> (PlikWejsciowy &we,  double &liczba) throw (std::ios_base::failure);
    private:
        std::ifstream plik;
    };
}

#endif // PLIKWEJSCIOWY_H
