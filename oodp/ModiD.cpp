#include "ModiD.h"
#include "Date.h"
#include <iostream>

using namespace std;

void ModiD::modi(Date& d){
  cout << d.day << endl;
  d.day++;
  cout << d.day << endl;
};

void ModiD::anothermodi(Date& d){
  cout << d.day;
}
