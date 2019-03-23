#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int networkdelay_bellmanford(std::vector<std::vector<int>>& times, int N, int K) {
  std::vector<int> delay(N, INT_MAX);
  delay[K] = 0;
  while (--N) {
    for (auto& edge : times) {
      int src = edge[0];
      int dst = edge[1];
      int cost = edge[2];
      if (delay[src] != INT_MAX) {
        delay[dst] = std::min(delay[dst], delay[src] + cost);
      }
    }
  }
  int maxdelay = *std::max_element(delay.begin(), delay.end());
  return maxdelay == INT_MAX? -1 : maxdelay;
}

#include <queue>
#include <algorithm>
typedef std::pair<int, int> pii;
int networkdelay2(std::vector<std::vector<int>>& times, int N, int K) {
  std::vector<std::vector<pii>> graph(N + 1);
  for (auto& edge : times) {
    graph[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
  }
  std::vector<int> dist(N + 1, INT_MAX);
  dist[K] = 0;
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  pq.push(std::make_pair(0, K));
  std::vector<int> visited(N + 1, 0);
  while (!pq.empty()) {
    pii cur = pq.top();
    pq.pop();
    int src = cur.second;
    if (!visited[src]) {
      visited[src] = 1;
      for (auto& edges : graph[src]) {
        int dst = edges.first;
        int c = edges.second;
        if (dist[dst] > dist[src] + c) {
          dist[dst] = dist[src] + c;
          pq.push(std::make_pair(dist[dst], dst));
        }
      }
    }
    int result = *std::max_element(dist.begin(), dist.end());
    return result == INT_MAX? -1 : result;
  }
}