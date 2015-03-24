#ifndef OPERATOR2ARG_H
#define OPERATOR2ARG_H

#include "operator1arg.h"

class operator2arg : public operator1arg {
    public:
        operator2arg(wyrazenie *, wyrazenie *);
        virtual ~operator2arg();
    protected:
        wyrazenie *argument2;
};

class dodaj : public operator2arg {
    public:
        dodaj (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class logarytm : public operator2arg {
    public:
        logarytm (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class odejmij : public operator2arg {
    public:
        odejmij (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class modulo : public operator2arg {
    public:
        modulo (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class mnoz : public operator2arg {
    public:
        mnoz (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class potega : public operator2arg {
    public:
        potega (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

class dziel : public operator2arg {
    public:
        dziel (wyrazenie *, wyrazenie *);
        double oblicz ();
        string opis ();
};

#endif // OPERATOR2ARG_H
