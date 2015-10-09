#include <iostream>

using namespace std;

float getdis(float x, float y, float x1, float y1);
bool onpoint(float x, float y, float rad, float x1, float y1);

int main(){
  float x,y,radius;

  cin >> x >> y >> radius;

  float max = -1,outx,outy;
  float curx = (float)(int) x;
  float cury = (float)(int) y;

  for(float dx = 0; (dx+curx) <= x+radius; dx++){
    for(float dy = 0;(dy+cury) <= y +radius;dy++){
      if(!onpoint(x,y,radius,dx+curx,dy+cury)){
	continue;
      }
      float dis = getdis(x,y,curx+dx,cury+dy);
      if(dis > max){
	max = dis;
	outx = dx + curx;
	outy = dy + cury;
      }
      if(dis == max){
	if(dx + curx > outx){
	  outx = dx + curx;
	  outy = dy + cury;
	  continue;
	}
	else if(dx + curx == outx){
	  if(dy + cury > outy){
	    outx = dx + curx;
	    outy = dy + cury;
	    continue;
	  }
	}
	else{
	  continue;
	}
      }
    }
  }

  for(float dx = 0; (dx+curx) >= y-radius; dx--){
    for(float dy = 0;(dy+cury) >= y -radius;dy--){
      if(!onpoint(x,y,radius,dx+curx,dy+cury)){
	continue;
      }
      float dis = getdis(x,y,curx+dx,cury+dy);
      if(dis > max){
	max = dis;
	outx = dx + curx;
	outy = dy + cury;
      }
      if(dis == max){
	if(dx + curx > outx){
	  outx = dx + curx;
	  outy = dy + cury;
	  continue;
	}
	else if(dx + curx == outx){
	  if(dy + cury > outy){
	    outx = dx + curx;
	    outy = dy + cury;
	    continue;
	  }
	}
	else{
	  continue;
	}
      }
    }
  }

  for(float dx = 0; (dx+curx) <= x+radius; dx++){
    for(float dy = 0;(dy+cury) >= y - radius;dy--){
      if(!onpoint(x,y,radius,dx+curx,dy+cury)){
	continue;
      }
      float dis = getdis(x,y,curx+dx,cury+dy);
      if(dis > max){
	max = dis;
	outx = dx + curx;
	outy = dy + cury;
      }
      if(dis == max){
	if(dx + curx > outx){
	  outx = dx + curx;
	  outy = dy + cury;
	  continue;
	}
	else if(dx + curx == outx){
	  if(dy + cury > outy){
	    outx = dx + curx;
	    outy = dy + cury;
	    continue;
	  }
	}
	else{
	  continue;
	}
      }
    }
  }

  for(float dx = 0; (dx+curx) >= x-radius; dx--){
    for(float dy = 0;(dy+cury) <= y +radius;dy++){
      if(!onpoint(x,y,radius,dx+curx,dy+cury)){
	continue;
      }
      float dis = getdis(x,y,curx+dx,cury+dy);
      if(dis > max){
	max = dis;
	outx = dx + curx;
	outy = dy + cury;
      }
      if(dis == max){
	if(dx + curx > outx){
	  outx = dx + curx;
	  outy = dy + cury;
	  continue;
	}
	else if(dx + curx == outx){
	  if(dy + cury > outy){
	    outx = dx + curx;
	    outy = dy + cury;
	    continue;
	  }
	}
	else{
	  continue;
	}
      }
    }
  }

  cout << outx << " "<<outy<<endl;
  
  return 0;

}

float getdis(float x, float y, float x1, float y1){
  return (x1-x)*(x1-x) + (y1-y)*(y1-y);
}

bool onpoint(float x, float y, float rad, float x1, float y1){
  if(getdis(x,y,x1,y1) <= rad*rad){
    return true;
  }
  return false;
}
