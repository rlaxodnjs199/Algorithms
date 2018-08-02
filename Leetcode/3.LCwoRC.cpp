#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
      std::vector<int> array(256, -1);
      int start = 0;
      int maxlen = 1;
      for (int i = 0; i < s.size(); i++) {
        if (array[s[i]] >= start) {
          start = array[s[i]] + 1;
        }
        array[s[i]] = i;
        maxlen = std::max(maxlen, i - start + 1);
        std::cout << start << "  " << maxlen << std::endl;
      }
      return maxlen;
    }
};
int main() {
  Solution ans;
  std::string s = "abcaaaaaaaaaaabcdaa";
  std::cout << ans.lengthOfLongestSubstring(s) << std::endl;
}

/*
1. Substring vs subsequence
In "pwwkew", longest substring is "wke" while longest subsequence is "pwke"

2. We need to measure all the characters at least once whether it appeared before or not.
This requires some types of storage to check previous appearance.
Array vs Hashtable
Both of them work here but I think array is more efficient here in terms of speed.
Since string is composed of finite number of characters, we can declare fixed size array.
Even though addition, deletion and find function of hashtable is O(1), it becomes worse when the number of entries is large enough that the hashtable needs to resize itself multiple times.
Therefore, since we can limit the size of entries, using array is a better idea.

3. We initialize array as a size of "256" because it is a maximum ASCII number and we can react to all valid inputs. The way to initialize array with size 256 and give every index a value of "-1" is vector<int> array(256, -1); We need to initialize all the entries by "-1" so that we can easily check its previous appearance.

4. We don't need to declare "endindex" variable because "i" already has a role of indicating endindex of the current substring.

**********5. [array[s[i]] >= start] because "start" should move only one direction toward end of the string. The reason is, even though a repeating happens for cetain character, it could possibly be overlapped by previous repeating characters. Therefore, we only need to consider "repeating character with biggest previous index".
*/