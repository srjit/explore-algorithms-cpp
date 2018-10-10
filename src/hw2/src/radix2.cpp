#include <iostream>
#include <iostream>
#include <queue>
#include <array>

using namespace std;


void length(int[] arr){
  int size = sizeof(arr)/sizeof(arr[0]);  
  std::cout<<size;
}

// void radixSort(int *input, int limit)
// {
// 	int digits = 10;

// 	int queue[limit];	
	
// 	for(int i = 0, factor = 1; i < digits; factor *= limit, i++){
	  
// 	  for(int j = 0; j < limit; j++){
// 	    queue[((input[j]/factor)%limit)] = input[j];
// 	  }
		     

// 		int k = 0;
// 		for(int j = 0; j < limit; j++)
// 		{
// 			while(!queue[j].empty())
// 			{
// 				input[k] = queues[j].front();
// 				queues[j].pop();
// 				k++;
// 			}
// 		}
// 	}
// }




int main()
{

	int input[] = {329, 457, 657, 839, 436, 720, 353};
	int limit = 7;

	length(input);
	
	// cout << "Input: ";
	// for(int i = 0; i < limit; i++)
	// 	cout << input[i] << " ";

	// // radixSort(input, limit);
	
	// cout << "\nOutput: ";
	// for(int i = 0; i < limit; i++)
	// 	cout << input[i] << " ";
	
	// cout << endl;
}

