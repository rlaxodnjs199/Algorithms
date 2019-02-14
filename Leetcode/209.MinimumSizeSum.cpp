/*
Problem:
Given an array of n positive integers and a positive
integer s, find the minimal length of a contiguous
subarray of which the sum >= s. If there isn't one, 
return 0.

Idea:
As a brute-force algorithm, we can check every pair 
of subarray[i...j] and compare lengths of them.
To do this more efficiently, I used two pointer 
technique, aka sliding window. I increment end index 
by 1 every loop and then whenever I found current sum 
>= target, I optimized the window by moving start 
index to the right as much as possible.

What I learned:
The min_len has to be declared as INT_MAX, since this 
is a problem to find minimum value.
When min_len is still INT_MAX before we return the 
result, that means there was no desirable update for 
min_len inside of the loop, and we can simply return 0.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int MinimumSizeSumSubarray(std::vector<int>& nums, int target) {
  int min_len = INT_MAX;
  int cur_sum = 0;
  for (int start = 0, end = 0; end < nums.size(); end++) {
    cur_sum += nums[end];
    if (cur_sum >= target) {
      while (cur_sum - nums[start] >= target) {
        cur_sum -= nums[start++];
      }
      min_len = std::min(min_len, end - start + 1);
    }
  }
  return min_len == INT_MAX? 0 : min_len;
}