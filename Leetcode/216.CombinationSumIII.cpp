/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
*/
#include <iostream>
#include <vector>
std::vector<std::vector<int>> comb3(int k, int n) {
  std::vector<std::vector<int>> result;
  std::vector<int> temp;
  helper(result, temp, k, n, 1);
  return result;
}
void helper(std::vector<std::vector<int>>& result, std::vector<int>& temp, int k, int n, int begin) {
  if (n < 0) return;
  if (k < 0) return;
  if (n == 0 && k == 0) {
    result.push_back(temp);
    return;
  }
  for (int i = begin; i < 10; i++) {
    temp.push_back(i);
    helper(result, temp, k, n, i+1);
    temp.pop_back();
  }
}