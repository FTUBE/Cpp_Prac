#include<iostream>
#include<vector>

using namespace std;

//void printpattern(char **pattern,int,int);
char** rotate(char **pattern);
char** initialize(int,int);
int* functionpi(char *pattern);
int* kmp(char *str, char *pattern);
void getmatrix(char **matrix,int row, int column);
void where(char **matrix, char **pattern,bool**);
bool compare(char *line, char *pattern,int start);
bool** initialize_bool(int,int);

int* pi;
int column,row;

int main(){

  
  cin >> row >> column;
  if(row < 3 || column < 3){
    return 0;
  }
  cin.ignore();
  char **matrix = initialize(row,column);

  getmatrix(matrix,row,column);
  //printpattern(matrix,row,column);
  char **pattern = initialize(3,3);

  getmatrix(pattern,3,3);
  bool **res = initialize_bool(row+1,column+1);
  
  for(int t = 0; t < 4; t++){
    pi = functionpi(pattern[0]);
    where(matrix,pattern,res);
    pattern = rotate(pattern);
  }
  
  for(int i = 0; i < row+1; i++){
    for(int  j = 0; j < column+1;j++){
      if(res[i][j]){
	printf("%d %d\n",i,j);
      }
    }
    }
  return 0;
}
/*
void printpattern(char **pattern,int row,int column){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      cout<<pattern[i][j];
    }
    cout<<endl;
  }
  }*/

char** rotate(char **pattern){
  char **toret = initialize(3,3);
  for(int i = 0; i < 3; i++){
    for(int  j = 0; j <3;j++){
      toret[j][2-i]  = pattern[i][j];
    }
  }
  return toret;  
}

char** initialize(int r, int c){
  
  char** matrix = new char*[r];
  for(int i = 0; i < r; i++){
    matrix[i] = new char[c];
  }
  return matrix;
}

bool** initialize_bool(int r, int c){
  bool** matrix = new bool*[r];
  for(int i = 0; i < r; i++){
    matrix[i] = new bool[c];
  }
  return matrix;
}

int* kmp(char *str, char *pattern){

  int *toret = new int[column];
  memset(toret,-1,sizeof(int)*column);
  int q = 0;
  int index = 0;
  
  for(int i = 0; i < column; i++){
    while(q > 0 && pattern[q] != str[i]){
      q = pi[q-1];
    }

    if(pattern[q] == str[i]){
      q++;
      if(q == 3){
	toret[index++] = i-q+1;
	q = pi[q-1];
      }
      continue;
    }
  }
  
  return toret;
}

int* functionpi(char *pattern){

  int* toret = new int[3];
  int k = -1;
  int index = 1;
  toret[0] = 0;
  for(int i = 1; i < 3; i++){
    while(k>=0 &&pattern[k+1] != pattern[i]){
      k = toret[k]-1;
    } 
    if(pattern[k+1] == pattern[i]){
      k++;
    }
    toret[index++] = k+1;
  }
  
  return toret;
}

void getmatrix(char **matrix,int r, int c){
  for(int i = 0; i < r;i++){
    for(int j = 0; j < c;j++){
      cin >> matrix[i][j];
      if(matrix[i][j] == '\n'){
	cin >> matrix[i][j];
      }
    }
  }
}

void where(char **matrix, char **pattern,bool** result){
  
  for(int i = 0; i < row-2;i++){
    int* pos = kmp(matrix[i],pattern[0]);
    for(int n = 0; pos[n] != -1;n++){
      if(compare(matrix[i+1],pattern[1],pos[n]) && compare(matrix[i+2],pattern[2],pos[n])){
	result[i+2][pos[n]+2] = true;
      }
    }
  }
}

bool compare(char *line, char *pattern,int start){

  for(int i = 0; i < 3; i++){
    if(line[start+i] != pattern[i]){
      return false;
    }
  }
  return true;
  
}
