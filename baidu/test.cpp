#include<iostream>

using namespace std;

int main(){
  int n,t,c;
  cin >> n>>t>>c;
  int array[n];
  for(int i = 0;i<n;i++){
    cin>>array[i];
  }
  
  int sum = 0;
  int times = 0;
  for(int i = 0; i<n;i++){
    bool find = true;
    sum = 0;
    for(int k = 0; k<c;k++){
      if(k+i == n){
	cout<<times<<endl;
	return 0;
      }
      sum += array[k+i];
      if(sum > t){
	find =false;
	break;
      }
    }
    if(find){
      times++;
    }
  }
  cout<<times<<endl;
}
