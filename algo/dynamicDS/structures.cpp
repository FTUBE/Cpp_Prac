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

void PQueue::add(int n){
  data[pointer] = n;
  pointer++;
  int child = pointer-1;
  int parent = getparent(child);
  while(parent != -1 && data[parent] >= data[child]){
    int temp = data[parent];
    data[parent] = data[child];
    data[child] = temp;
    child = parent;
    parent = getparent(parent);
  }
}

int PQueue::remove(){
  if(pointer==1){
    cout << "Empty." << endl;
    return -1;
  }
  int toret = data[1];
  data[1] = data[pointer-1];
  pointer--;
  int parent = 1;
  int maxindex = getmaxindex(parent);
  while(maxindex != -1){
    int temp = data[parent];
    data[parent] = data[maxindex];
    data[maxindex] = temp;
    parent = maxindex;
    maxindex = getmaxindex(parent);
  }
  return toret;
}

void PQueue::removeAll(){
  cout << "Heapsort." << endl;
  while(pointer > 1){
    cout << remove() << " ";
  }
  cout << endl;
}

int PQueue::getparent(int index){
  if((index/2) > 0){
    return index/2;
  }
  return -1;
}

int PQueue::getmaxindex(int parent){
  int leftchild = parent * 2;
  if(leftchild >= pointer){
    return -1;
  }
  if(leftchild+1 >= pointer){
    if(data[parent] >= data[leftchild]){
      return leftchild;
    }
    else{return -1;}
  }
  int min;
  if(data[leftchild] <= data[leftchild+1]){
    min = leftchild;
  }
  else{
    min = leftchild + 1;
  }
  if(data[min] >= data[parent]){
    return -1;
  }
  return min;
}

void BST::add(int val){

  if(head == NULL){
    head = new TreeNode(val);
    //cout << "Added" << endl;
    return;
  }

  TreeNode* current = head;
  TreeNode* last;
  
  while(true){
  // To ensure the non-repetitiveness, the val is checked to be no equal.
    if((current->val) == val){
      //      cout << "Skip." << endl;
      break;
    }
    if((current->val) > val){
      last = current;
      current = (current -> left);
      if(current == NULL){
	last -> left = new TreeNode(val);
	//cout << "Added" << endl;
	break;
      }
      continue;
    }
    last = current;
    current = (current -> right);
    if(current == NULL){
      last -> right = new TreeNode(val);
      //cout << "Added" << endl;
      break;
    }
  }

}

bool BST::search(int val){
  TreeNode* current = head;

  while(current != NULL){
    if((current->val) == val){
      return true;
    }
    if((current -> val) > val){
      current = current -> left;
      continue;
    }
    current = current -> right;
  }
  return false;
}

void BST::DFS(){
  traverse(head);
}

void BST::traverse(TreeNode* head){
  if(head == NULL){
    return;
  }
  traverse(head->left);
  cout << head->val << endl;
  traverse(head->right);
}

void BST::remove(int val){
  val = 0;
  //To be implemented.
}

// Print from here.
void ListNode::print(){
  cout << val << "->";
  ListNode* current = next;
  while(current != NULL){
    cout << (current->val) << "->";
    current = current->next;
  }
  cout << "NULL" << endl;
}
