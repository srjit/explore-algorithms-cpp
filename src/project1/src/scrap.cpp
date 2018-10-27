  for(int j=2; j<M+1; j++){
    for(int i=2; i<N+1; i++){

      int begin = j-1;
      int end = i;

      int max_group[end - begin]; 

      for (int k=begin; k < end; k++){

	std::cout<<"C_"<<k<<"_"<<j-1<<"\n";

	int element1 = C[k-1][j-1-1];
	int element2 = 0;

	for (int m=k+1; m<=i; m++){
	  element2 += A[m-1];
	}

	std::cout<<"Sums :"<<element2<<"\n";

	max_group[k-1] = element1 < element2 ? element1 : element2;

	//	std::cout<<"Min :"<<max_group[k-1]<<"\n";	

      }

      C[j-1][i-1] = *std::max_element(max_group, max_group + (end-begin));
      std::cout<<"Element C"<<j<<"_"<<i<<"\t"<<C[j-1][i-1]<<"\n";
    }
    
    
    
  }
