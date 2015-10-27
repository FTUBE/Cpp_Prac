#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

vector<int> inor;
vector<int> poor;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(vector<int>& inor,vector<int>& poor,int iostart, int ioend, int postart, int poend);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

int main(){
  vector<int> inorder;
  vector<int> postorder;
  inorder.push_back(1);
  inorder.push_back(2);
  inorder.push_back(3);
  inorder.push_back(4);
  inorder.push_back(5);
  inorder.push_back(6);
  postorder.push_back(5);
  postorder.push_back(6);
  postorder.push_back(4);
  postorder.push_back(3);
  postorder.push_back(2);
  postorder.push_back(1);
  buildTree(inorder,postorder);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

  inor = inorder;
  poor = postorder;

  int end = inor.size()-1;

  TreeNode* toret = helper(inor,poor,0,end,0,end);

  return toret;
}

TreeNode* helper(vector<int>& inor,vector<int>& poor,int iostart, int ioend, int postart, int poend){
  cout << "("<<iostart<<","<<ioend<<","<<postart<<","<<poend<<")"<<endl;
  
  if(ioend < iostart || poend < postart){
    return NULL;
  }

  TreeNode* toret = new TreeNode(poor[poend]);

  if(ioend == iostart || postart == poend){
    return toret;
  }

  int place = -1;
  int value = toret->val;

  for(int i = 0; i <= ioend;i++){
    if(inor[iostart+i] == value){
      place = i;
      break;
    }
  }
  cout<<place<<endl;
  toret -> right = helper(inor,poor,iostart+place+1,ioend,postart+place,poend-1);
  toret -> left = helper(inor,poor,iostart,iostart+place-1,postart,postart+place-1);

  return toret;
}
