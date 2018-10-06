#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
struct vertex {
  std::string start_vertex;
  std::vector<std::pair<std::string, int>> edges;
  vertex(std::string s): start_vertex(s) {}
};

class graph {
  public:
    std::unordered_map<std::string, vertex*> vertex_table;
    void add_vertex(const std::string& start_vertex);
    void add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost);
    void DFS(std::string start_vertex);
    void DFSutil(std::string current_vertex, std::unordered_set<std::string>& visited);
};

void graph::add_vertex(const std::string& start_vertex) {
  auto found_vertex = vertex_table.find(start_vertex);
  if (found_vertex == vertex_table.end()) {
    vertex_table[start_vertex] = new vertex(start_vertex);
    return;
  }
  std::cout << "Vertex already exists" << std::endl;
}

void graph::add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost) {
  auto found_vertex = vertex_table.find(start_vertex);
  if (found_vertex != vertex_table.end()) {
    found_vertex->second->edges.push_back(std::make_pair(end_vertex, cost));
  }
}

void graph::DFS(std::string start_vertex) {
  std::unordered_set<std::string> visited;
  DFSutil(start_vertex, visited);
}

void graph::DFSutil(std::string current_vertex, std::unordered_set<std::string>& visited) {
  visited.emplace(current_vertex);
  for (auto connected_vertex: vertex_table[current_vertex]->edges) {
    if (visited.find(connected_vertex.first) == visited.end()) {
      DFSutil(connected_vertex.first, visited);
    }
  }
}

int main() {
  graph g;
  g.add_vertex("one");
  g.add_vertex("two");
  g.add_vertex("three");
  g.add_vertex("four");
  g.add_vertex("five");
}
