#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int networkdelay(std::vector<std::vector<int>>& times, int N, int K) {
  std::vector<int> delay(N, INT_MAX);
  delay[K-1] = 0;
  while (--N) {
    for (auto& edge : times) {
      if (delay[edge[0]-1] != INT_MAX) {
        delay[edge[1]-1] = std::min(delay[edge[1]-1], delay[edge[0]] + edge[2]);
      }
    }
  }
  int maxdelay = 0;
  for (int& d : delay) {
    maxdelay = std::max(maxdelay, d);
  }
  return maxdelay == INT_MAX? -1 : maxdelay;
}