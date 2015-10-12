#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int SIZE = 35;
int maxprofit_td(int);
int maxprofit_td_dp(int);
int maxprofit_btmup_dp(int length);

int R[SIZE+1];
int cost[SIZE+1] = {-1,3,4,6,9,16,20,22,24,26,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,59,60,61,62,63,64,65};

struct cmp{
  bool operator()(int a, int b){
    if(a <= b){
      return true;
    }
    return false;
  }
};

int main(){
  int mp = maxprofit_btmup_dp(SIZE);
  cout << "MAXPROFIT "<<mp << endl;
  return 0;
}

int maxprofit_td(int length){
  priority_queue<int,vector<int>,cmp> queue;
  //cout<<"R["<<length<<"]";
  if(length == 1){
    return cost[1];
  }

  for(int i = 1; i < length; i++){
    int p = cost[i] + maxprofit_td(length-i);
    queue.push(p);
  }
  return queue.top();
}

int maxprofit_td_dp(int length){
  priority_queue<int,vector<int>,cmp> queue;
  //cout<<"R["<<length<<"]";
  if(R[length]!=0){
    return R[length];
  }
  
  if(length == 1){
    R[length] = cost[1];
    return cost[1];
  }

  for(int i = 1; i < length; i++){
    int p = cost[i] + maxprofit_td_dp(length-i);
    queue.push(p);
  }
  R[length] = queue.top();
  return queue.top();
}

int maxprofit_btmup_dp(int length){
  
  for(int i = 1 ; i <= length; i++){
    if(i == 1){
      R[i] = cost[i];
      continue;
    }
    priority_queue<int,vector<int>,cmp> queue;
    for(int n = 1; n < i; n++){
      //      cout<<"R["<<i-n<<"]";
      queue.push(cost[n] + R[i-n]);
    }
    R[i] = queue.top();
  }
  return R[length];
}
