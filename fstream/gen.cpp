#include <iostream>
#include <fstream>

using namespace std;

void genfilesize(ofstream& out,int size);

int main(){
  ofstream out;
  out.open("gendata");
  cout << "Type in the size of output file : \n";
  int size;
  cin >> size;
  while(size<0){
    cout << "Cannot be : " << size << ". Retype :\n";
    cin >> size;    
  }
  cout << "Generating.............\n";
  genfilesize(out,size);
  cout << "Done. File size : " << size << " MB\n"; 
}

// Size is in MBytes.

void genfilesize(ofstream& out,int size){
  for(;size>0;size--){
    int KBunit = 1024;
    for(;KBunit>0;KBunit--){
      int Bunit = 1024;
      for(;Bunit>0;Bunit--){
	out.put('w');
      }
    }
  }
  out.close();
}
