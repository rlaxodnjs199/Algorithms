/*
Problem:
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/
#include <iostream>
#include <vector>
#include <string>
class Solution {
  public:
    int unique_path(int m, int n) {
      if (m == 1 || n == 1) return 1;
      int dp[m][n];
      for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
      }
      for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
      }
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
};
int main() {
  Solution s;
  std::cout << s.unique_path(7, 3);
}