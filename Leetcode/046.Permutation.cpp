#include <iostream>
#include <vector>
template<typename T> void print_vec(T& vec) {
  for (auto& nums : vec) {
    std::cout << "[ ";
    for (auto& num : nums) {
      std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
  }
}
class Solution {
  public:
    std::vector<std::vector<int>> permutation(std::vector<int>& nums) {
      std::vector<std::vector<int>> result;
      permutationUtil(result, nums, 0);
      return result;
    }
    void permutationUtil(std::vector<std::vector<int>>& result, std::vector<int>& nums, int begin) {
      if (begin == nums.size()) {
        result.push_back(nums);
        return;
      }
      for (int i = begin; i < nums.size(); i++) {
        std::swap(nums[begin], nums[i]);
        permutationUtil(result, nums, begin+1);
        std::swap(nums[begin], nums[i]);
      }
    }
};
int main() {
  Solution s;
  std::vector<int> nums = {1,2,3,4,5};
  std::vector<std::vector<int>> result = s.permutation(nums);
  print_vec(result);
}