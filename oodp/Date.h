#ifndef DATE_H
#define DATE_H

class Date{
 public:
  int year, month,day;
  Date(int,int,int);
  void next();
  Date nextDate();
  bool equal(Date);
  void print();
};

#endif
