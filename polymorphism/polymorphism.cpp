#include <iostream>

using namespace std;

float avg(int x,int y);
float avg(int x,int y,int z);

int main(){
  enum{a,b,c,d,e};
  cout << "AVG of 0,1 is : " << avg(a,b) << "\n";
  cout << "AVG of 0,1,2 is : " << avg(a,b,c) << "\n";
}

float avg(int x,int y){
  return (x+y)/2.0;
}

float avg(int x,int y, int z){
  return (x+y+z)/3.0;
}
