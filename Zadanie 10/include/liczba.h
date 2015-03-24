#ifndef LICZBA_H
#define LICZBA_H

#include "operand.h"

class liczba : public operand
{
    public:
        liczba(double wartosc);
        double wartosc() { return l; };
        virtual int arnosc () = 0; // noexcept
        virtual bool potrzebny_arg () = 0; //jw
        //virtual ~liczba();
    protected:
    private:
        double l;
};

#endif // LICZBA_H
