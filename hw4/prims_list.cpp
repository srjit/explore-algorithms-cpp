#include <bits/stdc++.h> 
#include <iostream>
#include <vector>

using namespace std;

class Graph {

  int vertices;
  
public:

  std::vector<std::vector<std::pair<int, int>>> adjacencyList;

  Graph(int vertices);

  void create_edge(int u, int v, int weight);

  void prims_min_span_tree();
  
};



Graph::Graph(int vertex_count) {

  this->vertices = vertex_count;

  for(int i=0; i<vertex_count; i++){
    std::vector<std::pair<int, int>> p;
    adjacencyList.push_back(p);
  }

}


void Graph::create_edge(int u, int v, int weight){

  std::pair<int, int> adjListNode = std::make_pair(v, weight);
  this->adjacencyList[u].push_back(adjListNode);
  this->adjacencyList[v].push_back(adjListNode);
  
}

void prims_min_span_tree(){
  
}






int main(){

  int vertices = 9;

  Graph  g(vertices);
  g.create_edge(0,1,5);
  g.create_edge(0, 7, 8); 
  g.create_edge(1, 2, 8); 
  g.create_edge(1, 7, 11); 
  g.create_edge(2, 3, 7); 
  g.create_edge(2, 8, 2); 
  g.create_edge(2, 5, 4); 
  g.create_edge(3, 4, 9); 
  g.create_edge(3, 5, 14); 
  g.create_edge(4, 5, 10); 
  g.create_edge(5, 6, 2); 
  g.create_edge(6, 7, 1); 
  g.create_edge(6, 8, 6); 
  g.create_edge(7, 8, 7);   


  // std::vector<std::pair<int, int>> edge = g.adjacencyList[1];
  // std::cout<<edge[0].second;
}




