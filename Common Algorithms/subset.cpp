#include <iostream>
#include <vector>
std::vector<std::vector<int>> subset_iterative(std::vector<int> nums) {
  std::vector<std::vector<int>> result(1);
  for (int inums = 0; inums < nums.size(); inums++) {
    int n = result.size();
    for (int j = 0; j < n; j++) {
      result.push_back(result[j]);
      result.back().push_back(nums[inums]);
    }
  }
  return result;
}

void subset_recursive_helper(std::vector<std::vector<int>>& result, std::vector<int>& temp, std::vector<int>& nums, int pos) {
  result.push_back(temp);
  for (int i = pos; i < nums.size(); i++) {
    temp.push_back(nums[i]);
    subset_recursive_helper(result, temp, nums, i+1);
    temp.pop_back();
  }
}
std::vector<std::vector<int>> subset_recursive(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> temp;
  subset_recursive_helper(result, temp, nums, 0);
  return result;
}

#include <algorithm>
std::vector<std::vector<int>> subset_dup(std::vector<int>& nums) {
  std::vector<std::vector<int>> result(1);
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    int n = result.size();
    if (!i || nums[i] != nums[i-1]) {
      for (int j = 0; j < n; j++) {
        result.push_back(result[j]);
        result.back().push_back(nums[i]);
      }
    }
  }
  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<std::vector<int>> result = subset_recursive(nums);
  for (auto i : result) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  std::vector<int> nums2 = {1, 5, 5, 2, 3, 4, 5};
  std::vector<std::vector<int>> result2 = subset_dup(nums);
  for (auto i : result2) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}