#include <iostream>

using namespace std;

const int SIZE = 5;
typedef int INARRAY[SIZE];

int main(){

  INARRAY a;
  INARRAY b;

  for(int i = 0; i < SIZE; i++){
    a[i] = i;
    b[i] = i+1;
  }

  for(int n = 0; n < SIZE; n++){
    cout << "a[" << n <<"] = "<< a[n] << "\n";
    cout << "b[" << n <<"] = "<< b[n] << "\n\n";
  }
  
  return 0;
}
