/*
Problem:
Given a string, find the length of the longest substring
without repeating characters.

Idea:
Sliding window technique.
When we detect duplicate within range of [start ~ i],
we update start to be duplicate character last occurance
index + 1. Important thing here is that we should not
care duplicate 'before start' because it was already
excluded.

Things I leared:
For ASCII char, they have integer values from 0 ~ 255.
Therefore vector<int> hashmap(256, -1) can be used as a
map to store integer data corresponding to all individual
ASCII chars.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
      std::vector<int> hashmap(256, -1);
      int max_len = 0;
      for (int start = 0, end = 0; end < s.size(); end++) {
        if (hashmap[s[end]] >= start) {
          start = hashmap[s[end]] + 1;
        }
        hashmap[s[end]] = end;
        max_len = std::max(max_len, end - start + 1);
      }
      return max_len;
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
Even though addition, deletion and find function of hashtable is O(1), 
it becomes worse when the number of entries is large enough that the hashtable needs to resize itself multiple times.
Therefore, since we can limit the size of entries, using array is a better idea.

3. We initialize array as a size of "256" because it is a maximum ASCII number and we can react to all valid inputs. 
The way to initialize array with size 256 and give every index a value of "-1" is vector<int> array(256, -1); 
We need to initialize all the entries by "-1" so that we can easily check its previous appearance.

4. We don't need to declare "endindex" variable because "i" already has a role of indicating endindex of the current substring.

5.********** [array[s[i]] >= start] because "start" should move only one direction toward end of the string. 
The reason is, even though a repeating happens for cetain character, it could possibly be overlapped by previous repeating characters. 
Therefore, we only need to consider "repeating character with biggest previous index".
*/
