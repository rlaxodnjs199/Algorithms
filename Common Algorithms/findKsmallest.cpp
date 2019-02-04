#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
bool compare(std::vector<int> p1, std::vector<int> p2) {
    if (p1[0]*p1[0]+p1[1]*p1[1] < p2[0]*p2[0]+p2[1]*p2[1]) {
      return true;
    }
    return false;
  }
class Solution {
  public:
  std::vector<int> Ksmallest(std::vector<int> nums, int k) {
    std::make_heap(nums.begin(), nums.end());
    std::vector<int> result(nums.end()-k, nums.end());
    std::make_heap(result.begin(), result.end());
    for (int i = nums.size()-k-1; i >= 0; i--) {
      if (nums[i] < result.front()) {
        std::pop_heap(result.begin(), result.end());
        result.pop_back();
        result.push_back(nums[i]);
        std::push_heap(result.begin(), result.end());
      }
    }
    return result;
  }
  
  std::vector<std::vector<int>> Ksmallestpoint(std::vector<std::vector<int>> points, int k) {
    std::make_heap(points.begin(), points.end(), compare);
    std::vector<std::vector<int>> result(points.end()-k, points.end());
    std::make_heap(result.begin(), result.end(), compare);
    for (int i = points.size()-k-1; i >= 0; i--) {
      if (compare(points[i], result.front())) {
        std::pop_heap(result.begin(), result.end());
        result.pop_back();
        result.push_back(points[i]);
        std::push_heap(result.begin(), result.end());
      }
    }
    return result;
  }
};
int main() {
  Solution s;
  std::vector<std::vector<int>> points = {{-2, 4}, {0, -2}, {-1, 0}, {3, 5}, {-2, -3}, {3, 2}};
  points = s.Ksmallestpoint(points, 3);
  for (auto i : points) {
    std::cout << "[";
    for (auto j : i) {
      std::cout << j;
    }
    std::cout << "] ";
  }
}