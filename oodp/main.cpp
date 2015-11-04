#include "Date.h"
#include <iostream>
using namespace std;

int main(){
  Date* a = new Date(18,1,1992);
  Date b(17,1,1992);
  //  a.print();
  delete a;
  
  Date::c();
  return 0;
}
