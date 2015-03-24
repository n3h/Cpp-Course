#ifndef ZMIENNA_H
#define ZMIENNA_H

#include "operand.h"
#include <map>
#include <string>


class zmienna : public operand
{
    public:
        zmienna(std::string s, double d);
        virtual ~zmienna();
        virtual int arnosc () = 0; // noexcept
        virtual bool potrzebny_arg () = 0; //jw
    protected:
    private:
        static std::map<std::string,double> zmienne;
        // std::string nazwa;
};

#endif // ZMIENNA_H
