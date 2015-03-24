#include <iostream>

#include <cmath>
#include <typeinfo>
#include "newstring.h"

namespace obliczenia {

    newstring::newstring() {
        napis = "";
    }

    newstring::newstring(std::string s) {
        napis = s;
    }

    newstring::~newstring() {
    }

    newstring::newstring(const newstring& ns) {
        napis = ns.napis;
    }

    newstring& newstring::operator=(const newstring& ns) {
        if (this == &ns) return *this;

        napis = ns.napis;
        return *this;
    }

    newstring::newstring (newstring &&ns) {
        napis = ns.napis;
        ns.napis = "";
    }

    newstring& newstring::operator= (newstring&& ns) {
        swap(napis, ns.napis);
        return *this;
    }

    // to_string, istringstream
    newstring::newstring(int w) {
        std::string tmp = "";
        if (w < 0) {
            napis += "-";
            w = -w;
        }

        do {
            tmp += w % 10 + '0';
            w /= 10;
        } while (w != 0);

        for (int i = tmp.length(); i > 0; i--)
            napis += tmp[i-1];
    }

    newstring::newstring(double w) {
        double ulamkowa, calkowita;
        ulamkowa = modf(w, &calkowita);
        newstring l = newstring(static_cast<int>(calkowita));

        if (ulamkowa < 0) ulamkowa = -ulamkowa;
        while (std::fabs((fmod (ulamkowa,1))) > 0.000000001 && std::fabs((fmod (ulamkowa,1))) < 0.99999999) {
            ulamkowa *= 10;
        }

        newstring p = newstring(static_cast<int>(ulamkowa));
        napis = l.napis + "." + p.napis;
    }

    newstring::newstring(bool w) {
        if (w == 0)
            napis = "false";
        else
            napis = "true";
    }

    newstring::newstring(char w) {
        napis = w;
    }

    //!
    newstring::newstring(void* w) {
        int dziesiatkowo = reinterpret_cast<int>(w);

        int tmp;
        while(dziesiatkowo >= 1) {
            tmp = dziesiatkowo % 16;
            if (tmp >= 10)
                napis = static_cast<char>('a' + tmp - 10) + napis;
            else
                napis = static_cast<char>('0' + tmp) + napis;
            dziesiatkowo /= 16;
        }

        napis = "0x" + napis;
    }

    newstring::operator std::string() noexcept {
        return napis;
    }

    newstring::operator int() throw (std::bad_cast()) {
        bool ujemna = false;
        int wynik = 0;
        unsigned int i = 0;

        if (napis[0] == '-') {
            if (napis.length() == 1) throw std::bad_cast();
            ujemna = true;
            i++;
        }

        // while
        for (; i < napis.length(); i++) {
            if (napis[i] < '0' || napis[i] > '9') throw std::bad_cast();
            wynik *= 10;
            wynik += napis[i] - '0';
        }
        return (ujemna ? -wynik : wynik);
    }

    newstring::operator double() throw (std::bad_cast()) {
        bool ujemna = false;
        double wynik = 0, dzielnik = 0;
        unsigned int i = 0;

        if (napis[0] == '-') {
            if (napis.length() == 1) throw std::bad_cast();
            ujemna = true;
            i++;
        }

        while (i < napis.length() && napis[i] != '.') {
            if (napis[i] < '0' || napis[i] > '9') throw std::bad_cast();
            wynik *= 10;
            wynik += static_cast<double>(napis[i] - '0');
            i++;
        }

        for (i = i+1, dzielnik = 10; i < napis.length(); i++, dzielnik *= 10) {
            if (napis[i] < '0' || napis[i] > '9') throw std::bad_cast();
            wynik += static_cast<double>(napis[i] - '0') / dzielnik;
        }

        return (ujemna ? -wynik : wynik);
    }

    newstring::operator bool() throw (std::bad_cast()) {
        if (napis != "true" && napis != "false") throw std::bad_cast();
        if (napis == "true")
            return true;
        else
            return false;
    }

    newstring::operator char() throw (std::bad_cast()) {
        if (napis.length() != 1) throw std::bad_cast();
        return napis[0];
    }

    newstring::operator void*() throw (std::bad_cast()) {
        void* pointer;
        if (napis[0] != '0' || napis[1] != 'x' || napis.length() > 8 || napis.length() <= 2) throw std::bad_cast();
        for (unsigned int i = 2; i < napis.length(); i++)
            if (napis[i] < '0' || napis[i] > '9')
                if (napis[i] < 'a' || napis[i] > 'f')
                    throw std::bad_cast();

        int adres = 0, mnoznik = 1, pom;
        for (int i = napis.length(); i >= 3; i--) {
            pom = static_cast<int>(napis[i-1]);
                if (pom >= 'a')
                    pom -= 'a' - 10;
                else
                    pom -= '0';
            adres += mnoznik*pom;
            mnoznik *= 16;
        }
        pointer = reinterpret_cast<void *>(adres);
        return pointer;
    }

    newstring& newstring::operator+= (const newstring &ns) {
        napis += ns.napis;
        return *this;
    }

    newstring operator+ (const newstring &ns1, const newstring &ns2) {
        return newstring(ns1.napis + ns2.napis);
    }

    bool operator< (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis < ns2.napis);
    }

    bool operator<= (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis <= ns2.napis);
    }

    bool operator> (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis > ns2.napis);
    }

    bool operator>= (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis >= ns2.napis);
    }

    bool operator== (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis == ns2.napis);
    }

    bool operator!= (const newstring &ns1, const newstring &ns2) {
        return (ns1.napis != ns2.napis);
    }

    int newstring::length() const {
        return napis.length();
    }

    newstring& newstring::append(const newstring& ns) {
        napis.append(ns.napis);
        return *this;
    }

    newstring& newstring::insert(unsigned int poz, const newstring& ns) {
        napis.insert(poz, ns.napis);
        return *this;
    }

    newstring& newstring::erase(unsigned int poz, int dl) {
        napis.erase(poz, dl);
        return *this;
    }

    newstring& newstring::replace(unsigned int poz, int dl, const newstring& ns) {
        napis.replace(poz, dl, ns.napis);
        return *this;
    }

    newstring& newstring::substr(unsigned int poz, int dl) {
        napis = napis.substr(poz, dl);
        return *this;
    }

    char& newstring::operator[] (unsigned int poz) {
        if (poz >= napis.length()) // poz < 0
            throw std::string("Poza zakresem");
        return napis[poz];
    }

    const char& newstring::operator[] (unsigned int poz) const {
        if (poz >= napis.length()) // poz < 0
            throw std::string("Poza zakresem");
        return napis[poz];
    }

    std::ostream& operator<< (std::ostream &wy, const newstring &ns) {
        wy << ns.napis;
        return wy;
    }

    newstring operator+ (const newstring &ns, int w) {
        newstring s(ns);
        s += w;
        return s;
    }

    newstring operator+ (const newstring &ns, double w) {
        newstring s(ns);
        s += w;
        return s;
    }

    newstring operator+ (const newstring &ns, bool w) {
        newstring s(ns);
        s += w;
        return s;
    }

    newstring operator+ (const newstring &ns, char w) {
        newstring s(ns);
        s += w;
        return s;
    }

    newstring operator+ (const newstring &ns, void* w) {
        newstring s(ns);
        s += w;
        return s;
    }

    newstring operator+ (int w, const newstring &ns) {
        return ns + w;
    }

    newstring operator+ (double w, const newstring &ns) {
        return ns + w;
    }

    newstring operator+ (bool w, const newstring &ns) {
        return ns + w;
    }

    newstring operator+ (char w, const newstring &ns) {
        return ns + w;
    }

    newstring operator+ (void* w, const newstring &ns) {
        return ns + w;
    }

}
