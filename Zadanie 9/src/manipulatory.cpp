#include "manipulatory.h"
#include <iomanip> // setw

namespace obliczenia {
    //we
    std::istream & clearline (std::istream &we) {
        while (we.get() != '\n' && !we.eof()) ; //lub && we
        return we;
    }

    ignore::ignore (int ile) : indeks(ile) {}

    std::istream & operator>> (std::istream &we, const ignore &x) {
        int zmienna = 1;
        while(we.get() != '\n' && !we.eof() && zmienna <= x.indeks) zmienna++;
        return we;
    }

    //wy
    std::ostream & comma (std::ostream &wy) {
        return wy << ", ";
    }

    std::ostream & colon (std::ostream &wy) {
        return wy << ": ";
    }

    index::index (int x, int z) : liczba(x), pozycja(z) {}

    std::ostream & operator<< (std::ostream &wy, const index &x) {
        wy << "[" << std::setw(x.pozycja) << std::right << x.liczba << "]";
        return wy;
    }

    //inne
    void babelkowe(std::vector<std::pair<std::string, int> > &t) {
        for(unsigned i = 0; i < t.size()-1; i++)
            for(unsigned j = 0; j < t.size()-1-i; j++)
                if(t[j].first > t[j + 1].first)
                    std::swap(t[j], t[j + 1]);
    }
}
