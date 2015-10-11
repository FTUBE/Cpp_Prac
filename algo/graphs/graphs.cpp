#include<iostream>
#include<vector>
#include<queue>
#include"components.h"
#include<set>
#include<climits>

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
vector<int*> kruskal();
bool samegroup(set<vector<int> >& s,Edge e);
vector<int*> prims(int start);
vector<int> already;
priority_queue<Edge,vector<Edge>,ecmp> edgequeue;
vector<Edge> alledges;
void bellmanford(int start, int end);
vector<int> distancevec;

void testqueue();

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
  //  testqueue();
  /*  cout << "Kruskal Result"<<endl;
  vector<int*> edgeset = kruskal();
  for(int i = 0; i < edgeset.size();i++){
    cout <<"["<<edgeset[i][0]<<","<<edgeset[i][1]<<"]"<<endl;
  }
  cout << "Prims Result with start 1"<<endl;
   edgeset = prims(1);
  for(int i = 0; i < edgeset.size();i++){
    cout <<"["<<edgeset[i][0]<<","<<edgeset[i][1]<<"]"<<endl;
  }
  cout << "Prims Result with start 8"<<endl;
  edgeset = prims(8);
  for(int i = 0; i < edgeset.size();i++){
    cout <<"["<<edgeset[i][0]<<","<<edgeset[i][1]<<"]"<<endl;
    }*/
  cout<< "Bellman-Ford"<<endl;
  int from,to;
  cout << "from"<<endl;
  cin>>from;
  cout << "to"<<endl;
  cin>>to;  
  bellmanford(from,to);
  /* Graph building.*/

  //  print_adj(1);
  //      print_matrix();

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
  
  Edge* newedge = new Edge(_weight,pointa,pointb);
  edges[pointa][pointb] = newedge;
  edges[pointb][pointa] = newedge;
  edgequeue.push(*newedge);
  alledges.push_back(*newedge);
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

vector<int*> kruskal(){
  vector<int*> toret;
  set<vector<int> > s;
  for(int i = 0; i < MAXPOINT; i++){
    vector<int>* a_set = new vector<int>();
    (*a_set).push_back(i);
    s.insert(*a_set);
  }
  while(s.size() > 1){
    Edge e = edgequeue.top();
    edgequeue.pop();
    while(samegroup(s,e)){
      e = edgequeue.top();
      edgequeue.pop();
    }
    int *toadd = new int[2];
    toadd[0] = e.pointa;
    toadd[1] = e.pointb;
    toret.push_back(toadd);
    //    cout << s.size()<<endl;
  }
  return toret;
}

void testqueue(){
  while(edgequeue.size() > 0){
    cout << edgequeue.top().weight<<endl;
    edgequeue.pop();
  }
}

bool samegroup(set<vector<int> >& s,Edge e){
  for(set<vector<int> >::iterator it = s.begin(); it != s.end();it++){
    int a = e.pointa;
    int b = e.pointb;
    if(find((*it),a)){
      if(find((*it),b)){
	return true;
      }
      set<vector<int> >::iterator itb = s.begin();
      vector<int> copyorigin = (*it);
      while(itb != s.end()){
	if(find((*itb),b)){
	  for(int i = 0; i <(*itb).size();i++){
	    copyorigin.push_back((*itb)[i]);
	  }
	  break;
	}
	itb++;
      }
      s.erase(*itb);
      s.erase(*it);
      s.insert(copyorigin);
      return false;
    }
  } 
}

vector<int*> prims(int start){
  vector<int*> toret;
  priority_queue<Edge,vector<Edge>,ecmp> eq;
  vector<int> node_set;
  node_set.push_back(start);
  vector<int> adjacent = adj[start];
  for(int i = 0; i <adjacent.size();i++){
    eq.push(*edges[start][adjacent[i]]);
  }
  while(node_set.size() < MAXPOINT){
    Edge e = eq.top();
    eq.pop();
    bool a = find(node_set,e.pointa);
    bool b = find(node_set,e.pointb);

    if(a && b){
      continue;
    }
    
    int *newedge = new int[2];
    newedge[0] = e.pointa;
    newedge[1] = e.pointb;
    
    toret.push_back(newedge);
    if(a){
      node_set.push_back(e.pointb);
      adjacent = adj[e.pointb];
      for(int i = 0; i <adjacent.size();i++){
	eq.push(*edges[e.pointb][adjacent[i]]);
      }
    }
    else{
      node_set.push_back(e.pointa);
      adjacent = adj[e.pointa];
      for(int i = 0; i <adjacent.size();i++){
	eq.push(*edges[e.pointa][adjacent[i]]);
      }
    }
  }
  return toret;
}

void bellmanford(int start, int end){
  int distance[MAXPOINT];
  for(int i = 0; i < MAXPOINT; i++){
    if(i == start){
      distance[i] = 0;
      continue;
    }
    distance[i] = INT_MAX;
  }
  for(int i = 0; i < MAXPOINT-1; i++){
    for(int n = 0; n < alledges.size();n++){
      Edge e = alledges[n];
      //cout << "relax Edge "<<n<<endl;
      if(distance[e.pointa] != INT_MAX){
	if(distance[e.pointa] + e.weight < distance[e.pointb]){
	  distance[e.pointb] = distance[e.pointa] + e.weight;
	}
      }
      if(distance[e.pointb] != INT_MAX){
	if(distance[e.pointb] + e.weight < distance[e.pointa]){
	  distance[e.pointa] = distance[e.pointb] + e.weight;
	}
      }
    }
  }
  cout << start << " to "<<end << " is "<<distance[end]<<endl;
}

void dijstra(int start){
  priority_queue<int,vector<int>,pointcmp> pointleft;
  for(int i = 0; i < MAXPOINT;i++){
    if(i == start){
      distancevec[i] = 0;
    }
    else{
      distancevec[i] = INT_MAX;
    }
    pointleft.push(i);
  }
  while(!pointleft.empty()){
    int point = pointleft.top();
    
    
  }
}

struct pointcmp{
  bool operator()(int a, int b){
    if(distancevec[a] >= distancevec[b]){
      return true;
    }
    return false;
  }
};
