#include<iostream>
#include<string>

using namespace std;

int LCS(int,int);
int maxv(int a, int b);
int LCS_aux(int la, int lb);
int LCS_btmup(int la, int lb);

string x = "AGCGATATCCACTG";
string y = "TCACGCATAGGACT";
int mem[15][15];

int main(){
  //  int maxlength = LCS_aux(x.length(),y.length());
  int maxlength = LCS_btmup(x.length(),y.length());
  cout<<maxlength<<endl;
}

int LCS(int la, int lb){
  cout<< "R["<<la<<","<<lb<<"]"; 
  if(lb == 0 || la ==0){
    return 0;
  }
  if(x[la-1] == y[lb-1]){
    return 1 + LCS(la-1,lb-1);
  }
  int asearch = LCS(la-1,lb);
  int bsearch = LCS(la,lb-1);
  int res = maxv(asearch,bsearch);
  return res;
}


int maxv(int a, int b){
  if(a<b){
    return b;
  }
  return a;
}

int LCS_aux(int la, int lb){
  if(lb == 0 || la ==0){
    mem[la][lb] = 0;
    return 0;
  }
  if(mem[la][lb] > 0){
    return mem[la][lb];
  }
  cout<<"R["<<la<<","<<lb<<"]";
  if(x[la-1] == y[lb-1]){
    int res =  1 + LCS_aux(la-1,lb-1);
    mem[la][lb] = res;
    return res;
  }
  int asearch = LCS_aux(la-1,lb);
  int bsearch = LCS_aux(la,lb-1);
  mem[la][lb] = maxv(asearch,bsearch);
  return mem[la][lb];
}

int LCS_btmup(int la, int lb){
  for(int i = 0;i <= la;i++){
    for(int n = 0;n <= lb;n++){
      if(i==0 || n==0){
	mem[i][n] = 0;
	continue;
      }
      if(x[i-1] == y[n-1]){
	mem[i][n] = 1 + mem[i-1][n-1];
	//	cout<<mem[i][n];
	continue;
      }
      int shorta = mem[i-1][n];
      int shortb = mem[i][n-1];
      mem[i][n] = maxv(shorta,shortb);
    }
  }
  return mem[la][lb];
}
