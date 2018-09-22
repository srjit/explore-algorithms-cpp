#include <iostream>

void insertion_sort(int input[], int limit){


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


  for(i = 0; i< limit; i++){
    std :: cout << input[i];
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

  //  std :: cout << "*****\n";
  insertion_sort(input, limit);
  
  // int *sorted_array = insertion_sort(input, limit);

  // for(i = 0; i< limit; i++){
  //   std :: cout << sorted_array[i];
  // }
  
}
