#include <limits.h>
#include <iostream>
 
using namespace std;
 
struct Edge{
  int source;
  int destination;
  int weight;
};


struct Graph{
  int node_count;
  int edges_count;
  struct Edge* edge;
};


void output_to_console(int distance[], int vertex_count)
{
  std::cout<<"\nNodes \tDistance from Source\n";
  for (int i = 0; i < vertex_count; ++i){
    std::cout<<i<<"\t"<<distance[i]<<"\n";
  }
}


struct Graph* build(int node_count, int edges_count)
{
  
  struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
  graph->node_count = node_count;
  graph->edges_count = edges_count;
 
  graph->edge = (struct Edge*) malloc(graph->edges_count * sizeof(struct Edge));
  return graph;
  
}


void bellman_ford(struct Graph* graph, int source)
{
  
  int node_count = graph->node_count;
  int shortest_path[node_count];
  int edges_count = graph->edges_count;
 
  for (int i=0; i <node_count; i++)
    shortest_path[i] = INT_MAX;
 
  shortest_path[source] = 0;
 
  for (int i=1; i<=node_count-1; i++){
    for (int j=0; j <edges_count; j++){
      int u = graph->edge[j].source;
      int v = graph->edge[j].destination;
      int weight = graph->edge[j].weight;
      if (shortest_path[u] + weight < shortest_path[v])
	shortest_path[v] = shortest_path[u] + weight;
    }
  }
 
  for (int i=0; i <edges_count; i++){
    
    int u = graph->edge[i].source;
    int v = graph->edge[i].destination;
    int weight = graph->edge[i].weight;
    
    if (shortest_path[u] + weight < shortest_path[v]){
      std::cout<<"\n Graph contains negative edge cycle\n";
    }
  }
 
  output_to_console(shortest_path, node_count);
  
}


int main()
{
  
  int vertices,edges,source;
 
  std::cout<<"Enter number of vertices:";
  std::cin>>vertices;
  
  std::cout<<"Enter number of edges:";
  std::cin>>edges;

  std::cout<<"Enter source vertex ID:";
  std::cin>>source;
 
  struct Graph* graph = build(vertices, edges); 
  std::cout<<"\nEnter edge attributes: Source, destination, weight respectively\n";
  
  for(int i=0;i<edges;i++){
    std::cout<<"Edge "<<i<<": ";
    std::cin>>graph->edge[i].source>>graph->edge[i].destination>>graph->edge[i].weight;
  }
 
  bellman_ford(graph, source);
  
}
