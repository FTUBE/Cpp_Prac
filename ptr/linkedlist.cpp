/*The final node with '.' is also added into the list.*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node; 
typedef Node *nptr;
const int SIZE = 8;

struct Node{
  char word[SIZE];
  nptr next;
};

void newnode(nptr &node);
void createlist(nptr &list);
void printlist(nptr list);

int main(){
  nptr list;
  createlist(list);
  printlist(list);
}

void createlist(nptr &list){
  nptr current, last;
  newnode(list);
  cout << "Type a word" << endl;
  cin >> (list->word);
  if(!(strcmp(list->word,"."))){
    delete list;
    list = NULL;
  }
  
  current = list;
  
  while(current != NULL){
    newnode(current->next);
    cout << "Type a word" << endl;
    current = current->next;
    cin >> (current->word);
    if(!(strcmp((current->word),"."))){
      delete current;
      current = NULL;
    }
  }
}

void newnode(nptr &node){
  node = new (nothrow) Node;
  if(node == NULL){
    cout << "memory insuf." << endl;
    exit(0);
  }
}
  
void printlist(nptr list){
  while(list!=NULL){
    cout << list->word << " ";
    list = list->next;
  }
  cout << endl;
}
