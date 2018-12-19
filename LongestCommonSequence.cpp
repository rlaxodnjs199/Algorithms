#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
  int lcs(std::string s1, std::string s2) {
    int result;
    int m = s1.size();
    int n = s2.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i-1] == s2[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else {
          dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
    return dp[m][n];
  }
};
int main() {
  std::string s1 = "AGGTAB";
  std::string s2 = "GXTXAYB";
  Solution s;
  std::cout << s.lcs(s1, s2);
}