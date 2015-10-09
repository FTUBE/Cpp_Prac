#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculate(string line);
int reduce(string line);

int main(){
  int count = 0;
  cin >> count;
  vector<string> list;
  char array[100];
  cin.ignore();
  while(count>0){
    cin.getline(array,100);
    string str(array);
    cout << calculate(str)<<endl;
    count--;
  }
  
  return 0;
}

int calculate(string line){
  int maximum = -1;
  for(int i = 0; i <= line.length();i++){
    string l1(line);
    string l2(line);
    string l3(line);
    l1.insert(i,1,'A');
    l2.insert(i,1,'B');
    l3.insert(i,1,'C');
    int r1 = reduce(l1);
    int r2 = reduce(l2);
    int r3 = reduce(l3);
    maximum = max(max(max(r1,r2),r3),maximum);
  }
  
  return maximum;
}

int reduce(string line){
  string toret = "";
  int index = 0;
  if(line.compare("") == 0){
    return 0;
  }
  //    cout<<line<<" length : "<<line.length()<<endl;
  while(index < line.length()){
    char current = line[index];
    int duplicate = 0;
    while(index < line.length()){
      if(line[index] == current){
	duplicate++;
	index++;
	continue;
      }
      break;
    }
    if(duplicate == 1){
      toret.push_back(current);
    }
  }
  int red = line.length()-toret.length();
  if(red == 0){
    return 0;
  }
  int total = red + reduce(toret);
  return total;
}
