#include <iostream>
#include "sort.h"

using namespace std;

void arrprint(int[]);
const int SIZE = 15;

int main(){
  int Intarr[SIZE] = {8,7,6,5,4,3,2,1,0,1,5,4,5,4,2};
  arrprint(Intarr);
  quicksort(Intarr,0,SIZE-1);
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

