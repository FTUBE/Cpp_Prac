#include<iostream>

using namespace std;

const int MAXLENGTH = 1024;
int* maxPalindrome(char *str,int,int);
bool isPalindrome(char *str, int start, int end);
int ***R;

int main(){
  
  char *str = new char[MAXLENGTH+1];
  cin.getline(str,MAXLENGTH);
  R = new int**[MAXLENGTH];
  
  for(int i = 0; i < MAXLENGTH; i++){
    R[i] = new int*[MAXLENGTH];
  }
  
  for(int i = 0; i < MAXLENGTH; i++){
    for(int j = 0; j < MAXLENGTH; j++){
      R[i][j] = NULL;
    }
  }
  
  int *maxpiece = maxPalindrome(str, 0, strlen(str)-1);
  cout << "\nPalindrome : \n"<< endl;

  for(int i = maxpiece[0]; i <= maxpiece[1];i++){
    cout << str[i];
  }
  
  cout<<endl;
  
  return 0;

}

int* maxPalindrome(char *str, int start, int end){

  if(R[start][end]){
    return R[start][end];
  }
  
  int *max = new int[2];
  memset(max, -1, sizeof(int)*2);
  
  for(int i = start; i <= end;i++){
    for(int j = i; j <= end;j++){
      bool isPalin = isPalindrome(str,i,j);
      if(isPalin && j-i >= max[1]-max[0]){
	max[0] = i;
	max[1] = j;
      }
    }
  }

  R[start][end] = max;

  return max;
}

bool isPalindrome(char *str, int start, int end){
  while(end > start){
    if(str[end--] != str[start++]) return false;
  }
  return true;
}
