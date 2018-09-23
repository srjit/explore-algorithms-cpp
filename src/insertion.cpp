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


int *insertion_sort(int input[], int limit){

  int i, j, temp;

  for (i=0; i< limit; i++){
    for (j=i ;j>=0; j--){
      if(input[j] < input[j-1]){
	temp = input[j];
	input[j] = input[j-1];
	input[j-1] = temp;
      }
    }
  }

  return input;
}


int main(){

  int limit, i;
  
  std :: cout <<"Enter limit: ";
  std :: cin>> limit;

  int* input = get_input(limit);
  
  clock_t start = clock();
  
  int* sorted_array = insertion_sort(input, limit);
  
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Insertion Sort took %f seconds to finish \n", cpu_time_used);
  
}
