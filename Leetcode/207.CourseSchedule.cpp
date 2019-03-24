/*
Problem:
There are a total of n courses you should take,
labeled from 0 to n-1. Some have prerequisites,
when course 0 has course 1 as a prerequisite, it is
expressed as [0, 1]. Determine if you can finish all the courses.
*/
#include <iostream>
#include <vector>
bool canFinish_dfs(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  for (auto& edge : prerequisites) {
    graph[edge.second].push_back(edge.first);
  }
  std::vector<bool> visited(numCourses, false);
  std::vector<bool> dfspath(numCourses, false);
  for (int i = 0; i < numCourses; i++) {
    if (!visited[i] && !acyclic(graph, visited, dfspath, i)) {
      return false;
    }
  }
  return true;
}
bool acyclic(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<bool>& dfspath, int course) {
  if (visited[course]) return true;
  if (dfspath[course]) return false;
  visited[course] = dfspath[course] = true;
  for (int neighbor : graph[course]) {
    if (!acyclic(graph, visited, dfspath, neighbor)) return false;
  }
  dfspath[course] = false;
  return true;
}
