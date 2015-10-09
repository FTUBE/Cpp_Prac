#include <iostream>

using namespace std;

int main(){
  
}

string replace(string str){
  string match = "marshtomp";
  for(int i = 0;i<str.length();i++){
    int index = 0;
    bool match = true;
    while(index < match.length()){
      if(i == str.length()){
	match = false;
	break;
      }
      if(match[index] != str[i]){
	match = false;
	break;
      }
      index++;
      i++;
    }
    
  }
}
