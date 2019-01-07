#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
      if (matrix.empty()) return 0;
      int m = matrix.size();
      int n = matrix[0].size();
      int dp[m][n] = {0};
      int max_area = 0;
      for (int i = 0; i < m; i++) {
        dp[i][0] = matrix[i][0] - '0';
        max_area = std::max(max_area, dp[i][0]);
      }
      for (int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i] - '0';
      }
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          if (matrix[i][j] == '1') {
            dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            max_area = std::max(max_area, dp[i][j]);
          }
          else dp[i][j] = 0;
        }
      }
      return max_area * max_area;
    }
};
// ctrl+h : replace window ctrl+alt+enter : replace all
int main() {
  std::vector<std::vector<char>> matrix = {
    {'0','0','0','1'},
    {'1','1','0','1'},
    {'1','1','1','1'},
    {'0','1','1','1'},
    {'0','1','1','1'}
  };
  Solution s;
  std::cout << s.maximalSquare(matrix);
}