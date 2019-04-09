/*
Problem:
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
std::string minwin(std::string s, std::string t) {
  std::vector<int> numofchars(128, 0);
  for (auto& c : t) {
    numofchars[c]++;
  }
  int head = 0;
  int start = 0;
  int end = 0;
  int count = t.size();
  int min_len = INT_MAX;
  for (int i = 0; i < s.size(); i++) {
    if (--numofchars(s[i]) == 0) {
      if (--counter == 0) {
        end = i;
        while (counter == 0) {
          numofchars(s[start])++;
          if (numofchars(s[start]) > 0) counter++;
          start++;
        }
        if (min_len < end - start) {
          min_len = end - start;
          head = start - 1;
        }
      }
    }
  }
  return min_len = INT_MAX? "" : s.substr(head, min_len);
}