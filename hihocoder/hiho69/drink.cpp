#include<iostream>
#include<climits>

using namespace std;

int drink(int*,int);
bool isT(int T, int n, int* arr);

int main(){
  int n,k;
  cin >> n >> k;
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  printf("%d\n",drink(arr,n));
  return 0;
}

int drink(int* arr, int size){

  if(size == 1){
    return arr[0] + 1;
  }
  int upper = INT_MIN;
  int lower = INT_MAX;

  for(int i = 0 ; i < size; i++){
    if(arr[i] > upper){
      upper = arr[i];
    }
    if(arr[i] < lower){
      lower = arr[i];
    }
  }
  
  while(upper != lower){
    int mid = (upper + lower) / 2;
    if(!isT(mid,size,arr)){
      lower = mid + 1;
      continue;
    }
    upper = mid;
  }
  
  return upper;
}

bool isT(int T, int n, int* arr){

  int ho = 0;
  int remain = 0;

  for(int i = 0; i < n; i++){
    remain += T;
    if(remain <= arr[i]){
      remain = 0;
      if(2*i-2*ho >= n-2){
	return false;
      }
      continue;
    }
    remain -= arr[i];
    ho++;
    if(2*i - 2*ho >= n-2){
      return false;
    }
  }
  
  if(ho > n - ho){
    return true;
  }
  
  return false;
}
