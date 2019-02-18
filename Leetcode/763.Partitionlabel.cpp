/*
Problem:
A string s of lowercase letters is given.
Partition this string to as many part as possible
that each letter appears in at most one part, and
return a list of lengths of these parts.

Idea:
This is like a sliding window technique.
We first investigate the input string once and 
store last appearance index of each character in 
vector(or map). Next, we iterate through the loop 
again, and update end_index everytime, which refers
to last appearance index of all the character shown
before. When i reaches end_index, characters in
[start_index ~ end_index] don't appear after end_index.

What I learned:
There was two choices to store end_index for each
character. One was using unordered_map and the 
other was using vector. Accessing elements in 
vector is more cache friendly and easy then map.
vector of size 26 is enough to store information of
char 'a' to 'z'.
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