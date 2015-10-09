#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

void naive_cmp(string text,string pattern);
vector<int> functionpi(string pattern);
void kmp(string text, string pattern);

int main(int argc,char *argv[]){
  if(argc < 2){
    cout << "[text][pattern]"<<endl;
    exit(1);
  }
  if(!(argv[1] && argv[2])){
    exit(1);
  }
  string text(argv[1]);
  string pattern(argv[2]);
  //  naive_cmp(text,pattern);
  // cout << "Calculate pi for : "<<pattern<<endl;
  //vector<int> pi = functionpi(pattern);
  kmp(text,pattern);
  /*  cout << "[";
  for(int i = 0;i < pi.size();i++){
    cout << pi[i]<<" ";
  }
  cout << "]"<<endl;*/
}

void naive_cmp(string text,string pattern){
  for(int i = 0; i <text.length();i++){
    bool find = true;
    for(int q = 0;q < pattern.length();q++){
      if(i+q == text.length()){
	break;
       }
      if(pattern[q] != text[i+q]){
	find = false;
	break;
      }
    }
    if(find){
      cout << i << " "<<endl;
    }
  }
} 

vector<int> functionpi(string pattern){
  vector<int> toret;
  toret.push_back(0);
  int k = -1;
  int q = 1;
  while(q < pattern.length()){
    while(pattern[k+1] !=  pattern[q]){
      if(k == -1){
	break;
      }
      k = toret[k]-1;
    }
    if(pattern[k+1] == pattern[q]){
      k++;
    }
    toret.push_back(k+1);
    q++;
  }
  return toret;
}

void kmp(string text, string pattern){
  vector<int> pi_v = functionpi(pattern);
  int p = 0;
  int q = 0;
  while(p < text.length()){
    if(q == pattern.length()){      
      cout << p-q <<endl;
      q = 0;
    }
    if(p == text.length()){
      break;
    }
    if(text[p] == pattern[q]){
      p++;
      q++;
      continue;
    }
    while(text[p] != pattern[q]){
      if(q == 0){
	break;
      }
      q = pi_v[q-1];
    }
    if(text[p] != pattern[q]){
      p++;
    }
  }
}
