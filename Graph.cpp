#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
struct vertex {
  std::string start_vertex;
  std::vector<std::pair<std::string, int>> edges;
  vertex(std::string s): start_vertex(s) {}
};
class graph {
  public:
    std::unordered_map<std::string, vertex*> vertex_container;
    void add_vertex(const std::string& start_vertex);
    void add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost);
    
    void add_vertex(const std::string& start_vertex) {
      auto it = vertex_container.find(start_vertex);
      if (it == vertex_container.end()) {
        vertex_container[start_vertex] = new vertex(start_vertex);
        return;
      }
      std::cout << "Vertax with name " << start_vertex << " already exists" << std::endl;
    }
    void add_edge(const std::string& start_vertex, const std::string& end_vertex, int cost) {
      auto search_vertexes = vertex_container.find(start_vertex);
      if (search_vertexes != vertex_container.end()) {
        search_vertexes->second->edges.push_back(std::make_pair(end_vertex, cost));
      }
      std::cout << "Add Vertex " << start_vertex << " first!" << std::endl;
    }
};

/*

*/