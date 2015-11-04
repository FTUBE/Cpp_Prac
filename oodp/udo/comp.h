#ifndef COMP_H
#define COMP_H
#include <iostream>

using namespace std;

class Comp{
  double re,im;

 public:

  Comp(double,double);

  friend Comp operator+(const Comp&, const Comp&);

  friend ostream& operator<<(ostream&,const Comp&);
};

#endif
