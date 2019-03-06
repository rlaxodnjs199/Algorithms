#include <iostream>
#include <vector>
#include <algorithm>
int mps(std::vector<int>& nums) {
  if (nums.empty()) return 0;
  int current_max = nums[0];
  int current_min = nums[0];
  int result = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    current_max = std::max(nums[i], std::max(current_max * nums[i], current_min * nums[i]));
    current_min = std::min(nums[i], std::min(current_max * nums[i], current_min * nums[i]));
    result = std::max(result, current_max);
  }
  return result;
}