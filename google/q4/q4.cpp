#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Time{

 private:
  int second;
  int min;
  int hour;
  int total_second;

 public:
  Time();
  Time(string time);
  int get_total_second();
  int get_hour();
};

int Time::get_total_second(){
  return total_second;
}

int Time::get_hour(){
  return hour;
}


Time::Time(){
  second = 0;
  min = 0;
  hour = 0;
  total_second = 0;
}

Time::Time(string time){
  char *t = new char[time.length()+1];
  string tmp;
  strcpy(t, time.c_str());
  char *ptr = strtok(t, ":");
  int counter = 0;
  while(ptr){
    tmp = string(ptr);
    if(counter == 0)
      hour = stoi(tmp);
    else if(counter == 1)
      min = stoi(tmp);
    else if(counter == 2)
      second = stoi(tmp);
    counter++;
    ptr = strtok(NULL, ":");
  }
  //  cout << hour << ":" << min << ":" << second <<endl;
  total_second = 3600*hour + 60*min + second;
  //cout << "total: " << total_second << endl;
}

int subtime(Time small, Time large);
int sleep_time(Time get_up, Time sleep);




int main(){
  Time g("00:00:00");
  Time w("12:00:00");
  Time h("12:00:01");
  Time b("23:59:59");
  Time x("00:00:02");
  int total = sleep_time(w,g) + sleep_time(b,h);

  int res  = total/2;
  if(total % 2== 0){
    res++;
  }
  res *= 2;
  cout << res<<endl;
    /*  if(subtime(w, h) > x.get_total_second())
    cout << -1 << endl;
  if(sleep_time(g, b) > x.get_total_second())
    cout << -1 << endl;
    */

  return 0;

}


int subtime(Time small, Time large){
  return large.get_total_second() - small.get_total_second();
}

int sleep_time(Time get_up, Time sleep){
  if(get_up.get_hour() < sleep.get_hour())
    return get_up.get_total_second()+24*3600 - sleep.get_total_second();
  else
    return  get_up.get_total_second() - sleep.get_total_second();
}
