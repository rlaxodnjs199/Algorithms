/*
Topological Sort for Directed Acyclic Graph(DAG)
When there is a edge uv from u to v, u always comes
before v in the ordering. Only works for DAG.
u <- v <- w : w v u
The reason why it only works for DAG is because in a
cyclic graph, we can't find an end point of the correlation
so end up with traveling endless loop.
We can use both queue and stack to implement tolopogical sort.
Topological sort can be used to build system, linker implementation,
task management, and so on.
*/

#include <iostream>
#include <stack>
#include <list>
#include <array>
template<typename T> void print_stack(T& stk) {
  std::cout << "[ ";
  while (!stk.empty()) {
    std::cout << stk.top() << " ";
    stk.pop();
  }
  std::cout << "]" << endl;
}
class Graph {
  public:
    int num_vertex;
    std::list<int>* adj;
    Graph(int num);
    void addEdge(int start_vertex, int end_vertex);
    void topologicalSort();
    void topologicalSortutil(int vertex, bool visited[], std::stack<int>& stk);
};
Graph::Graph(int num) {
  num_vertex = num;
  adj = new std::list<int>;
}
void Graph::addEdge(int start_vertex, int end_vertex) {
  adj[start_vertex].push_back(end_vertex);
}
void Graph::topologicalSort() {
  bool visited[num_vertex];
  std::stack<int> stk;
  for (int i = 0; i < num_vertex; i++) {
    if (!visited[i]) {
      topologicalSortutil(i, visited, stk);
    }
  }
}
void Graph::topologicalSortutil(int vertex, bool visited[], std::stack<int>& stk) {
  visited[vertex] = true;
  for (auto i = adj[vertex].begin(); i != adj[vertex].end(); i++) {
    if (!visited[*i]) {
      topologicalSortutil(*i, visited, stk);
    }
  }
  stk.push(vertex);
}