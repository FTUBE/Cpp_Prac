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

struct PQueue{
  int data[10];
  int pointer;
PQueue():pointer(1){};
  void add(int);
  int remove();
  void removeAll();
  int getparent(int);
  int getmaxindex(int);
};

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
TreeNode():val(0),left(NULL),right(NULL){};
TreeNode(int _val):val(_val),left(NULL),right(NULL){};
};
  
struct BST{
  TreeNode* head;
  void add(int);
  bool search(int);
  void DFS();
  void traverse(TreeNode*);
  void remove(int);
BST():head(NULL){};
};

struct hashtable{
  // To be implemented.
};

struct ListNode{
  int val;
  ListNode* next;
ListNode(int _val):val(_val),next(NULL){};
  void print();
};
#endif
