#include<iostream>
#include<string>
#include <cmath>

using namespace std;

const int MAXLENGTH = 100;

int translatemin(string&);

int main(){

  char *line = new char[MAXLENGTH + 1];

  cin.getline(line,MAXLENGTH);
  string str(line);
  cout << translatemin(str) << endl;
  
  return 0;
}

int translatemin(string& str){

  int len = str.length();
  int sum = 0;

  int pointer = 0;
  int carry = 0;
  int base = 10;
  for(int i = len-1; i >= 0;i--){
    int bit =  str[i] - '0';
    int herer = bit + carry % base;
    carry = (bit + carry)/base;
    sum += herer * pow(base,pointer++);
  }
  
  return sum;  
}
