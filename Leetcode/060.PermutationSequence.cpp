/*
*/
#include <iostream>
#include <vector>
class Solution {
  public:
    std::vector<int> permutationSequence(std::vector<int> nums, int n) {
      int count = 0;
      return permutationUtil(nums, count, 0, n);
    }
    std::vector<int> permutationUtil(std::vector<int> nums, int& count, int begin, int n) {
      std::cout << count << " " << n << std::endl;
      if (count == n) {
        return nums;
      }
      else {
        for (int i = begin; i < nums.size(); i++) {
        std::swap(nums[begin], nums[i]);
        if (begin == nums.size()-1) count++;
        //std::cout << count << std::endl;
        permutationUtil(nums, count, begin+1, n);
      }
      }
    }
};
int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> result = s.permutationSequence(nums, 3);
  for (auto& n : result) {
    std::cout << n << " ";
  }
}