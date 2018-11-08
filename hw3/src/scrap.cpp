int longestCommonSubsequence(string seq1, string seq2){
  
  int m = seq1.length();
  n = seq2.length();
	
  //char b[m+1][n+1];
  vector<vector<char>> direction(m+1, vector<char>(n+1, 0));
  //char c[m+1][n+1];
  vector<vector<char>> magnitude(m+1, vector<char>(n+1, 0));
	
  for(int i = 0; i <= m; i++){
    
    for(int j = 0; j <= n; j++){
	
      if(i == 0 || j == 0) {	//default fill
	magnitude[i][j] = 0;
	direction[i][j] = '/';
      }
	  
      else if(seq1[i] == seq2[j]){
	magnitude[i][j] = magnitude[i-1][j-1] + 1;
	direction[i][j] = '@'; //using @ to represent diagonal(up/left) arrow.
      }
	  
      else if(magnitude[i-1][j] >= magnitude[i][j-1]){
	magnitude[i][j] = magnitude[i-1][j];
	direction[i][j] = '#'; //using # to represent the up arrow.
      }
	  
      else{
	magnitude[i][j] = magnitude[i][j-1];
	direction[i][j] = '!'; //using ! to represent the left arrow.
      }
    }
  }
	
  printLCS(direction, seq1, seq1.length(), seq2.length());
	
  return magnitude[m][n];
}	




int longestCommonSubsequence(string seq1, string seq2){
  
  int m = seq1.length();
  n = seq2.length();
	
  //char b[m+1][n+1];
  vector<vector<char>> b(m+1, vector<char>(n+1, 0));
  //char c[m+1][n+1];
  vector<vector<char>> c(m+1, vector<char>(n+1, 0));
	
  for(int i = 0; i <= m; i++){
    
    for(int j = 0; j <= n; j++){
	
      if(i == 0 || j == 0) {	//default fill
	c[i][j] = 0;
	b[i][j] = '/';
      }
	  
      else if(seq1[i] == seq2[j]){
	c[i][j] = c[i-1][j-1] + 1;
	b[i][j] = '@'; //using @ to represent diagonal(up/left) arrow.
      }
	  
      else if(c[i-1][j] >= c[i][j-1]){
	c[i][j] = c[i-1][j];
	b[i][j] = '#'; //using # to represent the up arrow.
      }
	  
      else{
	c[i][j] = c[i][j-1];
	b[i][j] = '!'; //using ! to represent the left arrow.
      }
    }
  }
	
  printLCS(b, seq1, seq1.length(), seq2.length());
	
  return c[m][n];
}	
