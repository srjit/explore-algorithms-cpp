#include <iostream>
#include <algorithm>
#include <vector>



struct Group{
  std::vector<int> elements;
  int sum;
};

/**
 * Find the index of an elment in a vector
 */
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

  int splits, data_size;


  /**
   * Collect the inputs from the user
   */
  std::cout << "Enter the number of elements: ";
  std::cin >> data_size;

  int data[data_size];
  std::cout << "\n" << "Enter the array: ";

  for (int idx=0; idx < data_size; idx++)
    std::cin >> data[idx];

  std::cout << "Enter number of arrays to split into:";
  std::cin >> splits;


  /**
   * Construction of the double array C[i][j]
   * and the matrix to which it
   */
  int C[splits][data_size];
  int parent_k[splits][data_size];

  for(int i=0;i<splits;i++){
    for(int j=0;j<data_size;j++){
      C[i][j] = 0;
      parent_k[i][j] = 0;
    }
  }

  /**
   * Constructing the first row of the matrix
   * as the sum of elements in the data array
   * until the current index (including it)
   */
  C[0][0] = data[0];
  for(int k=1; k<data_size; k++){
    C[0][k] = C[0][k-1] + data[k];
  }

  /**
   * Initialize the first column of every row  
   * in the C Matrix to 0
   */
  for(int k=1; k<splits; k++){
    C[k][0] = 0;
  }


  /**
   * Calculation for other elements
   * 
   */
  for(int j=1; j<splits; j++){

    for(int i=j; i<data_size; i++){

      /**
       * Store the min values from every k 
       */
      std::vector<int> max_group;

      std::vector<int> c_group;
      std::vector<int> sum_group;
      
      for(int k=j-1; k<i; k++ ){

	/**
	 * First element in the
	 * min part of the formula
	 */
	int element1 = C[j-1][k];

	/**
	 * Second element in the
	 * min part of the formula
	 */
	int sum_element = 0;
	for(int m=k+1; m<=i; m++)
	  sum_element += data[m];

	/**
	 * Choose the minimal element from the two elements
	 */
	c_group.push_back(element1);
	sum_group.push_back(sum_element);
	
	int min_element = element1 < sum_element ? element1 : sum_element;

	/**
	 * Push back the value into the vector
	 */
	max_group.push_back(min_element);
      }

      /**
       * Maximum element in this iteration
       */
      int max_element = *std::max_element(max_group.begin(), max_group.end());

      /**
       * Find the index of the maximum element and figure out
       * which element contributed to it.
       *
       * if it is c[k;j-1], use k which brought the largest element as value
       * of parent_k[j][i]
       *
       * if it is the sum element, use k-1 as  value for parent_k[j][i]
       */
      int _index = find_index(max_group, max_element);
      int index;
      if(c_group[_index] == max_element){
	index = _index;
      } else {
	index = _index - 1;
      }
      
      
      max_group.clear();
      C[j][i] = max_element;
      parent_k[j][i] = index + j;
      
    }
  }


  std::cout<<"\n C Matrix \n";
  for(int x=0;x<splits;x++){
    for(int y=0;y<data_size;y++){
      std::cout<<C[x][y]<<"\t";
    }
    std::cout<<"\n";
  }

  std::cout<<"\n Parent_k Matrix \n";
  for(int x=0;x<splits;x++){
    for(int y=0;y<data_size;y++){
      std::cout<<parent_k[x][y]<<"\t";
    }
    std::cout<<"\n";
  }


  std::cout<<"\n"<<"Finding the number of elements to be present in each group\n";

  std::vector<int> increments_in_groups;
  increments_in_groups.push_back(data_size);

  int tmp_index = data_size-1;
  for(int k=splits-1; k>0; k--){
    int next_index = parent_k[k][tmp_index];
    increments_in_groups.push_back(next_index);    
    tmp_index = next_index;
  }

  std::reverse(increments_in_groups.begin(),increments_in_groups.end());
  
  std::vector<int> groups;
  groups.push_back(increments_in_groups[0]);
  for(int i=1;i<increments_in_groups.size();i++){
    groups.push_back(increments_in_groups[i] - increments_in_groups[i-1]);
  }

  /**
   *  Number of elements in each group
   */
  for(int i=0;i<groups.size();i++){
    std::cout<<groups[i]<<"\t";
  }
  std::cout<<"\n";

  /**
   * Minimum of the sum of the groups
   */
  std::cout<<"Minimum of the sum of groups: "<<C[splits - 1][data_size - 1]<<"\n";
}
