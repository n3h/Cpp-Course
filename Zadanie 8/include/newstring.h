#ifndef NEWSTRING_H
#define NEWSTRING_H

#include <string>
#include <sstream>

namespace obliczenia {
class newstring
{
    public:
        newstring();
        newstring(std::string s);
        virtual ~newstring();

        newstring(const newstring& other);
        newstring& operator= (const newstring& other);

        newstring (newstring &&ns);
        newstring& operator= (newstring&& ns);

        //konstruktory konwertujace
        newstring(int);
        newstring(double);
        newstring(bool);
        newstring(char);
        newstring(void*);

        //operatory konwersji
        operator std::string() noexcept;
        operator int() throw (std::bad_cast());
        operator double() throw (std::bad_cast());
        operator bool() throw (std::bad_cast());
        operator char() throw (std::bad_cast());
        operator void*() throw (std::bad_cast());

        // operatory konkatenacji
        newstring& operator+= (const newstring &ns); //!
        friend newstring operator+ (const newstring &ns1, const newstring &ns2);

        //10
        friend newstring operator+ (const newstring &ns, int w);
        friend newstring operator+ (const newstring &ns, double w);
        friend newstring operator+ (const newstring &ns, bool w);
        friend newstring operator+ (const newstring &ns, char w);
        friend newstring operator+ (const newstring &ns, void* w);

        friend newstring operator+ (int w, const newstring &ns);
        friend newstring operator+ (double w, const newstring &ns);
        friend newstring operator+ (bool w, const newstring &ns);
        friend newstring operator+ (char w, const newstring &ns);
        friend newstring operator+ (void* w, const newstring &ns);

        // porownywanie
        friend bool operator< (const newstring &ns1, const newstring &ns2);
        friend bool operator<= (const newstring &ns1, const newstring &ns2);
        friend bool operator> (const newstring &ns1, const newstring &ns2);
        friend bool operator>= (const newstring &ns1, const newstring &ns2);
        friend bool operator== (const newstring &ns1, const newstring &ns2);
        friend bool operator!= (const newstring &ns1, const newstring &ns2);

        // length, append, erase, replace, substr, operator[]
        int length() const;
        newstring& append(const newstring& ns);
        newstring& insert(unsigned int poz, const newstring& ns);
        newstring& erase(unsigned int poz, int dl);
        newstring& replace(unsigned int poz, int dl, const newstring& ns);
        newstring& substr(unsigned int poz, int dl);

        char& operator[] (unsigned int poz);
        const char& operator[] (unsigned int poz) const;

        friend std::ostream& operator << (std::ostream &wy, const newstring &ns);

    private:
        std::string napis;
};
}

#endif // NEWSTRING_H
