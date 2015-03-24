#include "wyjatki.h"

zly_rozmiar::zly_rozmiar(std::string wyjatek) noexcept : komunikat(wyjatek) {}
zly_rozmiar::zly_rozmiar(const zly_rozmiar &other) noexcept : komunikat(other.komunikat) {}
zly_rozmiar& zly_rozmiar::operator=(const zly_rozmiar& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
zly_rozmiar::~zly_rozmiar() noexcept { }
const char* zly_rozmiar::what() const noexcept {
    return komunikat.c_str();
}

rozmiary_nie_pasuja::rozmiary_nie_pasuja(std::string wyjatek) noexcept : zly_rozmiar(wyjatek) {}
rozmiary_nie_pasuja::rozmiary_nie_pasuja(const rozmiary_nie_pasuja &other) noexcept : zly_rozmiar(other.komunikat) {}
rozmiary_nie_pasuja& rozmiary_nie_pasuja::operator=(const rozmiary_nie_pasuja& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
rozmiary_nie_pasuja::~rozmiary_nie_pasuja() { }
const char* rozmiary_nie_pasuja::what() const noexcept {
    return komunikat.c_str();
}

ujemny_rozmiar::ujemny_rozmiar(std::string wyjatek) noexcept : zly_rozmiar(wyjatek) {}
ujemny_rozmiar::ujemny_rozmiar(const ujemny_rozmiar &other) noexcept : zly_rozmiar(other.komunikat) {}
ujemny_rozmiar& ujemny_rozmiar::operator=(const ujemny_rozmiar& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
ujemny_rozmiar::~ujemny_rozmiar() { }
const char* ujemny_rozmiar::what() const noexcept {
    return komunikat.c_str();
}

nie_jest_kwadratowa::nie_jest_kwadratowa(std::string wyjatek) noexcept : zly_rozmiar(wyjatek) {}
nie_jest_kwadratowa::nie_jest_kwadratowa(const nie_jest_kwadratowa &other) noexcept : zly_rozmiar(other.komunikat) {}
nie_jest_kwadratowa& nie_jest_kwadratowa::operator=(const nie_jest_kwadratowa& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
nie_jest_kwadratowa::~nie_jest_kwadratowa() { }
const char* nie_jest_kwadratowa::what() const noexcept {
    return komunikat.c_str();
}

bledne_wspolrzedne::bledne_wspolrzedne(std::string wyjatek) noexcept : komunikat(wyjatek) {}
bledne_wspolrzedne::bledne_wspolrzedne(const bledne_wspolrzedne &other) noexcept : komunikat(other.komunikat) {}
bledne_wspolrzedne& bledne_wspolrzedne::operator=(const bledne_wspolrzedne& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
bledne_wspolrzedne::~bledne_wspolrzedne() noexcept { }
const char* bledne_wspolrzedne::what() const noexcept {
    return komunikat.c_str();
}

zerowy_wyznacznik::zerowy_wyznacznik(std::string wyjatek) noexcept : komunikat(wyjatek) {}
zerowy_wyznacznik::zerowy_wyznacznik(const zerowy_wyznacznik &other) noexcept : komunikat(other.komunikat) {}
zerowy_wyznacznik& zerowy_wyznacznik::operator=(const zerowy_wyznacznik& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
zerowy_wyznacznik::~zerowy_wyznacznik() noexcept { }
const char* zerowy_wyznacznik::what() const noexcept {
    return komunikat.c_str();
}

nieprawidlowe_wejscie::nieprawidlowe_wejscie(std::string wyjatek) noexcept : komunikat(wyjatek) {}
nieprawidlowe_wejscie::nieprawidlowe_wejscie(const nieprawidlowe_wejscie &other) noexcept : komunikat(other.komunikat) {}
nieprawidlowe_wejscie& nieprawidlowe_wejscie::operator=(const nieprawidlowe_wejscie& x) noexcept {
    if (this == &x) return *this;
    komunikat = x.komunikat;
    return *this;
}
nieprawidlowe_wejscie::~nieprawidlowe_wejscie() noexcept { }
const char* nieprawidlowe_wejscie::what() const noexcept {
    return komunikat.c_str();
}
