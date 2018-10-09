#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
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
    void DFS2(std::string start_vertex);
    void graph::BFS(std::string start_vertex);
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

void graph::DFS2(std::string start_vertex) {
  std::unordered_set<std::string> visited;
  std::stack<std::string> vertex_stack;
  vertex_stack.push(start_vertex);
  visited.emplace(start_vertex);
  //To print, print first vertex here
  while (!vertex_stack.empty()) {
    std::string current_vertex = vertex_stack.top();
    vertex_stack.pop();
    for (auto connected_vertex: vertex_table[current_vertex]->edges) {
      if (visited.find(connected_vertex.first) == visited.end()) {
        //And now recursively print all the visited vertex here
        vertex_stack.push(connected_vertex.first);
        visited.emplace(connected_vertex.first);
      }
    }
  }
}

void graph::BFS(std::string start_vertex) {
  std::unordered_set<std::string> vertex_visited;
  std::queue<std::string> vertex_queue;
  vertex_queue.push(start_vertex);
  vertex_visited.emplace(start_vertex);
  //To print, print first vertex here
  while (!vertex_queue.empty()) {
    std::string current_vertex = vertex_queue.back();
    current_vertex.pop_back();
    for (auto connected_vertex: vertex_table[current_vertex]->edges) {
      if (vertex_visited.find(connected_vertex.first) == vertex_visited.end()) {
        //And now recursively print all the visited vertex here
        vertex_queue.push(connected_vertex.first);
        vertex_visited.emplace(connected_vertex.first);
      }
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

/*
The insert, delete and search time of unordered_set is amortized O(1)
since it is implemented on hash table. In the DFS, we can use unordered_set
instead of unordered_map because we don't need to store a key-value pair.
The reason why we need both function:DFS and function:DFSutil is because
the recursion function need to check unordered_set:visited everytime.
Therefore we give DFS an unordered_set so that its helper function can
recursively update it.
Another way is to use stack as DFS2 did. One thing important here is that
we have to pop() the top element before pushing something else.
So the DFS traversal is visiting all the vertexes possibly reached from
previous vertex and choose one of them again and again.
For BFS traversal, simply use queue instead of stack to recursively push
all the reachable vertexes and traverse based on distance from the 
starting vertex.
*/