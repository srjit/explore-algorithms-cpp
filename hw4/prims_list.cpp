#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/**
 *  Class for the graph of which
 *  Prim's would be a function
 */
class Graph {

  int vertices;

public:

  /**
   *  Adjacency list as a vector of vector for storing paths.
   *  The i'th element in the outside vector represents the path's from vertex i
   *
   *  The vector holds a vector of 'pair' of  values.
   *
   *  Every 'pair' indicates an edge
   *  First elment of the pair: Destination vertex
   *  Second element of the pair: Weight of the edge
   */
  std::vector<std::vector<std::pair<int, int>>> adjacencyList;


  /**
   * Constructor and functions to be defined
   */
  Graph(int vertices);
  
  void create_edge(int u, int v, int weight);
  
  void prims_min_span_tree();

};



Graph::Graph(int vertex_count) {

  this->vertices = vertex_count;

  /**
   * Intializing the adjacency list.
   * We have 'n' elements in the list where n is the number of vertices.
   * At this point we have only vertices and no edges defined.
   */ 
  for(int i=0; i<vertex_count; i++){
    std::vector<std::pair<int, int>> p;
    adjacencyList.push_back(p);
  }

}


void Graph::create_edge(int u, int v, int weight){

  /**
   *  Creating an edge - when we do this we create a connection from
   *  u to v and one from v to u - Hence two pushbacks at two indices in the
   *  adjacency list.
   */
  std::pair<int, int> adjListNode = std::make_pair(v, weight);
  this->adjacencyList[u].push_back(adjListNode);
  this->adjacencyList[v].push_back(adjListNode);

}

void Graph::prims_min_span_tree(){

  /**
   *  Using the Built-in heap from the STL
   *  as a priority queue utility
   */
  priority_queue<pair<int, int>,
		 vector<pair<int, int>>,
		 greater<pair<int, int>>> priorityQueue;
  
  int src = 0;
  /**
   * Initialize the keys for all vertices with a very large value
   * to represent infinity
   */
  vector<int> key(this->vertices, 9999);
  /**
   *  Set all parents to -1 initially
   */
  vector<int> parent(this->vertices, -1);

  /**
   * Track the vertices we've taken in the Minimal Spanning Tree.
   * When ith element is added, we set the i'th element of the
   * vector to True.
   */
  vector<bool> hasAdded(this->vertices, false);

  /**
   * Adding to the priority queue
   */
  priorityQueue.push(make_pair(0, src));
  key[src] = 0;

  while (!priorityQueue.empty())
    {
      int u = priorityQueue.top().second;
      priorityQueue.pop();

      hasAdded[u] = true;  

      /**
       * Vector iterator to iterate through the connected nodes
       */
      vector<pair<int, int>>::iterator i;
      /**
       * Adjacency List (vector) pointing to the u-th vertex
       */
      std::vector<std::pair<int, int>> l = this->adjacencyList[u];
      
      for(int i=0; i<l.size(); i++)
        {
	  pair<int, int> _edge = l[i];

	  /**
	   * Since destination and weight are our first and second elements in
	   * the 'pair'.
	   */
	  int v = std::get<0>(_edge);
	  int weight = std::get<1>(_edge);

	  if (hasAdded[v] == false && key[v] > weight)
            {
	      key[v] = weight;
	      priorityQueue.push(make_pair(key[v], v));
	      parent[v] = u;
            }
        }
    }

  /**
   * Finish - Print the vertices 
   */
  cout << "Source" << "\t" << "Destination"<<"\n";
  for (int i = 1; i < this->vertices; ++i)
    cout << parent[i] << "\t" << i<<"\n";
}


int main(){

  int vertices;
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

  g.prims_min_span_tree();
  
}

