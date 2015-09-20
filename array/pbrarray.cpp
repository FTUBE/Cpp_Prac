#include <iostream>

using namespace std;
const int SIZE = 5;
typedef char C_ARRAY[SIZE];
void cpy_arr(C_ARRAY from, C_ARRAY to);
void printarray(C_ARRAY c);

int main(){
  C_ARRAY c1;
  C_ARRAY c2;
  for(int i = 0; i < SIZE; i++){
    c1[i] = 'a' + i;
  }
  cout << "Before copy. \nc1 :";
  printarray(c1);
  cout << "\n";
  cout << "c2 : ";
  printarray(c2);
  cout << "\n";
  
  cout << "Copying............\n";
  cpy_arr(c1,c2);
  
  cout << "After copy. \nc1 :";
  printarray(c1);
  cout << "\n";
  cout << "c2 :";
  printarray(c2);
  cout << "\n";
}

void cpy_arr(C_ARRAY from, C_ARRAY to){
  for(int i = 0; i < SIZE; i++){
    to[i] = from[i];
  }
}

void printarray(C_ARRAY c){
  for(int n = 0 ; n < SIZE; n++){
    cout << c[n] << ",";
    }
}
