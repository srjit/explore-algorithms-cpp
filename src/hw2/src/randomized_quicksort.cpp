#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h> 

using namespace std;

int random_partition(int* arr, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]); // move pivot element to the end
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

 
void random_quick_sort(int* arr, int start, int end)
{
    if(start < end) {
        int mid = random_partition(arr, start, end);
        random_quick_sort(arr, start, mid-1);
        random_quick_sort(arr, mid+1, end);
    }
}

int main()
{
    int A[] = {2,5,7,1,10,8,9};
    random_quick_sort(A, 0,6);

    for(int i=0;i<7;i++){
      cout<<A[i];
    }
}
