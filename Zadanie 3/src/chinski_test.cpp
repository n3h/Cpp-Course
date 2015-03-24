#include "chinski_test.hpp"

//a * b mod n
long long mnoz(long long a, long long b, long long n) {
  long long m,w;

  w = 0; m = 1;
  while(m)
  {
    if(b & m) w = (w + a) % n;
    a = (a << 1) % n;
    m <<= 1;
  }
  return w;
}

//2^e mod n
long long poteguj(long long e, long long n)
{
  long long m,p,w;

  p = 2; w = m = 1;
  while(m)
  {
    if(e & m) w = mnoz(w,p,n);
    p = mnoz(p,p,n);
    m <<= 1;
  }
  return w;
}
