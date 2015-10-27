#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v):val(v),left(NULL),right(NULL){};
};

TreeNode* lowestCommonAncestor(TreeNode *head, TreeNode *p,TreeNode *q);
bool findroute(TreeNode *head,vector<TreeNode*>& routeq, TreeNode *q);

int main(){

  TreeNode* head = new TreeNode(3);
  
  TreeNode* cur = head;

  cur->left = new TreeNode(5);
  cur->right = new TreeNode(1);
  cur = head->right;
  cur->left = new TreeNode(0);
  cur->right = new TreeNode(8);
  cur = head->left;
  cur->right = new TreeNode(2);
  cur->left = new TreeNode(6);
  cur = cur->right;
  cur->right = new TreeNode(4);
  cur->left = new TreeNode(7);

  TreeNode* res = lowestCommonAncestor(head, head->left->left, head->left->right->right);
  cout << res->val<<endl;

  return 0;
}

TreeNode* lowestCommonAncestor(TreeNode *head, TreeNode *p,TreeNode *q){

  vector<TreeNode*> routep;
  vector<TreeNode*> routeq;
  
  TreeNode* cur = head;
  findroute(head,routep,p);
  findroute(head,routeq,q);
  int index1 = routep.size()-1;
  int index2 = routeq.size()-1;
  TreeNode* common;
  while(routep[index1] == routeq[index2]){
    common = routep[index1];
    index1--;
    index2--;
  }
  return common;
}

bool findroute(TreeNode *head,vector<TreeNode*>& routeq, TreeNode *q){

  if(head == NULL){
    return false;
  }
  
  if(head == q){
    routeq.push_back(head);
    return true;
  }
  
  if(findroute(head->right,routeq,q)){
    routeq.push_back(head);
    return true;
  }
  
  if(findroute(head->left,routeq,q)){
    routeq.push_back(head);
    return true;
  }
  
  return false;
}

