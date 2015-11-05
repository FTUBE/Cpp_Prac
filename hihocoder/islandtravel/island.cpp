#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

int spfa(int**,int cnt);
int getdis(int pos1[2],int pos2[2]);
int getmin(int a, int b);
int findmin(int *arr,int cnt,int *exist);

int main(){
  int cnt;
  cin >> cnt;
  int pos[cnt][2];
  for(int i = 0; i < cnt;i++){
    scanf("%d %d",&pos[i][0],&pos[i][1]);
  }
  int **edge = new int*[cnt];
  
  for(int i = 0; i < cnt; i++) edge[i] = new int[cnt];

  for(int i = 0 ; i < cnt;i++){
    for(int j = i ; j <cnt;j++){
      int len = getdis(pos[i],pos[j]);
      edge[i][j] = len;
      edge[j][i] = len;
    }
  }  
  int res = spfa(edge,cnt); // dijstra(edge,cnt);
  cout<<res<<endl;
  return 0;
}

int spfa(int **edge,int cnt){
  int tp = 0;
  int end = 1;
  int *q = new int[cnt * cnt];
  q[tp] = 0;
  int inqueue[cnt];
  int dis[cnt];
  memset(inqueue,-1,sizeof(int) * cnt);

  for(int i = 0; i < cnt; i++){
    dis[i] = INT_MAX;
  }
  
  dis[0] = 0;

  while(tp < end){
    int point = q[tp++];
    inqueue[point] = -1;
    for(int i = 0; i < cnt;i++){
      if(dis[i] > dis[point] + edge[point][i]){
	dis[i] = dis[point] + edge[point][i];
	if(inqueue[i] == -1){
	  q[end++] = i;
	  inqueue[i] = 0;
	}
      }
    }
  }
  return dis[cnt-1];
}

int getdis(int pos1[2],int pos2[2]){
  
  int red1 = abs(pos1[0] - pos2[0]);
  int red2 = abs(pos1[1] - pos2[1]);

  return getmin(red1,red2);
}

int getmin(int a, int b){
  return (a>b?b:a);
}
