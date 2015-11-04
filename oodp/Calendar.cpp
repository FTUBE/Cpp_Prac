#include "Calendar.h"
#include "Date.h"

Calendar::Calendar(int d1, int m1,int y1,int d2,int m2,int y2){
  a = Date(d1,m1,y1);
  b = Date(d2,m2,y2);
};
