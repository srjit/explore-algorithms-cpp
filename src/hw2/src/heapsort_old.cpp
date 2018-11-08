# include <iostream>


int *get_input(int limit){

  int* input = new int[limit];
  int j = 0;
  for(int i=1000; i>1000-limit; i--){
    input[j] = i;
    j+=1;
  }
  return input;
}



void max_heapify(int a[], int i, int n){
  int l,r,largest,loc;
  l=2*i;
  r=(2*i+1);
  if((l<=n)&&a[l]>a[i])
    largest=l;
  else
    largest=i;
  if((r<=n)&&(a[r]>a[largest]))
    largest=r;
  if(largest!=i)
    {
      loc=a[i];
      a[i]=a[largest];
      a[largest]=loc;
      max_heapify(a, largest,n);
    }
}



void build_max_heap(int a[], int n){
  for(int k = n/2; k >= 1; k--){
      max_heapify(a, k, n);
    }
}


void heapsort(int input[], int limit){

  // // build_max_heap(input, limit);
  int i, temp;
  for (i = limit-1; i >= 0; i--)
    {
      temp = input[i];
      input[i] = input[1];
      input[1] = temp;
      max_heapify(input, 1, i - 1);
    }  
  
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
  
  heapsort(input, limit);

  std::cout<<"Output: \n";
  std::cout<<"\n";
  for(int k=0;k<limit;k++){
    std::cout<<input[k]<<"\t";
  }
  std::cout<<"\n";  
  
}
