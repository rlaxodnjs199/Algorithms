/*
Problem:
Given an array of size n+1, which contains
integer between 1 and n, prove that there is
at least one duplicate number. Assume there
is only one duplicate number.
*/
#include <iostream>
#include <vector>
int findduplicate1(std::vector<int>& nums) {
  int slow = 0;
  int fast = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }
  int entry = 0;
  while (entry != slow) {
    entry = nums[entry];
    slow = nums[slow];
  }
  return entry;
}