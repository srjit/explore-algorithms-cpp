#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>


int* random_numbers(int limit){

  srand(time(NULL));
  int random_number;
  unsigned int microseconds = 10000;
  int* input = new int[limit];

  for (int i=0; i< limit; i++){
    usleep(microseconds);
    random_number = std::rand() / 10000000;
    input[i] = random_number;
  }

  return input;
}


int main(){

  int limit = 10;
  int* input = random_numbers(limit);

  for(int j=0;j <limit; j++){
    std::cout<<input[j]<<"\t";
  }

  clock_t startTime = clock();
  clock_t endTime = clock();

  clock_t clockTicksTaken = endTime - startTime;
  double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

  std::cout<<"Time: "<< timeInSeconds;


    
}

