#ifndef FUNKCJA_H
#define FUNKCJA_H

#include "symbol.h"

class funkcja : public symbol
{
    public:
        funkcja();
        virtual ~funkcja();
        virtual int arnosc () { return 0; }; // noexcept
        virtual bool potrzebny_arg () { return 0; }; //jw
    protected:
    private:
};

#endif // FUNKCJA_H
