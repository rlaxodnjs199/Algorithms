/*
Problem:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>
int minPathSum(std::vector<std::vector<int>>& grid) {
  if (grid.empty()) return 0;
  int m = grid.size();
  int n = grid[0].size();
  int dp[m][n];
  dp[0][0] = grid[0][0];
  for (int row = 1; row < m; row++) {
      dp[row][0] = dp[row-1][0] + grid[row][0];
  }
  for (int col = 1; col < n; col++) {
      dp[0][col] = dp[0][col-1] + grid[0][col];   
  }
  for (int row = 1; row < m; row++) {
      for (int col = 1; col < n; col++) {
          dp[row][col] = min(dp[row-1][col], dp[row][col-1]) + grid[row][col];
      }
  }
  return dp[m-1][n-1];
}