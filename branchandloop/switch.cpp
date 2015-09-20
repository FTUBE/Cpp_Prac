#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  char c;
  while(true){
    cout << "Type in a char : \n";
    cin >> c;
    switch(c){
    case 'q':
      cout << "Exit.\n";
      exit(1);
    case 'r':
      cout << "Rewrite.\n";
      break;
    default:
      cout << "Unrecognized.\n";
      break;
    }
  }
}
