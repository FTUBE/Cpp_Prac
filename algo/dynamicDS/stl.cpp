#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
  priority_queue<int,vector<int>,greater<int> > queue1;
  int num;
  for(int i = 5;i > 0; i--){
    cin>>num;
    queue1.push(num);
  }
  while(!queue1.empty()){
    cout << queue1.top()<<endl;
    queue1.pop();
  }
}
