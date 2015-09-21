#include <iostream>
#include <cstdlib>

using namespace std;

int factorial(int);

int main(){
  cout << "Number : " << endl;
  int n;
  cin >> n;
  cout << "Factorial of " << n << " is " << factorial(n) << endl;
}

int factorial(int n){
  if(n < 0){
    cout << "Undef." << endl;
    exit(1);
  }
  if(n == 0){
    return 1;
  }
  return n*(factorial(n-1));
}
