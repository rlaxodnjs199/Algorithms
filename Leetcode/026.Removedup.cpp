/*
Idea:
We keep most recent element without duplicate
in index prev_index. Whenever we meet new element not equal to nums[prev_index], we store that element in  nums[prev_index+1] and increment prev_index by 1.
*/
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