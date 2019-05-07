#include <iostream>
#include <vector>
bool search(std::vector<int>& nums, int target) {
  if (nums.empty()) return false;
  int left = 0;
  int right = nums.size()-1;
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return true;
      if (nums[mid] <= nums[right]) {
          if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
              left++;
              right--;
          }
          else if (nums[mid] < target && nums[right] >= target) {
              left = mid + 1;
          }
          else {
              right = mid - 1;
          }
      }
      else {
          if (nums[left] <= target && nums[mid] > target) {
              right = mid - 1;
          }
          else {
              left = mid + 1;
          }
      }
  }
  return false;
}