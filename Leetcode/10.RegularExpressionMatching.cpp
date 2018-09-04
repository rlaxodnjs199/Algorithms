#include <iostream>
#include <string>
#include <vector>
class Solution {
  public:
    bool isMatch(std::string s, std::string p) {
      if (p.empty()) return s.empty();
      int m = s.size();
      int n = p.size();
      std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));
      dp[0][0] = true;
      // Considering cases when pattern is such as 'a*b*c*'
      for (int j = 1; j <= n; j++) {
        if (p[j-1] == '*' && j > 1) {
          dp[0][j] = dp[0][j-2];
        }
      }
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (p[j-1] != '*') {
            dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
          }
          else {
            /* if preceding character appears 0 time:
               dp[i][j-2]
               if preceding character appears more than 1 time: 
               dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.') */
            dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
          }
        }
      }
      return dp[m][n];
    }
};

int main() {
  Solution ans;
  std::string s = "aa";
  std::string p = "a*";
  if (ans.isMatch(s, p)) {
    std::cout << "Matching success!" << std::endl;
  }
  else {
    std::cout << "Matching failure!" << std::endl;
  }
}

/*
1. When s has length m and p has length n, why dp array needs size
(m+1) * (n+1)?
Because the array needs to store results when either m or n is empty.
Since they need one more line * column to store the result, the size
has to be (m+1) * (n+1).

2. How could we initialize dp[0][j] and dp[i][0] ?
First, dp[0][0] is true always since empty pattern matches empty string.
Other than that, dp[i][0] is always false 
since empty pattern cannot match nonempty string.
do[0][j] depends on the pattern.
It is true only when current p[j-1] is '*'
(To ensure preceding character occurs 0 time) and dp[0][j-2] = true.

3. Main logic?
if p[j-1] = *
preceing character occurs 0 or more
else
s[i-1] should match p[j-1] or p[j-1] = '.'
*/