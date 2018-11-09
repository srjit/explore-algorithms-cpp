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

void Graph::prims_min_span_tree(){

  priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> priorityQueue;
  int src = 0;
  vector<int> key(this->vertices, 9999);

  vector<int> parent(this->vertices, -1);

  vector<bool> inMST(this->vertices, false);



  priorityQueue.push(make_pair(0, src));
  key[src] = 0;

  while (!priorityQueue.empty())
    {
      int u = priorityQueue.top().second;
      priorityQueue.pop();

      inMST[u] = true;  

      list< pair<int, int> >::iterator i;
      std::vector<std::pair<int, int>> l = this->adjacencyList[u];
      for(int i=0; i<l.size(); i++)
        {
	  pair<int, int> _edge = l[i];

	  int v = std::get<0>(_edge);
	  int weight = std::get<1>(_edge);

	  if (inMST[v] == false && key[v] > weight)
            {
	      // Updating key of v
	      key[v] = weight;
	      priorityQueue.push(make_pair(key[v], v));
	      parent[v] = u;
            }
        }
    }

  // Print edges of MST using parent array
  for (int i = 1; i < this->vertices; ++i)
    printf("%d - %d\n", parent[i], i);

}






int main(){


  int vertices = 9;
  int edge_count;
  std::cout<<"Enter the number of vertices: ";
  std::cin>>vertices;
  std::cout<<"Enter the number of edges: ";
  std::cin>>edge_count;

  Graph  g(vertices);
  int a[3];
  for(int i=0; i<edge_count; i++){
    std::cout<<"Enter edge "<<i<<" in the format <source destination weight>: ";
    for(int j=0; j<3; j++){
      std::cin>>a[j];
    }
    g.create_edge(a[0],a[1],a[2]);
  }


  // g.create_edge(0,1,5 );
  // g.create_edge(0, 7, 8);
  // g.create_edge(1, 2, 8);
  // g.create_edge(1, 7, 11);
  // g.create_edge(2, 3, 7);
  // g.create_edge(2, 8, 2);
  // g.create_edge(2, 5, 4);
  // g.create_edge(3, 4, 9);
  // g.create_edge(3, 5, 14);
  // g.create_edge(4, 5, 10);
  // g.create_edge(5, 6, 2);
  // g.create_edge(6, 7, 1);
  // g.create_edge(6, 8, 6);
  // g.create_edge(7, 8, 7);


  g.prims_min_span_tree();
  // std::vector<std::pair<int, int>> edge = g.adjacencyList[1];
  // std::cout<<edge[0].second;
}
