#include<vector>
#ifndef COMPONENTS_H
#define COMPONENTS_H

using namespace std;

struct Edge{
  int weight, pointa,pointb;
  Edge(int _weight,int _pointa,int _pointb){
    weight = _weight;
    pointa = _pointa;
    pointb = _pointb;
  };
};

struct ecmp{
  bool operator()(Edge a, Edge b){
    if(a.weight >= b.weight){
      return true;
    }
    return false;
  }
};

struct pQueue{
  vector<int> data;
  pQueue(){
    data.push_back(0);
  };
  
};


#endif
