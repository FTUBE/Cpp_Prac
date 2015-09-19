#include <iostream>

using namespace std;

void getdimensions(int& x,int& y);

int main(){
  int x,y;
  cout << "Before assigning. X = " << x <<" and Y = " << y << "\n"; 
  getdimensions(x,y);
  cout << "After assigning. X = " << x <<" and Y = " << y << "\n";
}

void getdimensions(int& x, int& y){
  cout << "Please type x universe :\n";
  cin >> x;
  cout << "Please type y universe :\n";
  cin >> y;
}

