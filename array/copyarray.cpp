#include <iostream>

using namespace std;

const int SIZE = 5;
typedef char C_ARRAY[SIZE];
void printarray(C_ARRAY c);

int main(){
  C_ARRAY c1;
  C_ARRAY c2;
  
  for(int i = 0; i < SIZE; i++){
    c1[i] = 'a' + i;
  }
  cout << "c1: "; 
  printarray(c1);
  cout << "\nCopying.............\n";
  for(int i = 0; i < SIZE; i++){
    c2[i] = c1[i];
  }
  cout << "c2: "; 
  printarray(c2);
  cout << "\n"; 
  return 0;
}

void printarray(C_ARRAY c){
  for(int n = 0 ; n < SIZE; n++){
    cout << c[n] << ",";
    }
}
