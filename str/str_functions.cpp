#include <iostream>
#include <cstring>

using namespace std;

void printstr(char str[]);

int main(){
  char phrase[] = "abcdefghijklmn";
  char copy[strlen(phrase) + 1];
  strcpy(copy,phrase);
  printstr(copy);
  if(strcmp(copy,phrase) == 0){
    cout << "Same."<<endl;
  }
  else{
    cout << "Not the same."<<endl;
  }
  cout << "Concatenate."<<endl;
  int newsize = strlen(copy) * 2 + 1;
  char newcopy[newsize];
  strcpy(newcopy,copy);
  strcat(newcopy,copy);
  cout << strlen(newcopy) << endl;
  printstr(newcopy);
}

void printstr(char str[]){
  int i = 0;
  char c = str[i];
  while(c!='\0'){
    cout << c;
    i++;
    c = str[i];
  }
  cout << "\n";
}
