#include<iostream>
#include<climits>

using namespace std;

const int SIZE = 8;
int findmax(int arr[]);

int main(){
  int arr[SIZE] = {1,15,4,5,5,7,8,11};
  int max = findmax(arr);
  int count[max+1];
  for(int i = 0;i<max+1;i++){
    count[i] = 0;
    //    cout<<count[i]<<" ";
  }
  for(int i = 0 ;i<SIZE;i++){
    count[arr[i]] +=1;
  }
  
  int toret[SIZE];
  
  for(int i = 1;i<max+1;i++){

    count[i] = count[i]+count[i-1];
    //cout<<count[i]<<" ";
  }
  
  for(int i = 0;i<SIZE;i++){
    toret[count[arr[i]]-1] = arr[i];
    count[arr[i]] -=1;
  }
  for(int i = 0; i<SIZE;i++){
     cout<<toret[i]<<" ";
  }
  cout<<endl;
}

int findmax(int arr[]){
  
  int max = INT_MIN;
  
  for(int i = 0; i < SIZE;i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

