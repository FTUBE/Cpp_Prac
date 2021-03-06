#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

const int MAXLENGTH = 1000;


int main(){
  ifstream in;
  ofstream out;
  in.open("B-large-practice.in");
  if(in.fail()){
      return 0;
  }
  out.open("result");
  int cse;
  in>>cse;
  in.ignore();
  string res[100];
  char *line = new char[MAXLENGTH + 1];
  for(int i = 0; i < cse;i++){
    string agg = "";
    in.getline(line,MAXLENGTH);
    char *piece = strtok(line," ");
    while(piece){
      string p(piece);
      if(agg.length() == 0){
	agg = p + agg;
      }
      else{
	agg = p + " "+agg;
      }
      piece = strtok(NULL," ");
    }
    res[i] = agg;
  }
  for(int i = 0; i < cse;i++){
    out << "Case #"<<i+1<<": "<<res[i]<<endl;
  }
  in.close();
  return 0;
}
