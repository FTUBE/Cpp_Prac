#include <iostream>
#include "dimensions.h"

using namespace std;

int main(){
  int x,y;
  cout << "Before assigning. X = " << x <<" and Y = " << y << "\n";
  getdimensions(x,y);
  cout << "After assigning. X = " << x <<" and Y = " << y << "\n";
}
