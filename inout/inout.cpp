#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

  int number;
  enum {MON=1, TUES,WED,THURS,FRI,SAT=-1,SUN};
  cout << "Type in a number\n";
  cin >> number;
  cout.setf(ios::scientific);
  cout.precision(2);
  cout << "The number is : " << number << "\nThe sqrt is : "<<sqrt(number)<<"\n";

  //Format and enum;

  /*  cout.width(20);
  cout<<MON<<"\n";
  cout.width(20);
  cout<<TUES<<"\n";
  cout.width(20);
  cout<<WED<<"\n";
  cout.width(20);
  cout<<THURS<<"\n";
  */
  return 0;
}
