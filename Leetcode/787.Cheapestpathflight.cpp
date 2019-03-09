#include <iostream>
#include <vector>
#include <algorithm>
int findCheapestPath(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
  std::vector<int> dis(n, 100001);
  //Make sure we start from src by initialization
  dis[src] = 0;
  //at most K stops -> at most K+1 edges -> K+1 iterations in Bellman-Ford
  while (K+1) {
    std::vector<int> cur(dis);
    for (auto& path : flights) {
      cur[path[1]] = std::min(cur[path[1]], dis[path[0]] + path[2]);
    }
    dis = cur;
    K--;
  }
  return dis[dst] == 100001? -1 : dis[dst];
}