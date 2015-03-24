#ifndef OPERAND_H
#define OPERAND_H
#include "symbol.h"

class operand : public symbol
{
    public:
        operand();
        virtual ~operand();
        virtual int arnosc () { return 0; }; // noexcept
        virtual bool potrzebny_arg () { return 0; }; //jw
    protected:
    private:
};

#endif // OPERAND_H
