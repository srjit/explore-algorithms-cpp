#include<iostream> 


using namespace std; 

int get_greatest_element(int data[], int limit) {
  
	int greatest = data[0]; 
	for (int i = 1; i < limit; i++) 
		if (data[i] > greatest) 
			greatest = data[i];
	return greatest; 
} 



void countingSort(int data[], int limit, int exp){
  
	int output[limit]; 
	int i, count[10] = {0}; 

	for (i = 0; i < limit; i++) 
		count[(data[i]/exp)%10 ]++; 

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = limit - 1; i >= 0; i--) 
	{ 
		output[count[ (data[i]/exp)%10 ] - 1] = data[i]; 
		count[ (data[i]/exp)%10 ]--; 
	} 

	for (i = 0; i < limit; i++) 
		data[i] = output[i];
	
} 

void radixsort(int data[], int limit){ 

  int greatest_element = get_greatest_element(data, limit); 

  for (int base = 1; greatest_element/base > 0; base *= 10) {
    countingSort(data, limit, base);     
  }

} 


int main() {

     int input[] = {329, 457, 657, 839, 436, 720, 353};  
     int limit = sizeof(input)/sizeof(input[0]);
     
     radixsort(input, limit); 
  
    for(int i=0;i<limit;i++)
      std::cout<<input[i]<<"\t";
     
     return 0; 
} 
