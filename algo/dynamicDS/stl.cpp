#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
  queue<int> queue1;
  for(int i = 0;i<128; i++){
    queue1.push(i);
  }
  while(!queue1.empty()){
    cout << queue1.front()<<endl;
    queue1.pop();
  }
}
