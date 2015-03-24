#ifndef MANIPULATORY_H
#define MANIPULATORY_H

#include <iostream>
#include <vector>

namespace obliczenia {
    //we
    std::istream & clearline (std::istream &we);

    class ignore {
    public:
        ignore (int ile);
        friend std::istream & operator>> (std::istream &we, const ignore &x);
    private:
        int indeks;
    };

    //wy
    std::ostream & comma (std::ostream &wy);
    std::ostream & colon (std::ostream &wy);

    class index {
    public:
        index (int x, int z);
        friend std::ostream & operator<< (std::ostream &wy, const index &x);
    private:
        int liczba, pozycja;
    };

    //inne
    void babelkowe(std::vector<std::pair<std::string, int> >& t);
}

#endif // MANIPULATORY_H
