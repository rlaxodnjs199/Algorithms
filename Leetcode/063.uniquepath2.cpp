/*
1. Idea
If we can modify grid, then we don't need to intialize extra dp table.
If we can't we need to initialize extra dp table with same size as grid.
dp[i][j] = num of ways to reach grid[i][j]
dp[i][j] = 0 if grid[i][j] is an obstacle
otherwise it is a sum of dp[i-1][j] + dp[i][j-1].
*/
#include <iostream>
#include <vector>
class Solution {
public:
  int uniquepathwithobstacles(std::vector<std::vector<int>> &grid) {
    if (grid.empty() || grid[0][0]) return 0;
    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) {
      if (dp[i-1][0] != 0 && grid[i][0] == 0) dp[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (dp[0][i-1] != 0 && grid[0][i] == 0) dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << dp[i][j] << " ";
      }
      std::cout << std::endl;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (grid[i][j] != 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
    return dp[m-1][n-1];
  }
};
int main() {
  std::vector<std::vector<int>> grid = {{0, 1, 0, 0, 0}, 
                                        {1, 0, 0, 0, 0}, 
                                        {0, 0, 0, 0, 0}, 
                                        {0, 0, 0, 0, 0}};
  Solution s;
  std::cout << s.uniquepathwithobstacles(grid);
}