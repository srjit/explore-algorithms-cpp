# include <iostream>
# include <cstdlib>
#include <algorithm>


using namespace std; 


















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
  

  
}
