#include <vector>


struct MinSumOpt {
  
};



  for(int j=1; j<splits; j++){
    for(int i=j; i<data_size; i++){

      std::vector<int> max_group;
      // std::vector<int> k_indices;
      // what is the variation of k?

      for(int k=j-1; k<i; k++ ){
	
	int element1 = C[j-1][k];
	int sum_element = 0;
	for(int m=k+1; m<=i; m++){
	  sum_element += data[m];
	}

	int min_element = element1 < sum_element ? element1 : sum_element;
	max_group.push_back(min_element);
	// k_indices.push_back(k);
	
      }

      //find the maxminum element
      int max_element = *std::max_element(max_group.begin(), max_group.end());
      int index = find_index(max_group, max_element);
      
      max_group.clear();
      // k_indices.clear();

      
      C[j][i] = max_element;
      /*
	parent_khis is a weird hack. I have no idea why this works. Fuck me
      */
      parent_k[j][i] = index + j;
    }
  }
