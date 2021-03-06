#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Date{
  int d,m,y;
  Date(int _d,int _m, int _y):d(_d),m(_m),y(_y){
  };
  Date(){};
};

char months[12][12] = {{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}};

Date parse(char *str);
int calc(Date&,Date&);
int cstrtoi(char *str);
bool isrun(int year);

const int MAXLENGTH = 128;

int main(){

  int cse;
  cin >> cse;
  Date d[1100];
  cin.ignore();
  for(int i = 0; i < cse; i++){
    char str[MAXLENGTH];
    cin.getline(str,MAXLENGTH);
    d[2*i] = parse(str);
    cin.getline(str,MAXLENGTH);
    d[2*i + 1] = parse(str);
  }
    
  int res[cse];
  
  for(int i = 0; i <cse;i++){
    res[i] = calc(d[2*i],d[2*i + 1]);
  }
  
  for(int i = 0; i < cse; i++){
    printf("Case #%d: %d\n",i+1,res[i]);
  }
  return 0;
}

Date parse(char *str){
  char *piece = strtok(str," ,");
  int month,day,year;

  for(int i = 0; i < 12;i++){
    if(strcmp(piece,months[i]) == 0){
      month = i + 1;
      break;
    }
  }
  
  piece = strtok(NULL," ,");
  day = cstrtoi(piece);
  piece = strtok(NULL," ,");
  year = cstrtoi(piece);
  Date toret(day,month,year);
  return toret;
}

int calc(Date& a,Date& b){
  int sum = 0;
  bool ra,rb;
  ra = isrun(a.y);
  rb = isrun(b.y);
  
  for(int i = 1; a.y + i < b.y ;i++){
    if(isrun(a.y + i)){
      sum++;
    }
  }

  if(a.y == b.y && ra && a.m <=2 && a.d <=29){
    sum++;
    return sum;
  }
  
  if(ra && a.m <=2 && a.d <= 29){
    sum++;
  }

  if(rb){
    if(b.m >2 || (b.m ==2 && b.d ==29))
      sum++;
  }
  
  return sum;
}

bool isrun(int year){
  if(((year&3) == 0) && (year%100 !=0)){
    return true;
  }
  if((year&399) ==0){
    return true;
  }
  return false;
}

int cstrtoi(char *str){
  int len = strlen(str);
  int sum = 0;			
  for(int i = 0;i < len;i++){
    sum += (str[i] - '0') * pow(10,len-i-1);
  }
  return sum;
}
