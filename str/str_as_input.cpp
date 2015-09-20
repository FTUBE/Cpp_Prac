#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 100;

int main(){
  char input[MAX_LENGTH];
  cout << "Input a line : " << endl;
  cin.getline(input,MAX_LENGTH);
  cout << input << endl;

  cout << "Copying.......";

  int size = strlen(input);
  cout << "Input size is : " << size << endl;
  char copy[size + 1];
  strcpy(copy,input);
  cout << "Copied String : " << endl;
  cout << copy << endl;
  cout << "Input another cat : " << endl;
  cin.getline(input,MAX_LENGTH);
  int catsize = strlen(input);
  cout << "Input size is : " << catsize << endl;
  cout << "Total size is : " << size + catsize << endl;
  char cat[size + catsize + 1];
  strcpy(cat,copy);
  strcat(cat,input);
  cout << "cat : " << endl << cat << endl; 
  return 0;
}
