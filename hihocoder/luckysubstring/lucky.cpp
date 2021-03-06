#include <iostream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int MAXLENGTH = 100;

void generatesub(string& str, bool fibo[100]);
bool collect(string& here, bool fibo[100]);

map<string,bool> mp;

int main(){
  int fibo[] = {1,2,3,5,8,13,21,34,55,89};
  bool isfibo[100];
  memset(isfibo,false,100);
  for(int i = 0; i < 10;i++){
    isfibo[fibo[i]] = true;
  }
  char *line = new char[MAXLENGTH + 1];
  cin.getline(line,MAXLENGTH);
  string str(line);
  generatesub(str,isfibo);
  map<string,bool>::iterator it = mp.begin();
  while(it!=mp.end()){
    cout << it->first<<endl;
    it++;
  }
  
  return 0;
}

void generatesub(string& str, bool fibo[100]){
  for(int i = 0; i < str.length();i++){
    for(int  j = 1; j <= str.length();j++){
      string here = str.substr(i,j);
      if(collect(here,fibo)){
	mp[here] = true;
	continue;
      }
    }
  }
}

bool collect(string& here, bool fibo[100]){

  map<char, bool> count;
  
  for(int i = 0; i < here.length();i++){
    count[here[i]] = true;
  }
  
  if(!fibo[count.size()])
    {
      return false;
    }
  
  return true;
}
