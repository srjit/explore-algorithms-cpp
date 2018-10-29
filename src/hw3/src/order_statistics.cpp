#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <time.h>

using namespace std; 


int randomPartition(int* data, int begin, int end){
  
  srand(time(NULL));
    
  int pivot_index = begin + rand() % (end-begin+1);
  int pivot = data[pivot_index];
  swap(data[pivot_index], data[end]);
    
  pivot_index = end;
  int i = begin - 1;
 
  for(int j=begin; j<=end-1; j++)
    {
      if(data[j] <= pivot)
        {
	  i = i+1;
	  swap(data[i], data[j]);
        }
    }
 
  swap(data[i+1], data[pivot_index]);
  return i+1;
    
}


int randomized_select(int* data, int p, int r, int i){

  if (p == r){
    return data[p];
  }

  int q = randomPartition(data, p, r);
  int k = q - p + 1;

  if(i == k){
    return data[q];
  } else if (i < k){
    return randomized_select(data, p, q-1, i);
  } else {
    return randomized_select(data, q+1, r, i-k);
  }
  
}




int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);   
    return arr[n/2];    
}



void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// It searches for x in arr[l..r], and partitions the array  
// around x. 
int partition(int arr[], int l, int r, int x) 
{ 
    // Search for x in arr[l..r] and move it to end 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
}


int linear_select(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
  
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++) {
            median[i] = findMedian(arr+l+i*5, 5);
	}
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        int medOfMed = (i == 1)? median[i-1]: 
                                 linear_select(median, 0, i-1, i/2); 
  
        int pos = partition(arr, l, r, medOfMed); 
  
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return linear_select(arr, l, pos-1, k); 
  
        return linear_select(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 


int main()
{

  int size = 100;
  
  int input[size];

  for(int i=0;i<100;i++){
    input[i] = i+1;
  }

  /*
   * Create a random permutation of the numbers in the input array
   */
  random_shuffle(&input[0], &input[size-1]);

  int i;
  cout<<"Input i for finding the ith smallest element from the random partition: ";
  cin>>i;

  cout<<"Finding ith smallest number from the array using random select...\n";

  int rand_select_op = randomized_select(input, 0, 100, i+1);
  cout<<i<<"th smallest element is: "<<rand_select_op<<"\n";

  // selection in worst case linear time
  int linear_select_op = linear_select(input, 0, 99, i+1);
  cout<<i<<"th smallest element is: "<<linear_select_op<<"\n";  
    
}
