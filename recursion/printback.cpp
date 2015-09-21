#include <iostream>

using namespace std;

void printback();

int main(){
  printback();
  cout << endl;
}

void printback(){
  char c;
  cout << "Type in a character : "<< endl;
  cin >> c;
  if(c != '.'){
    printback();
    cout << c << " ";
  }
}
