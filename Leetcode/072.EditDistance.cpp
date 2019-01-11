/*
Convert string s1 to s2 using addition, deletion, and replacement operations
Return minimum number of operations needed
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Solution {
  public:
    int editDistance(std::string& s1, std::string& s2) {
      int m = s1.size();
      int n = s2.size();
      std::vector<std::vector<int>> dp(m+1, std::vector(n+1, 0));
      //int dp[m+1][n+1];
      for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
      }
      for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
      }
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          dp[i][j] = std::min(dp[i-1][j]+1, std::min(dp[i-1][j-1]+1, dp[i-1][j]+1)); 
        }
      }
      return dp[m][n];
    }
};