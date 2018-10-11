#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int randomPartition(int* arr, int start, int end)
{
    srand(time(NULL));
    
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]);
    
    pivotIdx = end;
    int i = start -1;
 
    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
	    swap(arr[i], arr[j]);
        }
    }
 
    swap(arr[i+1], arr[pivotIdx]);
    return i+1;
}

 
void randomQuickSort(int* arr, int start, int end)
{
    if(start < end) {
        int mid = randomPartition(arr, start, end);
        randomQuickSort(arr, start, mid-1);
        randomQuickSort(arr, mid+1, end);
    }
}


int main()
{
  int A[100];

  for(int i=0;i<100;i++){
    A[i] = i+1;
  }

  clock_t start = clock();
  randomQuickSort(A, 0, 100);
  clock_t end = clock();    

  cout<<"After sorting: ";
   for(int i=0;i<100;i++){
     cout<<A[i]<<"\t";
   }
   cout<<"\n";

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Quicksort took %f seconds to finish \n", cpu_time_used);
  
  
   
}
