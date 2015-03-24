#ifndef OPERATOR1ARG_H
#define OPERATOR1ARG_H

#include "operator0arg.h"

class operator1arg : public operator0arg {
    public:
        operator1arg(wyrazenie *);
        virtual ~operator1arg();
    protected:
        wyrazenie *argument1;
};

class przec_znak : public operator1arg {
    public:
        przec_znak (wyrazenie *);
        double oblicz ();
        string opis ();
};

class wart_bezw : public operator1arg {
    public:
        wart_bezw (wyrazenie *);
        double oblicz ();
        string opis ();
};

class sin : public operator1arg {
    public:
        sin (wyrazenie *);
        double oblicz ();
        string opis ();
};

class cos : public operator1arg {
    public:
        cos (wyrazenie *);
        double oblicz ();
        string opis ();
};

#endif // OPERATOR1ARG_H
