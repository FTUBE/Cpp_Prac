#include<vector>
#ifndef COMPONENTS_H
#define COMPONENTS_H

using namespace std;

struct Edge{
  int weight;
  Edge(int _weight){
    weight = _weight;
  };
};

struct pQueue{
  vector<int> data;
  pQueue(){
    data.push_back(0);
  };
  
};
#endif
