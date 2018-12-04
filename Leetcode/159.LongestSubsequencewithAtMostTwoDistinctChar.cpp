/*
1. Idea
To find the longest subsequence with at most two distinct character,
I can do window sliding technique with using hashmap.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
class Solution {
  int LS(std::string s) {
    int n = s.size();
    if (n < 3) return n;
    int maxlength = 0;
    int start = 0;
    int count = 0;
    std::unordered_map<char, int> hashmap;
    for (int i = 0; i < n; i++) {
      if (hashmap.find(s[i]) != hashmap.end() && hashmap[s[i]] != 0) {
        hashmap[s[i]]++;
      }
      else {
        while (count == 2) {
          if (--hashmap[s[start++]] == 0) count--;
        }
        count++;
        hashmap[s[i]] = 1;
      }
      maxlength = std::max(maxlength, i-start+1);
    }
    return maxlength;
  }
  int LS2(std::string s, int k) {
    int start = 0, end = 0, maxlength = 0, count = 0;
    std::vector<int> map(128, 0);
    while (end < s.size()) {
      if (map[s[end]]++ == 0) count++;
      while (count > k) {
        if (--map[s[start++]] == 0) count--; 
      }
      maxlength = std::max(maxlength, end-start+1);
      end++;
    }
    return maxlength;
  }
};