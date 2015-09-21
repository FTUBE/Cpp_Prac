#include <iostream>

using namespace std;

void printCarr(char[]);

int main(){
  char arr[] = "abcdefghi";
  char *arr_ptr = arr; 
  printCarr(arr_ptr);
}

void printCarr(char arr[]){
  int i = 0;
  while(arr[i] != '\0'){
    cout << arr[i];
    i++;
  }
  cout << endl;
}
