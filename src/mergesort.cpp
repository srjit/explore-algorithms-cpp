#include <iostream>

void merge(int a[], int left_low, int left_high, int right_low, int right_high) {
  
    int length = right_high-left_low+1;
    int temp[length];
    int left = left_low;
    int right = right_low;
    
    for (int i = 0; i < length; ++i) { 
        if (left > left_high)
            temp[i] = a[right++];
        else if (right > right_high)
            temp[i] = a[left++];
        else if (a[left] <= a[right])
            temp[i] = a[left++];
        else
            temp[i] = a[right++]; 
    }
    
    for (int i=0; i< length; ++i) 
        a[left_low++] = temp[i];
    
}

void merge_sort(int a[], int low, int high) {
  
    if (low >= high)
      return;                         
    
    else {
      int mid = (low + high)/2;
      merge_sort(a, low, mid);        
      merge_sort(a, mid+1, high);     
      merge(a, low, mid, mid+1,high); 
    }
    
}


int main(){

  int limit, i;
  
  std :: cout <<"Enter limit";
  std :: cin>> limit;

  int* input = new int[limit];
  
  std :: cout <<"Enter array to sort";
  for (i=0; i< limit; i++){
    std :: cin >> input[i];
  }


  std :: cout << "Using mergesort";
  merge_sort(input, 0, limit-1);
 
  for(i = 0; i< limit; i++){
    std :: cout << input[i];
  }
  

  
}
