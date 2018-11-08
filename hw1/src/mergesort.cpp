#include <iostream>
#include <time.h>


int *get_input(int limit){

  int* input = new int[limit];

  int j = 0;
  for(int i=1000; i>1000-limit; i--){
    input[j] = i;
    j+=1;
  }

  return input;
}



void copyMergedArrays(int original[], int merged[], int length, int left_low) {
    for (int i=0; i< length; ++i)
        original[left_low++] = merged[i];
}

void merge(int input[], int left_low, int left_high, int right_low, int right_high) {

    int length = right_high-left_low+1;
    int merged_array[length];
    int left = left_low;
    int right = right_low;

    auto left_array_exhausted = [&left, &left_high]() { return left > left_high;};
    auto right_array_exhausted = [&right, &right_high]() { return right > right_high;};

    for (int i = 0; i < length; ++i) {
        if (left_array_exhausted())
            merged_array[i] = input[right++];
        else if (right_array_exhausted())
            merged_array[i] = input[left++];
        else if (input[left] <= input[right])
            merged_array[i] = input[left++];
        else
            merged_array[i] = input[right++];
    }
    copyMergedArrays(input,  merged_array, length, left_low);

}

void merge_sort(int numbers[], int low, int high) {

    if (low >= high)
        return;

    else {
        int mid = (low + high)/2;
        merge_sort(numbers, low, mid);
        merge_sort(numbers, mid+1, high);
        merge(numbers, low, mid, mid+1, high);
    }

}


int main(){


    int limit;
    
    std :: cout << "Enter limit: ";
    std :: cin >> limit;

    int* input = get_input(limit);

    std :: cout << "Sorting using mergesort: ";

    clock_t start = clock();

    merge_sort(input, 0, limit-1);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Merge Sort took %f seconds to finish \n", cpu_time_used);

}





