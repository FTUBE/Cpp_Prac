#include <iostream>
#include "structures.h"

using namespace std;

void teststack(stack& a);
void testPQueue(PQueue& pq);
void BSTtest(BST& bst);

int main(){
  stack a;
  PQueue pq;
  BST binarytree;
  BSTtest(binarytree);
}

void teststack(stack& a){
  for(int i = 0 ; i < 16; i++){
    a.push(i);
    a.print();
  }
  for(int i = 0 ; i < 16; i++){
    cout << "pop value : " << a.pop();
    a.print();
  }
  //  a.pop();
}

void testPQueue(PQueue& pq){
  for(int i = 9 ; i > 0; i--){
    pq.add(i);
    }
  //  pq.add(1);
  pq.removeAll();
}

void BSTtest(BST& bst){
  int toadd[] = {7,6,43,6,3,5,61,1,6,4,3,5,2,5,2,5,2,5,26,5,6,1,14,4,6,3,1,-1};
  int i = 0;
  while(toadd[i] != -1){
    bst.add(toadd[i]);
    i++;
  }
  bst.DFS();
}
