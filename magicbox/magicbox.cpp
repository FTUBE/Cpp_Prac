#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int maxbox(string str, int x, int y, int z);
void check_range(int &Y,int &B,int &R,int x,int y,int z);

int main(){
  int x,y,z;
  cin >>x >> y>>z;
  char line[20001];
  cin.ignore();
  cin.getline(line,20001);
  string input(line);
  cout << maxbox(input,x,y,z) << endl;

}

int maxbox(string str, int x, int y, int z){
  int R = 0;
  int Y = 0;
  int B = 0;
  int max = 0;

  for(int i = 0; i < str.length();i++){
    switch(str[i]){
    case 'R':
      R++;
      break;
    case 'Y':
      Y++;
      break;
    case 'B':
      B++;
      break;
    }
    int sum = R + Y + B;
    if(sum >= max){
      max = sum;
    }
    check_range(Y,B,R,x,y,z);
  }
  return max;
}

void check_range(int &Y,int &B,int &R,int x,int y,int z){
  int a = abs(Y-B);
  int b = abs(Y-R);
  int c = abs(B-R);

  vector<int> wehave;
  vector<int> shouldbe;

  wehave.push_back(a);
  if(wehave[0] > b){
    wehave.push_back(b);
  }
  else{
    wehave.insert(wehave.begin(),b);
  }
  if(wehave[0] > c){
    if(wehave[1] > c){
      wehave.push_back(c);
    }
    else{
      wehave.insert(wehave.begin()+1,c);
    }
  }
  else{
    wehave.insert(wehave.begin(),c);
  }
  //should be;
  shouldbe.push_back(x);
  if(shouldbe[0] > y){
    shouldbe.push_back(y);
  }
  else{
    shouldbe.insert(shouldbe.begin(),y);
  }
  if(shouldbe[0] > z){
    if(shouldbe[1] > z){
      shouldbe.push_back(z);
    }
    else{
      shouldbe.insert(shouldbe.begin()+1,z);
    }
  }
  else{
    shouldbe.insert(shouldbe.begin(),z);
  }
  int index = 0;
  while(index < 3){
    if(shouldbe[index] != wehave[index]){
      return;
    }
    index++;
  }
  Y = 0;
  B = 0;
  R = 0;
}
