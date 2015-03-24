#ifndef OPERATOR0ARG_H
#define OPERATOR0ARG_H

#include "wyrazenie.h"

class operator0arg : public wyrazenie {
    public:
        operator0arg();
};

class e : public operator0arg {
    public:
        e ();
        double oblicz ();
        string opis ();
};

class pi : public operator0arg {
    public:
        pi ();
        double oblicz ();
        string opis ();
};

#endif // OPERATOR0ARG_H
