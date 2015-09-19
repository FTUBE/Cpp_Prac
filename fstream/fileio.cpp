#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
  ifstream in;
  ofstream out;
  in.open("data");
  out.open("data-copy");
  if(in.fail()){
    cout << "Cannot open file.\n";
    exit(1); //Quit safely.
  }
  cout << "File opened\n";
  char c;
  in.get(c);
  while(!in.eof()){
    cout << c;
    out.put(c);
    in.get(c);
  }
  cout << "\n";
  in.close();
  out.close();
  return 0;
}
