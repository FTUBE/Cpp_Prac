#include "Goods.h"

double Goods::getTotal(){
  return price * pieces + tax;
}

string Goods::getName(){
  return name;
}

unsigned int Goods::getPieces(){
  return pieces;
}

double Goods::getTax(){
  return tax;
}

double Goods::rd_up(double tax){
  double doublepart = tax*10;
  double intpart = (int)doublepart;
  double add = 0;
  double fraction = doublepart - intpart;
  if(fraction> 0.5){
    add = 1;
  }
  else if(fraction > 0){
    add = 0.5;
  }
  return (intpart + add)/10;
}
