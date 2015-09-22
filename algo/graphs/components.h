#ifndef COMPONENTS_H
#define COMPONENTS_H

struct Vertex{
  int id, weight;
Vertex(int _id):id(_id),weight(0){};
Vertex(int _id,int _weight):id(_id),weight(_weight){};
};
struct Edge{
  int id,weight;
  Vertex *pointa,*pointb;
Edge(int _id,Vertex *a, Vertex *b):id(_id),weight(0),pointa(a),pointb(b){};
Edge(int _id,int _weight,Vertex *a, Vertex *b):id(_id),weight(_weight),pointa(a),pointb(b){};  
};

struct graph{
  Vertex v_set[10];
  Edge e_set[45];
  addE(Edge&);
  addV(Vertex&);
};
#endif
