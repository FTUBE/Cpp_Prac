#include<iostream>

using namespace std;

int maxnum(int* arr, int n, int card);
int getbyinterval(int *arr, int start, int end,int n);

int main(){
  int num,n,card;
  cin >> num;
  int res[num];
  for(int i = 0; i < num;i++){
    cin >> n >> card;
    int *arr = new int[n];
    for(int k = 0; k < n; k++){
      cin >> arr[k];
    }
    res[i] = maxnum(arr,n,card);
    delete arr;
  }

  for(int i = 0; i < num; i++){
    cout << res[i] << endl;
  }
}

int maxnum(int* arr, int n, int card){
  if(card >= n){
    return 100;
  }
  int max = -1;
  int head = 0;

  while(head + card <= n){
    int cur_max = getbyinterval(arr,head,head+card-1,n);
    if(cur_max > max){
      max = cur_max;
    }
    head++;
  }

  return max;
}

int getbyinterval(int *arr, int start, int end,int n){
  int begin = 0;
  int fin = 101;

  if(start != 0){
    begin = arr[start-1];
  }
  if(end != n-1){
    fin = arr[end+1];
  }
  return fin - begin - 1;
}
