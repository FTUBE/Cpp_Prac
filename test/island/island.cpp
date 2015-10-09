#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int minimum_cost(vector<int> xi,vector<int> yi, int N);

int main(){

  return 0;
}

int minimum_cost(vector<int> xi,vector<int> yi, int N, vector<int> path,int uptonow){
  int index = 0;
  int minimum = INT_MAX;
  int current = path[path.size()-1];
  
  while(index < xi.size()){
    
    if(find_ele(path,index) || index == current){
      index++;
      continue;
    }
    
    int newuptonow = getdis(current,index,xi,yi) + uptonow;
    vector<int> newpath(path);
    newpath.push_back(index);
    int fake_min;
    
    if(index != N)
      fake_min = minimum_cost(xi,yi,N,newpath,newuptonow);
    else{
      fake_min = newuptonow;
    }
    
    minimum = min(minimum,fake_min);
    index++;
  }
  return minimum;
}

int getdis(int current,int index,vector<int> xi,vector<int> yi){
  
}

bool find_ele(vector<int> path, int tofind){
  int index = 0;
  while(index < path.size()){
    if(path[index] == tofind){
      return true;
    }
    index++;
  }
  return false;
}
