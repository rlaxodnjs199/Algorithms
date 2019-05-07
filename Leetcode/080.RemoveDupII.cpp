/*
Problem:
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <iostream>
#include <vector>
int removeDuplicates(std::vector<int>& nums) {
  if (nums.empty()) return 0;
  int prev = nums[0];
  int slot = 1;
  int count = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == prev) {
      count++;
      if (count > 2) {
        continue;
      }
    }
    else {
      count = 1;
      prev = nums[i];
    }
    nums[slot] = nums[i];
    slot++;
  }
  return slot;
}