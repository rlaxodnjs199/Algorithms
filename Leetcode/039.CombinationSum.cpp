/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
*/
#include <iostream>
#include <vector>
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> result;
  std::vector<int> temp;
  helper(result, temp, candidates, target, 0);
  return result;
}
void helper(std::vector<std::vector<int>>& result, std::vector<int>& temp, std::vector<int>& candidates, int target, int start) {
  if (target < 0) return;
  if (target == 0) {
    result.push_back(temp);
    return;
  }
  for (int i = start; i < candidates.size(); i++) {
    temp.push_back(candidates[i]);
    helper(result, temp, candidates, target - candidates[i], i);
    temp.pop_back();
  }
}