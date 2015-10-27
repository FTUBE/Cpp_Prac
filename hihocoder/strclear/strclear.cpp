#include<iostream>
#include<string>

using namespace std;

const int MAXLENGTH = 101;

int parse(string);
int clear(string str);

int main(){

  int num;
  cin >> num;
  cin.ignore();
  int res[num];
  
  char *line = new char[MAXLENGTH];
  
  for(int i = 0; i < num; i++){
    cin.getline(line,MAXLENGTH);
    string str(line);
    res[i] = parse(str);    
  }
  
  for(int i = 0; i < num;i++){
    cout << res[i] << endl;
  }
    
  return 0; 
}

int parse(string str){
  int max = -1;
  for(int i = 0; i < 3; i++){
    for(int n = 0; n <= str.length();n++){
      string newstr(str);
      newstr.insert(newstr.begin()+n,'A' + i);
      //cout << newstr<<endl;
      int thisc = clear(newstr);
      if(thisc >= max){
	max = thisc;
	continue;
      }
    }
  }
  return max;
}

int clear(string str){
  //  cout << str<<endl;
  string newstr = "";

  for(int i = 0; i < str.length();i++){

    bool ent = false;
    while(str[i] == str[i+1]){
      ent = true;
      i++;
    }
    if(ent){
      continue;
    }
    newstr.push_back(str[i]);
  }
  int del = str.length() - newstr.length();
  
  if(del == 0){
    return 0;
  }
  return del+clear(newstr);
}
