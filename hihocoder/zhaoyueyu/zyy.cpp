#include<iostream>
#include<vector>

using namespace std;

const int MAXLENGTH = 200;

char* replace_str(char*);
bool compare_case(char* tomp, char* str);

int main(){
  char *line = new char[MAXLENGTH+1];
  while(cin.getline(line, MAXLENGTH)){
    char *res = replace_str(line);
    while(*res != '\0'){
      cout << *(res++);
    }
    cout << endl;
  }
  return 0;
}

char* replace_str(char* str){
  int len = strlen(str);
  if(len < 9){
    return str;
  }
  char *res = new char[len + 1];
  char *pointer = res;
  char comp[10] = "marshtomp";
  char replace[8] = "fjxmlhx";

  vector<int> arr;
  
  for(int i = 0; i < len; i++){
    if(len - i < 9){
      break;
    }
    if(str[i] == 'm' || str[i] == 'M'){
      arr.push_back(i);
    }
  }
  
  int index = 0;
  int i = 0;
  for(int i = 0; i < len; i++){
    if(index >= arr.size() || i != arr[index]){
      *(pointer++) = str[i];
      continue;
    }
    index++;
    if(compare_case(comp,str+i)){
      strcpy(pointer,replace);
      pointer = pointer + 7;
      i += 8;
      index++;
      continue;
    }
    
    *(pointer++) = str[i];
  }

  *pointer = '\0';
  
  return res;
}

bool compare_case(char* tomp, char* str){
  for(int i = 0; i < 9; i++){
    int red = str[i] - tomp[i];
    if(red != 0 && red != -32){
      return false;
    }
  }
  return true;
}
