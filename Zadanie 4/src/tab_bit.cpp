//Kamil Bebenek, Kurs jezyka C++, zadanie 4, 31-03-2014
#include "tab_bit.h"
#include <string>

using namespace std;

//Klasa tab_bit
const int tab_bit::rozmiarSlowa = sizeof(slowo)*8;

tab_bit::tab_bit (int rozm) {
    if (rozm < 1) throw string("niedodatni rozmiar tablicy");
    dl = rozm;
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
        tab = new slowo[wielkosc];
        for (int i = 0; i < wielkosc; i++)
            tab[i] = 0;
}

tab_bit::tab_bit (slowo tb) {
    if (tb < 1) throw string("niedodatni rozmiar tablicy");
    dl = rozmiarSlowa;
    tab = new slowo[1];
    tab[0] = 0;
}

tab_bit::tab_bit(const tab_bit& other) {
    dl = other.dl;
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
    tab = new slowo[wielkosc];
    for(int i = 0; i < wielkosc; i++)
        tab[i] = other.tab[i];
}

tab_bit::tab_bit (tab_bit &&tb) {
    tab = tb.tab;
    dl = tb.dl;
    tb.dl = 0;
    tb.tab = nullptr;
}

tab_bit & tab_bit::operator = (const tab_bit &tb){
    if (&tb == this) return *this;

	delete[] tab;

	dl = tb.dl;
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
    tab = new slowo[wielkosc];
    for(int i = 0; i < wielkosc; i++)
        tab[i] = tb.tab[i];

	return *this;
}

tab_bit& tab_bit::operator=(tab_bit &&tb) {
    swap(tab, tb.tab);
    swap(dl,tb.dl);
    return *this;
}

tab_bit::~tab_bit() {
    delete[] tab;
}

bool tab_bit::czytaj (int i) const {
    if (i >= dl) throw string ("za duzy indeks");
    if (i < 0) throw string ("niedodatni indeks");
	return ((tab[i / rozmiarSlowa] >> (i % rozmiarSlowa)) % 2);
}

bool tab_bit::pisz(int i, bool b) {
    if (i >= dl) throw string ("za duzy indeks");
    if (i < 0) throw string ("niedodatni indeks");

    if (czytaj(i)!=b)
        if (b) tab[i / rozmiarSlowa] += (slowo)1 << (i % rozmiarSlowa);
        else tab[i / rozmiarSlowa] -= (slowo)1 << (i % rozmiarSlowa);
    return true;
}

istream & operator >> (istream &we, tab_bit &tb) {
	string wejscie;
	we >> wejscie;

	if (tb.dl < wejscie.length()) throw string("zbyt dlugie wejscie");

	for (int i = 0; i < wejscie.length(); i++) {
        if (wejscie[i]=='0') tb.pisz(i, 0);
        else if (wejscie[i]=='1') tb.pisz(i, 1);
        else throw string("nieprawidlowy znak na wejsciu");
	}

	for (int i = wejscie.length(); i < tb.dl; i++)
        tb.pisz(i, 0);

	return we;
}

ostream & operator << (ostream &wy, const tab_bit &tb) {
    for(int i=0; i < tb.dl; i++)
        wy << tb.czytaj(i);
	return wy;
}

bool tab_bit::operator[] (int i) const {
    if (i >= dl) throw string ("za duzy indeks");
    if (i < 0) throw string ("niedodatni indeks");
    return czytaj(i);
}

tab_bit::ref tab_bit::operator[] (int i) {
    if (i >= dl) throw string ("za duzy indeks");
    if (i < 0) throw string ("niedodatni indeks");
    return ref(this, i);
}

tab_bit& tab_bit::operator|=(const tab_bit &t) {
    if (dl != t.dl) throw string("Rozny rozmiar porownywanych tablic");
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
    for (int i = 0; i < wielkosc; i++)
        tab[i] = tab[i] | t.tab[i];
    return *this;
}

tab_bit& operator | (const tab_bit &t1, const tab_bit &t2) {
    if (t1.dl != t2.dl) throw string("Rozny rozmiar porownywanych tablic");
    tab_bit *t = new tab_bit(t1.dl);
    for(int i = 0; i < t1.dl; i++)
        t->pisz(i, t1[i] | t2[i]);
    return *t;
}

tab_bit& tab_bit::operator &=(const tab_bit &t) {
    if (dl != t.dl) throw string("Rozny rozmiar porownywanych tablic");
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
    for (int i = 0; i < wielkosc; i++)
        tab[i] = tab[i] & t.tab[i];
    return *this;
}

tab_bit& operator & (const tab_bit &t1, const tab_bit &t2) {
    if (t1.dl != t2.dl) throw string("Rozny rozmiar porownywanych tablic");
    tab_bit *t = new tab_bit(t1.dl);
    for(int i = 0; i < t1.dl; i++)
        t->pisz(i, t1[i] & t2[i]);
    return *t;
}

tab_bit& tab_bit::operator ^=(const tab_bit &t) {
    if (dl != t.dl) throw string("Rozny rozmiar porownywanych tablic");
    int wielkosc = (dl % rozmiarSlowa) ? dl/rozmiarSlowa+1 : dl/rozmiarSlowa;
    for (int i = 0; i < wielkosc; i++)
        tab[i] = tab[i] ^ t.tab[i];
    return *this;
}

tab_bit& operator ^ (const tab_bit &t1, const tab_bit &t2) {
    if (t1.dl != t2.dl) throw string("Rozny rozmiar porownywanych tablic");
    tab_bit *t = new tab_bit(t1.dl);
    for(int i = 0; i < t1.dl; i++)
        t->pisz(i, t1[i] ^ t2[i]);
    return *t;
}

tab_bit & operator ! (const tab_bit &t1){
	tab_bit *t = new tab_bit(t1.dl);
	for (int i = 0; i < t1.dl; i++)
		t->pisz(i, !t1[i]);
	return *t;
}

// Klasa ref
tab_bit::ref::operator bool() const {
    return tb->czytaj(indeks);
}

tab_bit::ref::ref(tab_bit* const t, const int i) : tb(t), indeks(i) {}

tab_bit::ref& tab_bit::ref::operator = (bool bit) {
	tb->pisz(indeks, bit);
	return *this;
}

tab_bit::ref& tab_bit::ref::operator = (const ref& t) {
    tb->pisz(indeks, t.tb->czytaj(t.indeks));
    return *this;
}
