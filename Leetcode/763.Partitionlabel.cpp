/*
Problem:
A string s of lowercase letters is given.
Partition this string to as many part as possible
that each letter appears in at most one part, and
return a list of lengths of these parts.

Idea:

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<int> partitionlabels(std::string s) {
  std::vector<int> result;
  std::vector<int> last_index(26, 0);
  for (int i = 0; i < s.size(); i++) {
    last_index[s[i]-'a'] = i;
  }
  for (int i = 0, iStart = 0, iEnd = -1; i < s.size(); i++) {
    iEnd = std::max(iEnd, last_index[s[i] - 'a']);
    if (i == iEnd) {
      result.push_back(i - iStart + 1);
      iStart = i + 1;
    }
  }
}