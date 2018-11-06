#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 
#define vertex_count 5 
  
int minKey(int key[], bool mstSet[]) {

  int min = 9999, min_index; 
  
  for (int v = 0; v < vertex_count; v++) {
    if (mstSet[v] == false && key[v] < min) {
      min = key[v], min_index = v;
    }
  }
  
  return min_index; 
}

  
void print_min_span_tree(int parent[], int n, int graph[vertex_count][vertex_count]) {
  
  printf("Edge Taken \tWeight\n");
  
  for (int i = 1; i < vertex_count; i++) 
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  

void prims_min_span_tree(int graph[vertex_count][vertex_count]) 
{
  /**
   * Parent's and keys
   */
  int parent[vertex_count];  
  int key[vertex_count];
    
  bool priQueue[vertex_count];
  
  int priority_queue[vertex_count];
  for(int i=0; i<vertex_count; i++){
    priority_queue[i] = i;
  }

  /**
   * Initially set all keys to infinity - A large value instead
   */
  for (int i = 0; i < vertex_count; i++) {
    key[i] = 9999;
    priQueue[i] = false;
  }

  /**
   * Setting first node to have a key 0 and
   * no parent
   */
  key[0] = 0;      
  parent[0] = -1; 

  int count=0;
  while(count < vertex_count-1){

    /**
     * Get element in the priority queue with minimum key
     * We are using u - set priQueue to true
     */
    int u = minKey(key, priQueue); 
    priQueue[u] = true;

  
    for (int v = 0; v < vertex_count; v++)

      /**
       * Conditions: (i) graph[u][v] has a non zero value if u and v are adjacent
       * (ii) v has to be present in the priority queue
       * (iii) weight(u,v) has to be smaller than the key[v]
       */
      if (graph[u][v] && priQueue[v] == false && graph[u][v] < key[v]) {
	parent[v] = u, key[v] = graph[u][v];
      }
	
    count++;
  } 
  
  print_min_span_tree(parent, vertex_count, graph); 
} 
  
  

int main() {
  
  int graph[vertex_count][vertex_count] = {{0, 2, 0, 6, 0}, 
		     {2, 0, 3, 8, 5}, 
		     {0, 3, 0, 0, 7}, 
		     {6, 8, 0, 0, 9}, 
		     {0, 5, 7, 9, 0}}; 
  
  prims_min_span_tree(graph); 
  
} 
