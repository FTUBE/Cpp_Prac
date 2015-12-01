#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream in;
  in.open("A-large-practice.in");
  if(in.fail()){
    cout<<"Fail\n";
    return 0;
  }
  ofstream out;
  out.open("result");
  
  int cse;
  in >> cse;
  in.ignore();
  int *res[cse];
  for(int i = 0; i < cse;i++){
    res[i] = new int[2];
  }
  for(int i = 0;i < cse;i++){
    int credit;
    int num;
    in >> credit;
    in >> num;
    int arr[num];
    for(int n = 0; n < num;n++){
      in >> arr[n];      
    }
    
    for(int j = 0; j < num;j++){
      bool skip = false;
      for(int k = j+1; k < num;k++){
	if(arr[j] + arr[k] == credit){
	  res[i][0] = j;
	  res[i][1] = k;
	  skip = true;
	  break;
	}
      }
      if(skip) break;
    }
  }
  for(int i = 0; i < cse;i++){
    out << "Case #"<<i+1<<": "<<res[i][0]+1<<" "<<res[i][1]+1<<endl; 
  }
  out.close();
  
  return 0;
}
