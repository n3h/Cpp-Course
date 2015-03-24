//Kamil Bebenek, Kurs jezyka C++, zadanie 1, 10-03-2014
#include <string>
#include <cmath>
#include "punkt2D.h"
#include "odcinek2D.h"
#include "funkcje_globalne.h"

using namespace std;

//x1*y2-y1*x2=0
bool czy_rownolegle (odcinek2D &a, odcinek2D &b) {
    punkt2D wektor_a(a.q.x - a.p.x, a.q.y - a.p.y);
    punkt2D wektor_b(b.q.x - b.p.x, b.q.y - b.p.y);
    return (abs(wektor_a.x*wektor_b.y - wektor_a.y*wektor_b.x) <= blad);
}

//x1*x2+y1*y2=0;
bool czy_prostopadle (odcinek2D &a, odcinek2D &b) {
    punkt2D wektor_a(a.q.x - a.p.x, a.q.y - a.p.y);
    punkt2D wektor_b(b.q.x - b.p.x, b.q.y - b.p.y);
    return (abs(wektor_a.x*wektor_b.x + wektor_a.y*wektor_b.y) <= blad);
}

int iloczyn(punkt2D &p1, punkt2D &p2, punkt2D &p3) {
    return ( (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y) );
}

bool lezy_miedzy(punkt2D &p1, punkt2D &p2, punkt2D &p3) {
    if (min(p1.x,p2.x) <= p3.x && p3.x <= max(p1.x,p2.x)) return true;
    else return false;
}

bool czy_przecinaja_sie(odcinek2D &a, odcinek2D &b) {
	int il1, il2, il3, il4;
	il1 = iloczyn(a.p, b.p, a.q);
	il2 = iloczyn(a.p, b.q, a.q);
	il3 = iloczyn(b.p, a.p, b.q);
	il4 = iloczyn(b.p, a.q, b.q);
	if ((il1*il2 < 0) && (il3*il4 < 0)) return true;
	else if (abs(il1) <= blad && lezy_miedzy(a.p, a.q, b.p)) return true;
	else if (abs(il2) <= blad && lezy_miedzy(a.p, a.q, b.q)) return true;
	else if (abs(il3) <= blad && lezy_miedzy(b.p, b.q, a.p)) return true;
	else if (abs(il4) <= blad && lezy_miedzy(b.p, b.q, a.q)) return true;
	else return false;
}
