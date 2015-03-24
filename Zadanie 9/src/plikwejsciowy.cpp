#include "plikwejsciowy.h"

namespace obliczenia {

    PlikWejsciowy::PlikWejsciowy(std::string nazwa) {
        plik.exceptions(std::ios::failbit | std::ios::badbit);
        plik.open(nazwa.c_str(), std::ios::in);
        if(!plik.is_open()) throw std::ios_base::failure("Nie mozna otworzyc pliku");
    }

    PlikWejsciowy::~PlikWejsciowy() {
        plik.close(); // if(plik.is_open())
    }

    std::string PlikWejsciowy::pobierzLinie() {
        std::string linia;
        std::getline(plik, linia);
        return linia;
    }

    char PlikWejsciowy::pobierzZnak() {
        char znak = plik.get();
        return znak;
    }

            //while (znak == '\n' || znak == 13 || znak == 20)
        //    plik >> znak;
        //znak = plik.get();
      /*  if (plik.good() && !plik.eof() && !plik.fail()u)
            znak = plik.get();
        if (!plik.good() || plik.eof())
            znak = 's';
        */
        //plik.unsetf(std::ios_base::skipws);
        //plik >> znak; //std::noskipws >>
        //if (plik >> std::noskipws >> znak)
        //    return znak;
        /*
        if (plik.get(znak)) ;
        else {
            znak = 'z';
        }
        std::cout << "znak: " << znak << std::endl;
        */
        //plik.exceptions(); //  && plik.good() && plik && std::ifstream::failbit
   //     try {
      //  if (!plik.eof()) { // while 10 13
        //    plik.get(znak);
            //    plik >> znak;
          //      if (znak == 10 || znak == 13) { plik.get(znak); }
      //  }
     //   } catch (std::ios_base::failure const& f) { std::cout << "-!-"; }
    // std::cout << "-!-" << znak;

    int PlikWejsciowy::pobierzInt() {
        int liczba;
        plik >> liczba;
        return liczba;
    }

    double PlikWejsciowy::pobierzDouble() {
        double liczba;
        plik >> liczba;
        return liczba;
    }

    // std::istream
    PlikWejsciowy & operator>> (PlikWejsciowy &we, std::string &napis) throw (std::ios_base::failure) {
        napis = we.pobierzLinie();
        return we;
    }

    PlikWejsciowy & operator>> (PlikWejsciowy &we, char &znak) throw (std::ios_base::failure) {
        znak = we.pobierzZnak();
        return we;
    }

    PlikWejsciowy & operator>> (PlikWejsciowy &we, int &liczba)  throw (std::ios_base::failure) {
        liczba = we.pobierzInt();
        return we;
    }

    PlikWejsciowy & operator>> (PlikWejsciowy &we,  double &liczba) throw (std::ios_base::failure) {
        liczba = we.pobierzDouble();
        return we;
    }

}
