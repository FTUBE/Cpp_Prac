#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <vector>
#include "Goods.h"
#include <fstream>

const int MAXLENGTH = 512;
const int WORD = 128;

class Receipt{

 private:

  int counts;
  vector<Goods*> items;
  vector<string> dicExem;
 
  Goods* goodsFactory(char*);
  bool isExem(string);

  void loadDic();

 public:

  void loadGoodsFromFile(string);
  void printTotal();

 Receipt():counts(0){};
  ~Receipt();
};
#endif
