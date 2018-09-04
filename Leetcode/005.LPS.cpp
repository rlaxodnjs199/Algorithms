#include <iostream>
#include <algorithm>
class Solution {
  public:
    std::string LPS(std::string s) {
      if (s.empty()) return s;
      int maxlen = 1;
      int start = 0;
      for (int i = 0; i < s.size()-1; i++) {
        if ((s.size()-i) <= maxlen/2) break;
        int j = 1, k = 1;
        while ((i+j) < s.size() && s[i] == s[i+j]) {
          j++;
        }
        while ((i-k) >= 0 && (i+k+j-1) < s.size() && s[i-k] == s[i+k+j-1]) {
          k++;
        }
        int tempmax = (i+k+j-2)-(i-k+1)+1;
        if (tempmax >= maxlen) {
          start = i-k+1;
          maxlen = tempmax;
        } 
      }
      return s.substr(start, maxlen);
    }
};
int main() {
  Solution s;
  std::string str = "abcdcbakkukkabcdcba";
  std::cout << s.LPS(str) << std::endl;
}
/*
1. Idea
Palindromic String: When we flip a string based on median index character,
both left side and right side have to be identical. We need to do at least
one-pass measurement because we can't skip measuring certain index.
Now, can we use dynamic programming here?
I don't think so because there is no guarantee that we can use suboptimal solutions
to build optimal solution. For example, in "abcdcbakkukkabcdcba", suboptimal solution
might be "abcba" with median character "c". However, the optimal solution is the entire
string, which has median character of "u". We cannot guarantee a solution is optimal before
we measuring each index as a median pivot of the palindromic string.
Oh, one thing I notice is that if the remaining length of the string is less than the palindromic
substring we found, than we can simply end the function.

2. First time, I was wrong because when I devide the cases by s[i]==s[i+1] and the rest,
I can't manage where there are more than 3 continuosly repeating characters.
Therefore, what I want to do is first go to the two edges for the substring with
repeating characters, and then measure if s[i-something] == s[i+something].
*/