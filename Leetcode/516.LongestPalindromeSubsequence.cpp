/*
Problem:
Given a string, return longest palindrome subsequence.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int LPS(std::string s) {
  std::vector<int> dp_prev(s.size());
  std::vector<int> dp_cur(s.size(), 0);
  for (int start = s.size() - 1; start >= 0; start--) {
    for (int end = start; end < s.size() - 1; end++) {
      if (start == end) {
        dp_cur[end] = 1;
      }
      else {
        if (s[start] == s[end]) {
          dp_cur[end] = dp_prev[end-1] + 2;
        }
        else {
          dp_cur[end] = std::max(dp_prev[end], dp_cur[end-1]);
        }
      }
    }
    dp_prev = dp_cur;
  }
  return dp_cur[s.size() - 1];
}