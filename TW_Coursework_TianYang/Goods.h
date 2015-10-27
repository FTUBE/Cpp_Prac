#ifndef GOODS_H
#define GOODS_H

#include <string>

using namespace std;

class Goods{

 private:
  
  const unsigned int pieces;
  const double rate,price,tax;
  const string name;
  double rd_up(double);
  
 public:

  double getTotal();
  double getTax();
  string getName();
  unsigned int getPieces();
  
 Goods(string _name,unsigned int _p,double _price,double _rate): rate(_rate),name(_name),price(_price),pieces(_p),tax(rd_up(price*rate*pieces)){};
  
};

#endif
