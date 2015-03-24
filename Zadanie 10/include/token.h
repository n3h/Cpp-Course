#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class token
{
    public:
        token(std::string s) : rodzaj(s), w(0);
        token(std::string s, double d) : rodzaj(s), w(d);
        virtual ~token();
    protected:
    private:
        std::string rodzaj;
        double w;

};

#endif // TOKEN_H
