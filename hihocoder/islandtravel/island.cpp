#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int dijstra(int **edge,int cnt);
int getdis(int pos1[2],int pos2[2]);
int getmin(int a, int b);
int findmin(int *arr,int cnt,int *exist);

int main(){

  int cnt;
  cin >> cnt;
  int pos[cnt][2];
  
  for(int i = 0; i < cnt;i++){
    cin >> pos[i][0] >> pos[i][1];
  }

  int **edge = new int*[cnt];
  for(int i = 0; i < cnt; i++){
    edge[i] = new int[cnt];
  }
  
  for(int i = 0 ; i < cnt;i++){
    for(int j = 0 ; j <cnt;j++){
      int len = getdis(pos[i],pos[j]);
      edge[i][j] = len;
    }
  }
  
  int res = dijstra(edge,cnt);
  cout<<res<<endl;
  for(int i = 0; i < cnt; i++){
    delete []edge[i];
  }
  
}

int dijstra(int** edge,int cnt){
  int s[cnt];
  int dis[cnt];
  
  memset(s,-1,sizeof(int) * cnt);
  for(int i = 0 ; i < cnt; i++){
    dis[i] = INT_MAX;
  }
  dis[0] = 0;
  int num = 0;
  while(num < cnt){
    int index = findmin(dis,cnt,s);
    for(int i = 0; i < cnt;i++){
      dis[i] = getmin(dis[i],dis[index] + edge[index][i]);
    }
    s[index] = 0;
    num++;
  }
  
  return dis[cnt-1];
}


int findmin(int *arr,int cnt,int *exist){

  int toret = INT_MAX;
  int k = 0;
  
  for(int i = 0; i < cnt;i++){
    if(arr[i] < toret && exist[i] == -1){
      toret = arr[i];
      k = i;
    }
  }
  return k;
}
int getdis(int pos1[2],int pos2[2]){
  
  int red1 = abs(pos1[0] - pos2[0]);
  int red2 = abs(pos1[1] - pos2[1]);

  return getmin(red1,red2);
}

int getmin(int a, int b){
  return (a>b?b:a);
}
