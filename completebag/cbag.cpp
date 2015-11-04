#include<iostream>
#include<climits>

using namespace std;

const int capacity = 7;
const int num = 4;
const int MIN = 0x80000000;

int getmax(int,int);
int maxv(int*,int*,const int);

int main(){

  int weight[4] = {3,1,9,10};
  int value[4] = {1,5,1,14};
  int res = maxv(weight,value,capacity);
  
  if(res < 0){
    cout << "No resolu.\n";
    return 0;
  }

  cout << "Res = "<<res<<endl;

  return 0;
}

int maxv(int *weight,int *value,const int capacity){

  int dp[num + 1][capacity + 1];

  for(int i = 0; i < num+1; i++){
    for(int j = 0; j < capacity + 1; j++){
      if(j == 0){
	dp[i][j] = 0;
	continue;
      }
      dp[i][j] = MIN;
    }
  }

  for(int i = 1; i < num+1; i++){
    for(int j = 1; j < capacity+1;j++){
      if(weight[i-1] > j){
	dp[i][j] = dp[i-1][j];
	continue;
      }
      dp[i][j] = getmax(dp[i-1][j],dp[i-1][j - weight[i-1]] + value[i-1]);
    }
  }

  return dp[num][capacity];  
}

int getmax(int a,int b){
  return (a>b?a:b);
}
