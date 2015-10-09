#include<iostream>
#include<vector>
#include<queue>
#include"components.h"
using namespace std;

const int MAXPOINT = 9;
vector<int> adj[MAXPOINT];
Edge* edges[MAXPOINT][MAXPOINT];

void build();
void addEdge(int pointa, int pointb, int _weight);
void print_adj(int point);
void print_matrix();
void bfs(int start);
void printvec(vector<int> arr);
bool find(vector<int> arr, int num);
void queue_bfs(int start);
vector<int> queue_bfs_shortestpath(int start);
void dfs(int start);

vector<int> already;

int main(){
  build();
  addEdge(0,1,6);
  addEdge(0,3,3);
  addEdge(1,2,2);
  addEdge(2,3,9);
  addEdge(1,4,7);
  addEdge(4,3,11);
  addEdge(4,5,1);
  addEdge(1,5,10);
  addEdge(5,3,14);
  addEdge(6,3,9);
  addEdge(5,3,14);
  addEdge(5,6,5);
  addEdge(5,7,5);
  addEdge(0,3,3);
  addEdge(6,7,4);
  addEdge(0,3,3);
  addEdge(6,8,4);
  addEdge(7,8,8);
  /* Graph building.*/

  //  print_adj(1);
  //    print_matrix();

  //bfs.
  /*    bfs(0);
	queue_bfs(0);*/
  /*  vector<int> dis = queue_bfs_shortestpath(0);
  for(int i = 0; i < MAXPOINT;i++){
  cout << " 0 -> " << i << " : "<<dis[i]<<endl;
  }*/
  //   dfs(0);
  
}

void build(){

  for(int i = 0; i < MAXPOINT; i++){
    vector<int> arr;
    adj[i] = arr;
    //    cout << "Point "<<i<<" built."<<endl;
  }
}

void addEdge(int pointa, int pointb,int _weight){
  if(pointa >= MAXPOINT || pointb >= MAXPOINT){
    cout << "limit value exceeded."<<endl;
    return;
  }
  if(!find(adj[pointa],pointb)){
    adj[pointa].push_back(pointb);
  }
  
  if(!find(adj[pointb],pointa)){
    adj[pointb].push_back(pointa);
  }
  
  Edge* newedge = new Edge(_weight);
  edges[pointa][pointb] = newedge;
  edges[pointb][pointa] = newedge;
}

void print_adj(int point){
  if(point >= MAXPOINT){
    cout << "limit value exceeded."<<endl;
    return;
  }
  int adj_count = adj[point].size();
  cout << "Point "<<point << "-[ ";
  for(int i = 0; i< adj_count;i++){
    cout << adj[point][i] << "-("<<edges[point][adj[point][i]]->weight<<")"<< " ";
  }
  cout<< "]"<<endl;
}

void print_matrix(){
  for(int i = 0; i< MAXPOINT ;i++){
    print_adj(i);
  }
}

void bfs(int start){
  vector<int> route;
  cout << start << endl;
  route.push_back(start);
  vector<int>* next = new vector<int>();
  (*next).push_back(start);
  while((*next).size() != 0){
    vector<int>* new_next = new vector<int>();
    for(int i = 0; i<(*next).size();i++){
      int point = (*next)[i];
      for(int n = 0; n < adj[point].size();n++){
	if(find(route,adj[point][n]) || find((*new_next),adj[point][n])){
	  continue;
	}
	(*new_next).push_back(adj[point][n]);
	(route).push_back(adj[point][n]);
      }
    }
    cout << "!new route : \n";
    printvec(*new_next);
    cout << "route now: \n";
    printvec(route);
    cout<<"\n";
    delete next;
    next = new_next;
  }  
}

vector<int> queue_bfs_shortestpath(int start){
  vector<int> visited;
  queue<int> q;
  vector<int> distance(MAXPOINT);
  q.push(start);
  distance[start] = 0;
  while(!q.empty()){
    int now = q.front();
    visited.push_back(now);
    q.pop();
    vector<int> adjacent = adj[now];
    for(int i = 0; i < adjacent.size();i++){
      if(find(visited,adjacent[i])){
	continue;
      }
      distance[adjacent[i]] = distance[now]+1;
      visited.push_back(adjacent[i]);
      q.push(adjacent[i]);
    }
  }
  return distance;
}

void queue_bfs(int start){
  vector<int> visited;
  queue<int> q;
  q.push(start);
  while(!q.empty()){
    int now = q.front();
    visited.push_back(now);
    q.pop();
    vector<int> adjacent = adj[now];
    for(int i = 0; i < adjacent.size();i++){
      if(find(visited,adjacent[i])){
	continue;
      }
      cout << adjacent[i]<<endl;
      visited.push_back(adjacent[i]);
      q.push(adjacent[i]);
    }
  }
}

void printvec(vector<int> arr){
  int size = arr.size();
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout<<endl;
}

bool find(vector<int> arr, int num){
  for(int i = 0;i<arr.size();i++){
    if(arr[i] == num){
      return true;
    }
  }
  return false;
}

void dfs(int start){
  if(!find(already,start)){
    cout << start << endl;
    already.push_back(start);
    vector<int> adjacent = adj[start];
    for(int i = 0; i < adjacent.size();i++){
      dfs(adjacent[i]);
    }
  }
  return;
}
