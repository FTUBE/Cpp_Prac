#include <iostream>
#include <map>

using namespace std;

int main(){

  map<char*,int> mp;

  for(int i = 0 ; i < 15 ;i++){
    char *newstr = new char[2];
    newstr[0] = 'a' + i;
    newstr[1] = '\0';
    mp[newstr] = 1;
  }
  

  map<char*,int>::iterator it;
  
  for(it = mp.begin(); it != mp.end(); it++){
    cout << it->first << " -> "<< it->second<<endl;
    delete it->first;
  }

  /*  it = mp.find("a");
  if(it == mp.end()) cout << "Not find\n";
  
  it = mp.find("c");
  if(it == mp.end()) cout << "Not find\n";
  */
  return 0;
}
