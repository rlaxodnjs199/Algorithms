/*
Problem:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/
#include <iostream>
#include <algorithm>
bool canJump(vector<int>& nums) {
  int n = nums.size();
  int end = nums[0];
  for (int i = 0; i <= end; i++) {
    if (end >= n-1) return true;
    end = std::max(end, i + nums[i]);
  }
  return false;
}