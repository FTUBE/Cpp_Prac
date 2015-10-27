#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

bool find(vector<int> arr, int num);

int main(){
  int line;
  cin>>line;
    
  for(int i = 0; i<line;i++){
    int num;
    cin>>num;
    
    while(cin>>num){
      //some num processed.
      if(getchar() == '\n'){
	break;
      }
    }
  }
}
