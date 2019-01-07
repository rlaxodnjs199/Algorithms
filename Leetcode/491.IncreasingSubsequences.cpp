#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
class Solution {
  public:
    std::vector<std::vector<int>> findsubsequences1(std::vector<int>& nums) {
      std::vector<std::vector<int>> result;
      std::vector<int> temp;
      helperfunction(result, nums, temp, 0);
      return result;
    }
    void helperfunction(std::vector<std::vector<int>>& result, std::vector<int>& nums, std::vector<int>& temp, int begin) {
      std::unordered_set<int> hash;
      for (int i = begin; i < nums.size(); i++) {
        if ((temp.empty() || temp.back() <= nums[i]) && hash.find(nums[i]) == hash.end()) {
          hash.insert(nums[i]);
          temp.push_back(nums[i]);
          if (temp.size() >= 2) result.push_back(temp);
          helperfunction(result, nums, temp, i+1);
          temp.pop_back();
        }
      }
    }
    std::vector<std::vector<int>> findsubsequences2(std::vector<int>& nums) {
      std::set<std::vector<int>> result;
      std::vector<std::vector<int>> temp(1);
      for (int i = 0; i < nums.size(); i++) {
        int n = temp.size();
        for (int j = 0; j < n; j++) {
          if (temp[j].empty() || temp[j].back() <= nums[i]) {
            std::vector<int> temp2 = temp[j];
            temp2.push_back(nums[i]);
            if (temp2.size() > 1) result.insert(temp2);
            temp.push_back(temp2);
          }
        }
      }
      return std::vector<std::vector<int>>(result.begin(), result.end());
    }
};
int main() {
  std::vector<int> nums = {4, 3, 7, 7};
  Solution s;
  std::vector<std::vector<int>> result = s.findsubsequences1(nums);
  for (auto vec : result) {
    std::cout << "[ ";
    for (auto num : vec) {
      std::cout << num << " ";
    }
    std::cout << "] ";
  }
}