#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
std::vector<int> findorder_dfs(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  for (auto& edge : prerequisites) {
    graph[edge.second].push_back(edge.first);
  }
  std::vector<bool> visited(numCourses, false);
  std::vector<bool> detectcycle(numCourses, false);
  std::vector<int> order;
  for (int i = 0; i < numCourses; i++) {
    if (!visited[i]) {
      if (!isacyclic(graph, visited, detectcycle, order, i)) {
        return {};
      }
    }
  }
  std::reverse(order.begin(), order.end());
  return order;
}
bool isacyclic(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<bool>& detectcycle, std::vector<int>& order, int course) {
  if (detectcycle[course]) return false;
  if (visited[course]) return true;
  detectcycle[course] = visited[course] = true;
  for (auto& neighbor : graph[course]) {
    if (!isacyclic(graph, visited, detectcycle, order, neighbor)) return false;
  }
  order.push_back(course);
  detectcycle[course] = false;
  return true;
}