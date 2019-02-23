/*
Problem:
Difficulty[i] is the difficulty of job[i] and profit[i] is the profit of job[i]. Worker[i] is the ability of worker, which means this worker can complete a job with difficulty at most worker[i]. Every worker can be assigned to at most one job but it can be done several times.
Find maximum profit we can make.
*/
#include <iostream>
#include <vector>
#include <algorithm>
int maxprofit(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
  std::vector<std::pair<int, int>> profit_diff;
  for (int i = 0; i < profit.size(); i++) {
    profit_diff.push_back(std::make_pair(profit[i], difficulty[i]));
  }
  std::sort(profit_diff.begin(), profit_diff.end());
  int max_profit = 0;
  for (int i = worker.size()-1, j = worker.size()-1; i >= 0 && j >= 0;) {
    if (worker[i] <= profit_diff[j].second) {
      max_profit += profit_diff[j].first;
      i--;
    }
    else {
      j--;
    }
  }
  return max_profit;
}