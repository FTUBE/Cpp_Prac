#include "Date.h"
#include <iostream>

using namespace std;

int Date::counter = 0;

Date::Date(int d,int m, int y){
  if(d < 1 || d > 31){
    cout << d << "Illegal day\n";
    d = 1;
  }
  if(m < 1 || m > 12){
    cout << m << "Illegal month\n";
    m = 1;
  }
  if(y < 1900 || y > 3000){
    cout << y << "Illegal year\n";
    y = 2000;
  }
  day = d; month = m; year = y;
  counter++;
};

Date::~Date(){
  counter--;
};
Date Date::nextDate() const{
  int newd = day+1;
  int newm = month;
  int newy = year;
  
  if(newd > 31){
    newd = 1;
    newm++;
  }
  
  if(newm > 12){
    newm = 1;
    newy++;
  } 

  Date date(newd, newm, newy);
  return date;
};

void Date::next(){
  day++;
  if(day > 31){
    day = 1;
    month++;
  }
  if(month > 12){
    month = 1;
    year++;
  } 
};

bool Date::equal(Date aDate){
  return aDate.month == month && aDate.year == year && aDate.day == day;
};

void Date::print() const{
  printf("%d / %d / %d\n",day,month,year);
};

void Date::c(){
  printf("Number of dates : %d\n", counter);
}
