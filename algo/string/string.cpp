#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool palindrome(string s);
string newone(int a);
string multiplysingle(string num1,char num2);
string add(string add1, string add2);
string multiply(string num1,string num2);
string trimming(string totrim);

int main(int argc,char *argv[]){
  if(argc < 3){
    cout << "No input string" << endl;
    exit(1);
  }
    string num1(argv[1]);
  string num2(argv[2]);
  /*
  string copy = "";
  int count = 0;
  while(count<input.length()){
    copy.push_back(input[count]);
    count++;
  }  
  cout << input << endl;
  cout << "Append"<<endl;
  string ano = "another";
  input += ano;
  cout << input<<endl;
  cout << "pop_back()"<< endl;
  while(input.compare(copy)!=0){
    input.pop_back();
  }
  cout << input<<endl;
  cout << "Substring" << endl;
  cout << input.substr(1,2) << endl;
  cout << "Erase"<<endl;
  while(input.compare("") != 0){
    cout << input.erase(input.length()-1,1) << endl;
  }
  cout << "Palindrome check" << endl;
  if(palindrome(copy)){
    cout << "palindrome"<<endl;
    return 0;
  }
  cout << "non-palindrome"<<endl;
  return 0;*/
  
  //cout << multiply(num1,num2) << endl;
  cout << num1+num2+2<<endl;
}

bool palindrome(string s){
  int head = 0;
  int tail = s.length()-1;
  while(head<tail){
    if(s[head] != s[tail]){
      return false;
    }
    head++;
    tail--;
  }
  return true;
}

string newone(int a){
  char c = '0' + (a % 10);
  int i = 5;
  string toret = "";
  while(i > 0){
    toret.push_back(c);
    i--;
  }
  return toret;
}

string multiplysingle(string num1,char num2){
  int c = 0;
  int index = num1.length()-1;
  string toret = "";
  while(index>=0){
    int res = (num1[index]-'0')*(num2-'0') + c;
    toret.insert(0,1,(res%10)+'0');
    c = res/10;
    index--;
  }
  if(c == 0){
    return toret;
  }
  toret.insert(0,1,c + '0');
  return toret;
}

string add(string add1, string add2){
  int index1 = add1.length()-1;
  int index2 = add2.length()-1;

  string s = "";
  int c = 0;
  int sum = 0;
  char n1,n2;

  while(index1>=0 || index2>=0){
    if(index1 < 0){
      n1 = '0';
    }
    else{
      n1 = add1[index1];
    }
    if(index2 < 0){
      n2 = '0';
    }
    else{
      n2 = add2[index2];
    }
    sum = (n1-'0') + (n2-'0') + c;
    c = sum / 10;
    s.insert(0,1,(sum % 10) + '0');
    index1--;
    index2--;
  }
  if(c == 0){
    return s;
  }
  s.insert(0,1,c+'0');
  return s;
}

string multiply(string num1,string num2){
  int length = num2.length();
  int index = length - 1;
  string toret = "0";
  while(index >= 0){
    int padding = length - index - 1;
    string get = multiplysingle(num1,num2[index]);
    while(padding > 0){
      get.push_back('0');
      padding--;
    }
    toret = add(toret,get);
    index--;
  }
  toret = trimming(toret);
  return toret;
}

string trimming(string totrim){
  int index = 0;
  while(totrim[index] == '0' && index != totrim.length()){
    index++;
  }
  
  if(index == totrim.length()){
    return "0";
  }
  
  string toret = "";
  while(index < totrim.length()){
    toret.push_back(totrim[index]);
    index++;
  }
  return toret;
}

