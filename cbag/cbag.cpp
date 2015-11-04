#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

const int cnt = 5;
const int pick = 5;
const int capa = 6;

int maxv(int*,int*,int);
int getmax(int,int);
int getmin(int,int);

int main(){
  
  int weight[cnt];
  int value[cnt];

  for(int i = 0; i < cnt; i++){
    cin >> weight[i];
  }
  
  for(int i = 0; i < cnt; i++){
    cin >> value[i];
  }
  cout << "How many?\n";
  int num;
  cin >> num;
  cout << "MAX VALUE = " << maxv(weight,value,num)<<endl;
  return 0;
}

int maxv(int *weight,int *value,int num){

  int dp[pick + 1][capa + 1];
  
  for(int  i =0 ; i < num+1;i++){
    for(int j = 0; j < capa+1;j++){
      dp[i][j] = 0x80000000;
    }
  }

  for(int i = 0; i < capa + 1; i++){
    dp[0][i] = 0;//dp[0][i] means needn't to fill the bag.
  }
  
  dp[0][0] = 0;//dp[0][0] only means to fill the bag.

  /*  for(int i = 0; i < pick + 1; i++){
    dp[i][0] = 0;
    }*/
  
  for(int i = 0; i < cnt; i++){
 
    for(int p = getmin(num,i+1); p > 0; p--){
      for(int c = capa; c >= weight[i]; c--){
	dp[p][c] = getmax(dp[p-1][c-weight[i]] + value[i],dp[p][c]);
      }
    }

  }
  
  return dp[num][capa];
}

int getmax(int a, int b){
  return (a>b?a:b);
}

int getmin(int a, int b){
  return (a>b?b:a);
}
