#ifndef STRUCTURES_H
#define STRUCTURES_H
struct stack{
  int size;
  int *data;
  int length;
stack():size(1),length(0){
  data = new int[1];
};
  void push(int);
  bool isFull();
  void expand();
  void print();
  int pop();
};
#endif
