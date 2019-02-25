/*
Problem:
Given a string s, find the longest palindrome substring in s.

Idea:
When we traverse the input string, we pick index i as a center
of a palindrome substring and expand the substring as much as
possible. This takes O(n^2) runtime complexity and O(1) space.
We can also do dp solution for this problem but the complexity
is same while space complexity goes up to O(n^2). Therefore
expanding both end of the string starts from each index is more
efficient algorithm.

What I learned:
First time, I made mistake setting constraint for tStart and tEnd.
tStart should be greater than 0 and tEnd should be less than
s.size()-1 since we expand them by 1 and they should meet 
string size constraint after update.
*/
#include <iostream>
#include <algorithm>
class Solution {
  public:
    std::string LPS(std::string s) {
      if (s.empty() || s.size() == 1) return s;
      int start = 0;
      int max_len = 1;
      for (int i = 0; i < s.size(); i++) {
        if (s.size() - i < max_len/2) break;
        int tStart = i;
        while (i < s.size()-1 && s[i] == s[i+1]) i++;
        int tEnd = i;
        while (tStart > 0 && tEnd < s.size()-1 && s[tStart-1] == s[tEnd+1]) {
          tStart--;
          tEnd++;
        }
        if (max_len <= tEnd - tStart + 1) {
          start = tStart;
          max_len = tEnd - tStart + 1;
        }
      }
      return s.substr(start, max_len);
    }
};
int main() {
  Solution s;
  std::string str = "abcdcbakkukkabcdcba";
  std::cout << s.LPS(str) << std::endl;
}