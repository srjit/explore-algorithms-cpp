#include <iostream>


int findMax(int* data, int limit){

  int max = data[0];
  for(int i=0; i<limit; i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  return max;
  
}


void sort(int* data, int limit){

  int largest = findMax(data, limit);

  /*
    Loop 1: Create an array with limit - the largest element
  */
  int _counts[largest+1] = {0};

  /*
    Loop 2
   */
  for(int i=0; i<limit; i++){
    _counts[data[i]]+=1;
  }

  /*
    Loop 3
   */
  for(int i=2; i<=largest; i++){
    _counts[i] += _counts[i-1];
  }


  int B[limit] = {0};
  for(int j=limit-1; j>=0; j--){
    B[_counts[data[j]]] = data[j];
    _counts[data[j]] = data[j] - 1;
  }


  std::cout<<"\nSorted Array:";
  for(int i=0; i<limit; i++){
    std::cout<<B[i] << "\t";
  }

  std::cout<<"\n";
}



int main( int argc, char* argv[] )
{

    int A [] = {20, 18, 5, 7, 16, 10, 9, 3, 12, 14, 0};
    int limit = 11;

    std::cout<<"Input Array: ";
    for( int i = 0; i < limit; i++ ){
      std::cout<<A[i] << "\t";
    }      


    sort(A, limit);
    
    return 0;
    
}
