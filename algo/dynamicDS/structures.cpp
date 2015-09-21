#include <iostream>
#include "structures.h"
#include <cstdlib>

using namespace std;

void stack::push(int n){
  cout << "push " << n << endl;
  if(isFull()){
    expand();
  }
  data[this->length] = n;
  (this->length)++;
}

int stack::pop(){
  if(length==0){
    cout << "No data to push, halt" << endl;
    exit(1);
  }
  int toret = data[length-1];
  length--;
  return toret;
}

void stack::expand(){
  int *newdata = new int[(this->size)*2];
  for(int i = 0; i < this->length; i++){
    newdata[i] = (this->data)[i];
  }
  (this->size) *= 2;
  delete (this->data);
  (this->data) = newdata;
}

bool stack::isFull(){
  if(this->length == this->size){
    return true;
  }
  else{
    return false;
  }
}

void stack::print(){
  cout << "\nCapacity : " << this->size << " Length : " << this->length << endl;
  cout << "[ ";
  for(int i = 0; i < (this->length); i++){
    cout << (this->data)[i] << " ";
  }
  cout << "]" << endl;
}
