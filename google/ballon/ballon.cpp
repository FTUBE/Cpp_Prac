#include <iostream>
#include<cmath>
#include <fstream>

using namespace std;

int N,M,Q;

int geten(int**,int*);
int timeunit(int pos[2], int *velo);
int getmin(int,int);
int getmax(int,int);

int main(){
  ifstream in;
  ofstream out;
  out.open("result");
  in.open("B-large.in");
  int cse;
  in>>cse;
  for(int c = 0; c < cse;c++){
    
    in >> N >> M >> Q;
    
    int velo[M];
    
    int **pos = new int*[N];
    
    for(int i = 0; i < N;i++){
      pos[i] = new int[2];
    }
    
    for(int i = 0; i < M;i++){
      in >> velo[i];
    }
    
    for(int i = 0; i < N;i++){
      in >>pos[i][0] >> pos[i][1];
    }
    int res = geten(pos,velo);
    if(res == INT_MAX){out<<"Case #"<<c+1<<": "<<"IMPOSSIBLE\n";continue;}
    out << "Case #"<<c+1 <<": "<<res <<endl;
  }
  return 0;
}

int geten(int **pos, int *velo){
  
  int dp[N+1][Q+1];
  for(int i = 0; i <= Q;i++){
    dp[0][i] = 0;
  }

  for(int i = 1; i <= N;i++){
    int m = INT_MIN;
    for(int n = 0; n < i;n++){
      m = getmax(timeunit(pos[n],velo),m);
    }
    dp[i][0] = m;
  }

  for(int i = 1; i <= N;i++){
    for(int j = 1; j <= Q;j++){
      int min = INT_MAX;
      for(int use = -j; use <= j;use++){
	pos[i-1][1] += use;
	if(pos[i-1][1] < 0 || pos[i-1][1] >= M){
	  pos[i-1][1] -= use;
	  continue;
	}
	min = getmin(getmax(dp[i-1][j-abs(use)],timeunit(pos[i-1],velo)),min);
	pos[i-1][1] -= use;
      }
      dp[i][j] = min;
    }
  }

  return dp[N][Q];
}

int timeunit(int pos[2], int *velo){

  if(velo[pos[1]] == 0){
    if(pos[0] == 0){
      return 0;
    }
    return INT_MAX;
  }
  
  if(pos[0] * velo[pos[1]] > 0){
    return INT_MAX;
  }
  
  int timeneed = (0-pos[0])/velo[pos[1]];
  if((0-pos[0])%velo[pos[1]] != 0){
    timeneed++;
  }
  
  return timeneed;
}

int getmin(int a,int b){
  return (a>b?b:a);
}
int getmax(int a,int b){
  return (a>b?a:b);
}
