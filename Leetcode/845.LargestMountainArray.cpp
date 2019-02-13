#include <iostream>
#include <vector>
int logestmountain(std::vector<int>& nums) {
  if (nums.size() < 3) return 0;
  int max_len = 0;
  int cur_len = 1;
  bool ascend = nums[0] < nums[1];
  bool descend = nums[1] > nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i-1] < nums[i]) {
      if (ascend && !descend) {
        cur_len++;
      }
      else {
        cur_len = 2;
        ascend = true;
        descend = false;
      }
    }
    else if (nums[i-1] > nums[i]) {
      if (ascend) {
        descend = true;
        cur_len++;
        if (cur_len >= 3) max_len = std::max(max_len, cur_len);
      }
    }
    else {
      ascend = false;
      descend = false;
    }
  }
}