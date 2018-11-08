# include <iostream>


int *get_input(int limit){
  int A [] = {20, 18, 5, 7, 16, 10, 9, 3, 12, 14, 0};
  return A;
}



void countingSort(int* input,int n,int RANGE){


    int count[RANGE];

    for(int i=0;i<RANGE;i++){
      count[i] = 0;
     }
    
    int i;
    int out[n];
    
    
    for(i=0;i<n;i++)
        count[input[i]]+=1;


    for(i=1;i<RANGE;i++)
        count[i]+=count[i-1];
    
    
    for(i=n-1;i>=0;i--){
        out[--count[input[i]]]=input[i];
        // --count[input[i]];
    }
    

    for(i=0;i<n;i++)
        // input[i]=out[i];
      std::cout<<out[i];
    
}


int getLargestElement(int* data, int limit){

  int largest = data[0];

  for(int i = 0;i < limit; i++){
       if(data[i] > largest)
           largest = data[i];
    }

   return largest;
}


int main(){

  int limit, i;
  
  std :: cout <<"Enter limit: ";
  std :: cin>> limit;

  int* input = get_input(limit);

  std::cout<<"\nNumbers to be sorted: \n";
  for(int k=0;k<limit;k++){
    std::cout<<input[k]<<"\t";
  }
  std::cout<<"\n";

  int range = getLargestElement(input, limit);

  countingSort(input, limit, range);

  
  // std::cout<<"Output: \n";
  // std::cout<<"\n";
  // for(int k=0;k<limit;k++){
  //   std::cout<<input[k]<<"\t";
  // }
  // std::cout<<"\n";  
  
}



