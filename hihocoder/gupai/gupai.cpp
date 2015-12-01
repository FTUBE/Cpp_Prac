#include <iostream>

using namespace std;

long long fibonacci(int&);

int main(){
  int n;
  cin >> n;

  cout << fibonacci(n)<<endl;
  
  return 0;
}

long long fibonacci(int& n){

  long long f[2];

  f[0] = 1;
  f[1] = 1;

  for(int i = 2; i < n + 1; i++){
    long long res = f[0] + f[1] % 19999997;
    f[0] = f[1];
    f[1] = res;
  }

  return f[1] % 19999997;
}
