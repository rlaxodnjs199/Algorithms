/*
Problem:
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
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