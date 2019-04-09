/*
Problem:
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
*/
#include <iostream>
#include <vector>
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> result(1);
  for (auto& n : nums) {
    int size = result.size();
    for (int i = 0; i < size; i++) {
      result.push_back(result[i]);
      result.back().push_back(n);
    }
  }
  return result;
}