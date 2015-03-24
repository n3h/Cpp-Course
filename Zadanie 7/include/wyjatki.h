#ifndef WYJATKI_H
#define WYJATKI_H

#include <iostream>
#include <string>
#include <exception>

class zly_rozmiar : public std::exception {
    public:
        zly_rozmiar(std::string wyjatek) noexcept;
        zly_rozmiar(const zly_rozmiar &other) noexcept;
        zly_rozmiar& operator=(const zly_rozmiar& x) noexcept;
        virtual ~zly_rozmiar();
        virtual const char *what() const noexcept;

    protected:
        std::string komunikat;
};

class rozmiary_nie_pasuja : public zly_rozmiar {
    public:
        rozmiary_nie_pasuja(std::string wyjatek) noexcept;
        rozmiary_nie_pasuja(const rozmiary_nie_pasuja &other) noexcept;
        rozmiary_nie_pasuja& operator=(const rozmiary_nie_pasuja& x) noexcept;
        virtual ~rozmiary_nie_pasuja();
        virtual const char *what() const noexcept;
};

class ujemny_rozmiar : public zly_rozmiar {
    public:
        ujemny_rozmiar(std::string wyjatek) noexcept;
        ujemny_rozmiar(const ujemny_rozmiar &other) noexcept;
        ujemny_rozmiar& operator=(const ujemny_rozmiar& x) noexcept;
        virtual ~ujemny_rozmiar();
        virtual const char *what() const noexcept;
};

class nie_jest_kwadratowa : public zly_rozmiar {
    public:
        nie_jest_kwadratowa(std::string wyjatek) noexcept;
        nie_jest_kwadratowa(const nie_jest_kwadratowa &other) noexcept;
        nie_jest_kwadratowa& operator=(const nie_jest_kwadratowa& x) noexcept;
        virtual ~nie_jest_kwadratowa();
        virtual const char *what() const noexcept;
};

class bledne_wspolrzedne : public std::exception {
    public:
        bledne_wspolrzedne(std::string wyjatek) noexcept;
        bledne_wspolrzedne(const bledne_wspolrzedne &other) noexcept;
        bledne_wspolrzedne& operator=(const bledne_wspolrzedne& x) noexcept;
        virtual ~bledne_wspolrzedne();
        virtual const char *what() const noexcept;
    protected:
        std::string komunikat;
};

class zerowy_wyznacznik : public std::exception {
  public:
    zerowy_wyznacznik(std::string wyjatek) noexcept;
    zerowy_wyznacznik(const zerowy_wyznacznik &other) noexcept;
    zerowy_wyznacznik& operator=(const zerowy_wyznacznik& x) noexcept;
    virtual ~zerowy_wyznacznik();
    virtual const char *what() const noexcept;
    protected:
        std::string komunikat;
};

class nieprawidlowe_wejscie : public std::exception {
  public:
    nieprawidlowe_wejscie(std::string wyjatek) noexcept;
    nieprawidlowe_wejscie(const nieprawidlowe_wejscie &other) noexcept;
    nieprawidlowe_wejscie& operator=(const nieprawidlowe_wejscie& x) noexcept;
    virtual ~nieprawidlowe_wejscie();
    virtual const char *what() const noexcept;
    protected:
        std::string komunikat;
};

#endif // WYJATKI_H
