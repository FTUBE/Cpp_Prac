#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<int> iv;
  cout << "vector length :" << iv.size() << endl;
  cout << "push_back(1) : " << endl;
  iv.push_back(1);
  cout << iv[0] << endl;
  cout << "Insert : " << endl;
  for(int i = 2; i <= 5 ;i++){
    iv.insert(iv.begin(),i);
  }
  for(unsigned long i = 0; i < iv.size();i++){
    cout << iv[i] << " ";
  }
  cout<<endl;
  cout << "Erase" << endl;

  iv.erase(iv.begin()+3);
    for(unsigned long i = 0; i < iv.size();i++){
    cout << iv[i] << " ";
  }
    iv.pop_back();
}
