#include <iostream>
#include <vector>
int rmdup(std::vector<int>& nums) {
  if (nums.empty()) return 0;
  int prev_index = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] != nums[prev_index]) {
      nums[++prev_index] = nums[i];
    }
  }
  return prev_index + 1;
}