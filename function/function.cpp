#include <iostream>

using namespace std;

const float PI = 3.1415926535;

int drawCircle(float diameter);

int main()
{
  float radius = 0;
  cout << "Type in the radius of the circle.\n";
  cin >> radius;
  drawCircle(radius*2);
  return 0;
}

int drawCircle(float diameter){
  float radius = 0;
  float area = 0;
  radius = diameter/2;
  cout.width(20);
  cout << "The radius is : " << radius << "\n";
  cout.width(20);
  cout << "Diameter is : " << radius*2 << "\n";
  area = PI*radius*radius;
  cout.width(20);
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "Area : " << area << "\n";
  return 0;
}
