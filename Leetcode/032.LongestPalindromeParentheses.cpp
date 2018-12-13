/*
Return length of Longest Palindrome Parentheses
1. Idea
Use stack to store s[index] in order.
Pop stack only when pop is eligible.
Push everything except the case when we pop.
Update max length when we pop.
Max length at the moment we pop is from ("previous" top + 1) to current index.
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int longestpp1(std::string s) {
      std::stack<int> stk;
      int max_len = 0;
      int start = 0;
      for (int i = 0; i < s.size(); i++) {
        if (!stk.empty() && s[i] == ')' && s[stk.top()] == '(') {
          stk.pop();
          max_len = std::max(max_len, i - stk.top());
        }
        else {
          stk.push(i);
        }
      }
      return max_len;
    }
    int longestpp2(std::string s) {
      int n = s.size();
      int max_len = 0;
      std::vector<int> dp(n, 0);
      for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
          if (s[i-1] == '(') {
            dp[i] = i >= 2? dp[i-2] + 2 : 2;
          }
          else {
            if (s[i-dp[i-1]-1] == '(') {
              dp[i] = (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0) + dp[i-1] + 2;
            }
          }
          max_len = std::max(max_len, dp[i]);
        }
      }
      return max_len;
    }
};
int main() {
  std::string s = ")()())";
  Solution sol;
  std::cout << sol.longestpp2(s);
}