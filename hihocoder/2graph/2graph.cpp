#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

bool solve(vector<int> *matrix,int);

int main(){
  int group;
  cin >> group;
  bool result[group];
  vector<int> *matrix;
  int dimension,edge;
  
  for(int i = 0; i < group; i++){

    cin >> dimension >> edge;

    matrix = new vector<int>[dimension+1];

    bool skip = false;
    while(edge-- > 0){
      int r,c;
      cin >> r >> c;
      if(r == c){skip = true;}
      matrix[r].push_back(c);
      matrix[c].push_back(r);
    }
    if(!skip){
      result[i] = solve(matrix,dimension);
    }
    else{
      result[i] = false;
    }
    /*    for(int n = 0; n < dimension + 1; n++){
      delete []matrix;
      }*/
  }

  for(int i = 0; i < group; i++){
    cout << (result[i]?"Correct":"Wrong") << endl;
  }
  
  return 0;
}

bool solve(vector<int> *matrix,int dimension){

  short arr[dimension + 1];
  memset(arr,-1,sizeof(short)*(dimension + 1));
  for(int num = 1; num < dimension + 1; num++){
    if(arr[num] == -1){
      queue<int> next;
      arr[num] = 0;
      next.push(num);
      
      while(!next.empty()){
	int cur = next.front();
	next.pop();
	short nextshould = (arr[cur] + 1) % 2;
	for(int n = 0; n < matrix[cur].size(); n++){
	  if(arr[matrix[cur][n]] == -1){
	    arr[matrix[cur][n]] = nextshould;
	    next.push(matrix[cur][n]);
	  }
	  else if(arr[matrix[cur][n]] != nextshould){
	    return false;
	  }	
	}
      }
    }
  }   
  return true;
}

