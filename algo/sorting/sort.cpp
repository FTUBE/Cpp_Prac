#include <iostream>
#include "sort.h"

using namespace std;

void insertionsort(int arr[],int length){
  int pointer = 1;
  while((pointer)!=length){
    int p_value = arr[pointer];
    for(int i = pointer - 1; i >= -1; i--){
      if(i == -1 || arr[i] < p_value){
	arr[i+1] = p_value;
	break;
      }
      arr[i+1] = arr[i];
    }
    pointer++;
  }
}

//4,5,6,3


void mergesort(int arr[], int from, int to){
  if(to==from){
    return;
  }
  int mid = (to + from) / 2;
  mergesort(arr,from,mid);
  mergesort(arr,mid+1,to);
  merge(arr,from,mid,to);
}

void merge(int arr[],int from,int mid,int to){
  //  cout << "Merge" << from << " " << mid << " " << to << endl;
  int size1 = mid - from + 1;
  int size2 = to - mid;
  int left[size1];
  int right[size2];

  copy(arr,from,mid,left);
  copy(arr,mid + 1,to,right);
    
  int point1 = 0;
  int point2 = 0;
  int k = 0;
  
  while((from + k) <= to){
    if(point1 == size1){
      while(point2 != size2){
	arr[from + k] = right[point2];
	k++;
	point2++;
      }
      break;
    }
    
    if(point2 == size2){
      while(point1 != size1){
	arr[from + k] = left[point1];
	k++;
	point1++;
      }
      break;
    }

    if(left[point1] >= right[point2]){
      arr[from + k] = right[point2];
      point2++;
    }
    else{
      arr[from + k] = left[point1];
      point1++;
    }
    k++;
    }
}

void copy(int arr[],int from, int to,int copy[]){
  for(int i = 0; i < (to - from + 1);i++){
    copy[i] = arr[from + i];
  }
}
