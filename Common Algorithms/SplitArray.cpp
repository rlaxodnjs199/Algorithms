/*
Given array, split array into two parts with equal sum.
I can switch at most one element.
Return true if partition is succesful, flase if it is not possible.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
  public:
    bool SplitArray(std::vector<int> nums) {
      std::unordered_map<int, int> leftmap;
      std::unordered_map<int, int> rightmap;
      for (int i = 0; i < nums.size(); i++) rightmap[nums[i]] += 1;
      int totalsum = 0;
      for (int i : nums) totalsum += i;
      int halfsum = totalsum / 2;
      int leftsum = 0;
      for (int i = 0; i < nums.size(); i++) {
        leftsum += nums[i];
        if (leftsum == halfsum) return true;
        if (leftsum < halfsum) {
          if (rightmap[halfsum-leftsum]) return true;
          else {
            leftmap[nums[i]]++;
            rightmap[nums[i]]--;
          }
        }
        else {
          if (leftmap[halfsum-leftsum]) return true;
          else {
            leftmap[nums[i]]++;
            rightmap[nums[i]]--;
          }
        }
      }
      return false;
    }
};
int main() {
  std::vector<int> nums = {2, 2, 2, 2, 3, 3, 3, 7};
  Solution s;
  if (s.SplitArray(nums)) {
    std::cout << "Split possible" << std::endl;
  }
  else {
    std::cout << "Split not possible" << std::endl;
  }
}