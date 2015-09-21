#include <iostream>
#include "structures.h"

using namespace std;

int main(){
  stack a;
  for(int i = 0 ; i < 16; i++){
    a.push(i);
    a.print();
  }
  for(int i = 0 ; i < 16; i++){
    cout << "pop value : " << a.pop();
    a.print();
  }
  //  a.pop();
}
