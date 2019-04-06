#include <iostream>
#include <vector>
#include <algorithm>
int maxsubarray(std::vector<int>& nums) {
  int maxsum = nums[0];
  int cursum = 0;
  for (int i = 0; i < nums.size(); i++) {
    cursum += nums[i];
    maxsum = std::max(maxsum, cursum);
    if (cursum < 0) cursum = 0;
  }
  return maxsum;
}