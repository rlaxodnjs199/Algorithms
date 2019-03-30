/*
Problem:
Given two integers n and k, return all possible combinations 
of k numbers out of 1 ... n
*/
#include <iostream>
#include <vector>
std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> result;
  if (k > n) return result;
  std::vector<int> temp;
  combinehelper(result, temp, n, k, 1);
  return result;
}
void combinehelper(std::vector<std::vector<int>>& result, std::vector<int>& temp, int n, int k, int c) {
  if (k == 0) {
    result.push_back(temp);
    return;
  }
  for (int i = c; i <= n; i++) {
    temp.push_back(i);
    combinehelper(result, temp, n, k-1, i+1);
    temp.pop_back();
  }
}