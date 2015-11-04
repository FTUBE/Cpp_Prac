#include "comp.h"
#include <iostream>

Comp::Comp(double _re, double _im){
  re = _re;
  im = _im;
};

Comp operator+(const Comp& a, const Comp& b){
  Comp toret(a.re+b.re,a.im+b.im);
  return toret;
}
ostream& operator<<(ostream& o, const Comp& a){
  o << a.re<<" + " <<a.im<<"i";
  return o;
}
