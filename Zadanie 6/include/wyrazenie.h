#ifndef WYRAZENIE_H
#define WYRAZENIE_H

#include <string>
#include <vector>
//#include <utility> //pair

using namespace std;

class wyrazenie {
    public:
        virtual double oblicz () = 0;
        virtual string opis () = 0;
        virtual ~wyrazenie ();
};

class liczba : public wyrazenie {
    const double wartosc;

    public:
        liczba (double);
        double oblicz (); //virtual
        string opis (); //virtual
};

class zmienna : public wyrazenie {
    string nazwa;
    static vector<pair<string,double>> zmienne;

    public:
        zmienna (string);
        double oblicz (); //virtual
        string opis (); //virtual

        static void dodaj (string, double);
        static double wartosc (string);
        static void usun (string);
};

#endif // WYRAZENIE_H
