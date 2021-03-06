#include<iostream>
#include<fstream>
#include<map>

using namespace std;

int main(){
  ifstream in;
  in.open("C-large-practice.in");
  ofstream out;
  out.open("result");
  int cse;
  in>>cse;
  in.ignore();
  map<char,string> mp;
  string tomap[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
  for(int i = 0; i < 26;i++){
    mp['a'+i] = tomap[i];
  }
  mp[' '] = "0";
  
  char prev = '/';
  string res = "";
  char *line = new char[1001];
  int k = 0;
  while(k < cse){
    in.getline(line,1000);
    int len = strlen(line);
    for(int i = 0;i < len;i++){
      if(mp[line[i]][0] == prev){
	res += (" "+mp[line[i]]);
      }
      else{
	res += mp[line[i]];
      }
      prev = mp[line[i]][0];
    }
    out <<"Case #"<<k+1<<": "<< res<<endl;
    prev = '/';
    res = "";
    k++;
  }
  out.close();
  in.close();
  return 0;
  
}
