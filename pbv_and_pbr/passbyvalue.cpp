#include <iostream>
#include <cmath>
using namespace std;

int factorial(int number);

int main(){
  int number;
  cout << "Please type in a number :\n";
  cin >> number;
  cout << "The number is : " << number << "\n";
  cout << "sqrt is : " << sqrt(number) << "\n";
  cout << "factorial is : " << factorial(number) << "\n";
}

int factorial(int number){

  int product = 1;
  
  for(;number>1;number--){
    product *= number; 
  }
  return product;
}
