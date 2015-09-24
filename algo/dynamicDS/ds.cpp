#include <iostream>
#include "structures.h"

using namespace std;

void teststack(stack& a);
void testPQueue(PQueue& pq);
void BSTtest(BST& bst);
ListNode* createNode(int);
ListNode* reverse(ListNode* head);
ListNode* reverse_norecur(ListNode* head);
ListNode* insertion(ListNode* head);

int main(){
  stack a;
  PQueue pq;
  BST binarytree;
  int n = 671;
  ListNode *head = createNode(7);
  head->print();
  cout << "Reverse" << endl;
  //  head = reverse_norecur(head);
  head = insertion(head);
    head->print();
  /*ListNode *truehead = head;
    while(truehead->next != NULL){
    truehead = truehead -> next;
  }
  head = reverse(head);
  head->next = NULL;
  head = truehead;*/
  //head->print();
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

ListNode* createNode(int count){
  ListNode* head = new ListNode(0);
  ListNode* current = head;
  for(int i = 1; i < count; i++){
    current -> next = new ListNode(i);
    current = current->next;
  }
  return head;
}

ListNode* reverse(ListNode* head){
  if(head->next == NULL){
    return head;
  }
  reverse(head->next)->next = head;
  return head;
}

ListNode* reverse_norecur(ListNode* head){
  ListNode* prev = NULL;
  ListNode* nextnode = NULL;
  ListNode* cur = head;

  while(cur != NULL){
    if(cur ->next == NULL){
      cur -> next = prev;
      break;
    }
    if((cur->next)->next == NULL){
      ListNode* tempnext = cur->next;
      tempnext->next = cur;
      cur->next = prev;
      cur = tempnext;
      break;
    }
    nextnode = (cur->next)->next;
    ListNode* tempnext = cur->next;
    cur->next = prev;
    tempnext -> next= cur;
    prev = tempnext;
    cur = nextnode;
  }
  return cur;
}

// Insetion method of l1->l2->l3->l4->l5->NULL, to l1->l4->l2->l5->l3->NULL.
// l1->l2->l3->l4->NULL, to l1->l3->l2->l4->NULL.

ListNode* insertion(ListNode* head){
  ListNode* cur = head;
  int n = 0;
  while(cur != NULL){
    n++;
    cur = cur->next;
  }
  n++;
  n = n / 2;
  ListNode* slow = head;
  ListNode* fast = head;
  while(n>0){
    fast = fast -> next;
    n--;
  }
  ListNode* marker = fast;
  ListNode* slowprev = NULL;
  ListNode* fastprev = NULL;
  while(fast != NULL){
    slowprev = slow;
    fastprev = fast;
    ListNode* slownext = slow->next;
    ListNode* fastnext = fast->next;
    slow->next = fast;
    fast->next = slownext;
    slow = slownext;
    fast = fastnext;
  }
  if(slow != marker){
    slow -> next = NULL;
  }
  else{
    cout << slowprev->val << endl;
    cout << fastprev->val << endl;
    slowprev->next = fastprev;
    fastprev->next = NULL;
  }
  return head;
}
