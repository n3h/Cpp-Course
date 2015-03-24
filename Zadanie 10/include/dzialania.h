#ifndef DZIALANIA_H
#define DZIALANIA_H

#include "funkcja.h"

class dodaj : public funkcja
{
    public:
        dodaj();
        virtual ~dodaj();
        double wartosc () {
            return argumenty[0] + argumenty[1];
        }
        int arnosc() {
            return 2;
        }

        bool potrzebny_arg() {
            return arnosc()-dodane;
        }

        void dodajArgument(double argument) {
            argumenty[dodane++] = argument;
        }
    protected:
    private:
        double* argumenty = new double[2];
        int dodane = 0;
};

#endif // DZIALANIA_H
