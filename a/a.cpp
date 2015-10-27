//Clicker
//mstest2015dec2 Problem C
//hiho67
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

#define MAX_N 30

int n;
int m;
int a[MAX_N];
int b[MAX_N];
int dp[MAX_N+1][20000+1];

int dfs(int i,int j){
  if(dp[i][j]>=0){
    return dp[i][j];
  }
  if(i==n){
    return dp[i][j]=0;
  }
  int ans;
  ans=dfs(i+1,j);
  int w;
  w=0;
  int dw;
  dw=b[i];
  int v;
  v=0;
  while(w+=dw,j>=w){
    v+=a[i];
    int tmp=dfs(i+1,j-w)+v;
    if(ans<tmp){
      ans=tmp;
    }
    dw=(int)(1.07*dw);
  }
  return dp[i][j]=ans;
}
int main(){
  int i;
  scanf("%u%u",&n,&m);
  for(i=0;i<n;i++){
    scanf("%u%u",&a[i],&b[i]);
  }
  memset(dp,-1,sizeof dp);
  printf("%u",dfs(0,m));
  return 0;
}
