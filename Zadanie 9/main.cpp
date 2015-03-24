#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//#include <algorithm>

#include "manipulatory.h"
#include "plikwejsciowy.h"
#include "plikwyjsciowy.h"

void zad1() {
    std::cin >> obliczenia::clearline >> obliczenia::ignore(2);

    std::vector< std::pair<std::string,int> > tekst;

    int licznik = 0;
    while (std::cin){
        std::string linia;
        std::getline(std::cin, linia);
        licznik++;
        //if (linia[0] != 26) // ctrl+z
            tekst.push_back(std::make_pair(linia, licznik));
    }
    tekst.pop_back();

    //std::sort(tekst.begin(),tekst.end());
    obliczenia::babelkowe(tekst);

    std::stringstream s;
    s << licznik;
    int dlugosc = s.str().length();

    for(unsigned int i = 0; i < tekst.size(); i++) {
        std::cout << obliczenia::index(tekst[i].second, dlugosc) << obliczenia::colon << tekst[i].first << std::endl;
    }

    tekst.clear();

    std::cout << std::endl << "Comma: " << obliczenia::comma << std::endl;
}

void zad2() {
    //! string
    std::cout << std::endl << "===== Test stringow =====" << std::endl;
    std::vector<std::string> stringi;
    std::string str;
    obliczenia::PlikWejsciowy plik1S("testString.txt");
    obliczenia::PlikWyjsciowy plik2S("zapiszString.txt");

    std::cout << "Wczytywanie: " << std::endl;
    while(!plik1S.eof()) {
        plik1S >> str;
        stringi.push_back(str);
        std::cout << str << std::endl;
    }

    std::cout << "Zapisywanie: " << std::endl;
    for(int i = stringi.size(); i > 0; i--) {
        std::cout << stringi.back() << std::endl;
        plik2S << stringi.back();
        stringi.pop_back();
        plik2S.zapiszNowaLinie();
    }

    //! char
    std::cout << std::endl << "===== Test char-ow =====" << std::endl;
    std::vector<char> znaki;
    char znak;
    obliczenia::PlikWejsciowy plik1Z("testChar.txt");
    obliczenia::PlikWyjsciowy plik2Z("zapiszChar.txt");

    std::cout << "Wczytywanie: " << std::endl;
    while(!plik1Z.eof() && plik1Z.dalej() >= 0 && plik1Z.dalej() < 128) { // && plik1Z.good()
        plik1Z >> znak;
        if (znak != 13 && znak != 10 && znak != 0 && znak != 32) { // lf, cr, null, spacja
            znaki.push_back(znak);
            std::cout << znak << std::endl;
        }
    }

    std::cout << "Zapisywanie: " << std::endl;
    for(int i = znaki.size(); i > 0; i--) {
        std::cout << znaki.back() << std::endl;
        plik2Z << znaki.back();
        znaki.pop_back();
        plik2Z.zapiszNowaLinie();
    }

    //! int
    std::cout << std::endl << "===== Test calkowitych =====" << std::endl;
    std::vector<int> calkowite;
    int calk;
    obliczenia::PlikWejsciowy plik1C("testInt.txt");
    obliczenia::PlikWyjsciowy plik2C("zapiszInt.txt");

    std::cout << "Wczytywanie: " << std::endl;
    while(!plik1C.eof()) {
        plik1C >> calk;
        calkowite.push_back(calk);
        std::cout << calk << std::endl;
    }

    std::cout << "Zapisywanie: " << std::endl;
    for(int i = calkowite.size(); i > 0; i--) {
        std::cout << calkowite.back() << std::endl;
        plik2C << calkowite.back();
        calkowite.pop_back();
        plik2C.zapiszNowaLinie();
    }

    //! double
    std::cout << std::endl << "===== Test rzeczywistych =====" << std::endl;
    std::vector<double> rzeczywiste;
    double rzecz;
    obliczenia::PlikWejsciowy plik1D("testDouble.txt");
    obliczenia::PlikWyjsciowy plik2D("zapiszDouble.txt");

    std::cout << "Wczytywanie: " << std::endl;
    while(!plik1D.eof()) {
        plik1D >> rzecz;
        rzeczywiste.push_back(rzecz);
        std::cout << rzecz << std::endl;
    }

    std::cout << "Zapisywanie: " << std::endl;
    for(int i = rzeczywiste.size(); i > 0; i--) {
        std::cout << rzeczywiste.back() << std::endl;
        plik2D << rzeczywiste.back();
        rzeczywiste.pop_back();
        plik2D.zapiszNowaLinie();
    }
/*
    std::cout << "Zapisywanie: " << std::endl;
    for(int i = rzeczywiste.size() - 1; i >= 0; i--) {
        std::cout << rzeczywiste[i] << std::endl;
        //plik2D << rzeczywiste[i];
        plik2D << rzeczywiste.back();
        plik2D.zapiszNowaLinie();
    }
*/
}

int main() {
    try {
    zad1();
    zad2();

    } catch(std::ios_base::failure e) {
        std::cerr << e.what() << std::endl;

    } catch (std::string blad) {
        std::cerr << blad;
    }

    return 0;
}
