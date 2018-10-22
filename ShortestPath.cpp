/*
->Finding shortest path in unweighted graph
In unweighted graph, the shortest path means
smallest number of edges needed to reach from
source vertex to destination vertex.
There for BFS, which goes through the vertexes
based on level of number of edges, is the optimized
strategy for finding shortest path. When using DFS,
it is possible that we can find shortest path but we
should need to measure all the possibilities, updating
'smallest num of edges' and return that path.
This is absolutely inefficient.

->Finding shortest path in weighted graph
1. Using BFS for finding shortest path in weighted graph?
We can't do this by using normal BFS since when we visit
a node once, we marked it as visited and doesn't visit again.
To compute shortest path, we need to investigate different paths
to certain node to get an answer.

2. Dijsktra's algorithm
Dijsktra's algorithm is finding shortest path by greedy choice.
Starting from a certain vertex, it updates distance to all
adjacant vertex and push the weight from start vertex to 
priority queue. We select edges in greedy manner like this so that
we are choosing minimum weight path from start vertex at any moment.
When all the vertexes are visited(priority queue is empty)
, loop is terminated. One problem in Dijsktra's algorithm is that
it cannot deal with negative edge because it does not necessarily
several paths to the destination vertex. The path found first is regarded
as the shortest path in Dijsktra's algorithm.

3. Bellman-Ford algorithm
Bellman-Ford algorithm is finding shortest path by recursively update
all the reachable paths
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
typedef std::pair<int, vertex*> vpair;
struct vertex {
  std::string vertex_name;
  std::vector<std::pair<std::string, int>> edges;
  vertex(std::string name): vertex_name(name) {}
};
class Graph {
  public:
    //Why I use vertex* instead of vertex
    //No need to store vertex in two different place
    std::unordered_map<std::string, vertex*> vertex_list;
    int num_vertex;
    void add_vertex(const std::string& name);
    void add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost);
    void Graph::Dijsktra(vertex* source);
};
void Graph::add_vertex(const std::string& name) {
  auto it = vertex_list.find(name);
  if (it == vertex_list.end()) {
    vertex_list[name] = new vertex(name);
  }
}
void Graph::add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost) {
  auto it = vertex_list.find(start_vertex);
  if (it != vertex_list.end()) {
    auto edge_pairs = it->second->edges;
    auto pair = std::make_pair(end_vertex, cost);
    if (std::find(edge_pairs.begin(), edge_pairs.end(), pair) == edge_pairs.end()) {
      edge_pairs.push_back(pair);
    }
  }
}
void Graph::Dijsktra(vertex* source) {
  std::priority_queue<vpair, std::vector<vpair>, std::greater<vpair>> pq;
  std::unordered_map<std::string, int> distance_table;
  pq.push(std::make_pair(0, source));
  distance_table[source->vertex_name] = 0;
  while (!pq.empty()) {
    vertex* v = pq.top().second;
    pq.pop();
    for (auto i = v->edges.begin(); i != v->edges.end(); i++) {
      std::string s = (*i).first;
      int w = (*i).second;
      if (distance_table[s] > distance_table[v->vertex_name] + w) {
        distance_table[s] = distance_table[v->vertex_name] + w;
        pq.push(std::make_pair(distance_table[s], vertex_list[s]));
      }
    }
  }
  std::cout << "Distance from source" << std::endl;
  for (auto i : distance_table) {
    std::cout << i.first << " " << i.second << std::endl;
  }
}