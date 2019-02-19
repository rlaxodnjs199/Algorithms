/*
A boat can carry maximum two people with limit weight.
Find minimum number of boats to carry all people in the
given array.
*/
#include <iostream>
#include <vector>
#include <algorithm>
int numboat(std::vector<int> weights, int limit) {
  std::sort(weights.begin(), weights.end());
  int num_boat = 0;
  for (int start = 0, end = weights.size() - 1; start <= end; end--) {
    if (weights[start] + weights[end] <= limit) {
      start++;
    }
    num_boat++;
  }
  return num_boat;
}