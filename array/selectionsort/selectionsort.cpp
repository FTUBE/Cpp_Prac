#include <iostream>

using namespace std;

const int SIZE = 15;
typedef int ARR[SIZE];

void getarray(ARR a);
void selectionsort(ARR a);
void printarray(ARR c);
void swap(int& a,int& b);
int minimum_from(ARR a, int index);

int main(){
  ARR a1;
  getarray(a1);
  cout << "Before sort: \n";
  printarray(a1);
  selectionsort(a1);
  cout << "\nAfter sort: \n";
  printarray(a1);
  cout << "\n";
}

void printarray(ARR c){
  for(int n = 0 ; n < SIZE; n++){
    cout << c[n] << " ";
    }
}

void selectionsort(ARR a1){
  for(int i = 0; i < SIZE; i++){
    int min_index = minimum_from(a1,i);
    swap(a1[i], a1[min_index]);
  }
}

void swap(int& a,int& b){
  int interm = a;
  a = b;
  b = interm;
}

int minimum_from(ARR a, int index){
  int min = a[index];
  int min_i = index;
  for(int i = index + 1; i < SIZE; i++){
    if(a[i] < min){
      min = a[i];
      min_i = i;
    }
  }
  return min_i;
}

void getarray(ARR a){
  char c;
  for(int i = 0; i < SIZE; i++){
    cout << "Please type the " << i << " element of the array : \n";
    cin >> a[i];
  }
}
