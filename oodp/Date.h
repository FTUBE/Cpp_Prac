#ifndef DATE_H
#define DATE_H
#include "ModiD.h"

class Date{

  int year, month,day;
  static int counter;
 public:
  Date(int=18,int=1,int=1992);
  ~Date();
  void next();
  Date nextDate() const;
  bool equal(Date);
  void print() const;
  friend void ModiD::modi(Date&);
  friend void ModiD::anothermodi(Date&);
  static void c();
};

#endif
