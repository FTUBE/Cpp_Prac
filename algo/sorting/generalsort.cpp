#include <iostream>
#include "sort.h"

using namespace std;

void arrprint(int[]);
const int SIZE = 10;

int main(){
  int Intarr[SIZE] = {8,7,6,5,4,3,2,1,9,1};
  arrprint(Intarr);
  mergesort(Intarr,0,SIZE-1);
  cout << "After sort : \n";
  arrprint(Intarr);
}

void arrprint(int arr[]){
  cout << "[ ";
  for(int i = 0; i < SIZE; i++){
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

