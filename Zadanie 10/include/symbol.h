#ifndef SYMBOL_H
#define SYMBOL_H

//abstrakcyjna! ciag symboli = wyrazenie ONP
class symbol
{
    public:
        symbol();
        virtual ~symbol();

        virtual double wartosc () = 0; //throw (logic_error) // obliczwartosc
        virtual int arnosc () { return 0; }; // noexcept
        virtual bool potrzebny_arg () { return 0; }; //jw
        virtual void dodaj_arg (double arg) = 0; // throw (logic_error)

    protected:
    private:
};

#endif // SYMBOL_H
