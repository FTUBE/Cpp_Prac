#include<iostream>

using namespace std;

const int MAXLENGTH = 101;

int parse(char*);
int clear(char*);
void ins(char* str, int offset,char inchar);

int main(){

  int num;
  cin >> num;
  cin.ignore();
  int res[num];

  int size = num;
  
  char *line = new char[MAXLENGTH];

  int index = 0;
  
  while(num-- > 0){
    cin.getline(line,MAXLENGTH);
    res[index++] = parse(line);
  }

  for(int i = 0; i < size; i++){
    cout << res[i] << endl;
  }
  return 0; 
}

int parse(char* str){
  int max = -1;
  char *cpy = new char[strlen(str)+2];
  int len = strlen(str);
  for(int i = 0; i < 3;i++){
    for(int n = 0; n <= len; n++){
      strcpy(cpy,str);
      ins(cpy,n,'A'+i);
      int cur = clear(cpy);
      if(cur > max){
	max = cur;
	if(max == len + 1){
	  return max;
	}
      }
    }
  }
  return max;
}

int clear(char *str){

  char *newone = new char[strlen(str) + 1]; 
  char *prev = str;
  int index = 0;

  while(true){
    int prevlen = strlen(prev);
    for(int i = 0; i < prevlen;i++){
      int mae = i-1;
      int ato = i+1;
      if(mae == -1){
	if(prev[ato] != prev[i]){
	  newone[index++] = prev[i];
	}
	continue;
      }
      if(ato == prevlen){
	if(prev[mae] != prev[i]){
	  newone[index++] = prev[i];
	}
	continue;
      }
      if(prev[mae] != prev[i] && prev[i] != prev[ato]){
	newone[index++] = prev[i];
      }
    }
    
    newone[index] = '\0';
    index = 0;

    if(prevlen == strlen(newone)){
      break;
    }
    prev = newone;
    newone = new char[strlen(newone) + 1];
  }

  return strlen(str) - strlen(prev);
}

void ins(char* str, int offset,char inchar){

  while(offset != 0){
    offset--;
    str++;
  }
  
  char prev = *str;
  *str = inchar;
  str++;
  while(prev != '\0'){
    char tmp = *str;
    *str = prev;
    prev = tmp;
    str++;    
  }
  *str = '\0';
}
