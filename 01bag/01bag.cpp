#include <iostream>
#include <vector>

using namespace std;
const int capacity = 30;

vector<int> maxv(int*,int*,int);

int main(){

  int value[5];
  int weight[5];
  
  for(int i = 0; i < 5; i++){
    cin >> value[i]; 
  }
  
  for(int i = 0; i < 5; i++){
    cin >> weight[i];
  }

  vector<int> res = maxv(value,weight,capacity);
  for(int i = 0; i < res.size(); i++){
    cout << res[i] << " ";
  }
  cout << endl;


}

vector<int> maxv(int *value,int *weight,int c){

  int **dp = new int*[5];
  for(int i = 0; i < 5; i++){
    dp[i] = new int[c + 1];
  }
  
  for(int i = 0; i < 5; i++){
    dp[i][0] = 0;
  }

  for(int i = 0; i < c+1; i++){
    if(weight[0] > i)
      dp[0][i] = 0;
    else{
      dp[0][i] = value[0];
    }
  }

  for(int i = 1; i < 5; i++){
    for(int j = 1; j < c + 1; j++){
      if(weight[i] > j){
	dp[i][j] = dp[i-1][j];
	continue;
      }
      if(value[i] + dp[i-1][j-weight[i]] > dp[i-1][j]){
	dp[i][j] = value[i] + dp[i-1][j-weight[i]];
      }
      else{
	dp[i][j] = dp[i-1][j];
      }
    }
  }
  vector<int> res;
  
  for(int i = 4, w = c; i >= 0; i--){
    
    if(i == 0){
      if(dp[i][w] == value[i]){
	res.push_back(i);
      }
      continue;
    }
    
    if(dp[i][w] == dp[i - 1][w]){
      continue;
    }
    w -= weight[i];
    res.push_back(i);
  }
  return res;
}
