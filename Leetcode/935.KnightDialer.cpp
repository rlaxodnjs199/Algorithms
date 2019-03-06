#include <iostream>
#include <numeric>
#include <vector>
const int MOD = 1000000007;
int knightDialer(int N) {
  std::vector<std::vector<int>> neighbors = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
  std::vector<int> prev(10, 1);
  //--N loops one time less than N--
  while (--N) {
    std::vector<int> cur(10);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < neighbors[i].size(); j++) {
        cur[i] = (cur[i] + prev[neighbors[i][j]]) % MOD;
      }
    }
    prev = cur;
  }
  return std::accumulate(prev.begin(), prev.end(), 0, [&](int a, int b) {return (a + b) % MOD;});
}