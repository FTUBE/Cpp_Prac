#include "Date.h"
#include <iostream>
using namespace std;

int main(){
  Date a(18,1,1992);
  a.print();

  Date b = a.nextDate();
  b.print();

  a.print();
  cout << "==Change the date of a==\n";

  a.next();
  a.print();
  return 0 ;
}
