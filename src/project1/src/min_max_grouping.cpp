#include <iostream>
#include <algorithm>
#include <vector>



int find_index(std::vector<int> max_group, int max_element){

  int index;
  for(int i=0;i<max_group.size();i++){
    if(max_group[i] == max_element){
      index = i;
      break;
    }
				     
  }

  return index;
}

int main(){

  int M;
  int N = 12;
  int A[] = {3, 9, 7, 8, 2, 6, 5, 10, 1, 7, 6, 5};  
  

  std::cout<<"Enter number of arrays to split into:";
  std::cin>>M;

  

  /**
   * Construction of the double array c[i][j]
   */
  int C[M][N];
  int T[M][N];
  int parent[M][N];
  
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      C[i][j] = 0;
      T[i][j] = 0;
      parent[i][j] = 0;
    }
  }

  /**
   * Constructing the first row of the matrix
   */
  C[0][0] = A[0];
  for(int k=1; k<N; k++){
    C[0][k] = C[0][k-1] + A[k];
  }

  for(int k=1; k<M; k++){
    C[k][0] = 0;
  }


  /**
   * Calculation for other elements
   * 
   */
  for(int j=1; j<M; j++){
    for(int i=j; i<N; i++){

      std::vector<int> max_group;
      std::vector<int> k_indices;
      // what is the variation of k?

      for(int k=j-1; k<i; k++ ){
	
	int element1 = C[j-1][k];
	int sum_element = 0;
	for(int m=k+1; m<=i; m++){
	  sum_element += A[m];
	}

	int min_element = element1 < sum_element ? element1 : sum_element;
	max_group.push_back(min_element);
	k_indices.push_back(k);
	
      }

      //find the maxminum element
      int max_element = *std::max_element(max_group.begin(), max_group.end());
      int index = find_index(max_group, max_element);
      

      // std::vector<int>::iterator it = std::find(max_group.begin(), max_group.end(), max_element);
      std::cout<<"Index of k is: "<<index + 1<<"\n";
      
      
      max_group.clear();
      k_indices.clear();

      
      C[j][i] = max_element;
      /*
	This is a weird hack. I have no idea why this works. Fuck me
      */
      T[j][i] = index + j;
    }
  }
  
  std::cout<<"\n C Matrix \n";
  for(int x=0;x<3;x++){
    for(int y=0;y<12;y++){
      std::cout<<C[x][y]<<"\t";
    }
    std::cout<<"\n";
  }

  std::cout<<"\n T Matrix \n";
  for(int x=0;x<3;x++){
    for(int y=0;y<12;y++){
      std::cout<<T[x][y]<<"\t";
    }
    std::cout<<"\n";
  }

  /**
   *
   *
   **/
  
}
