/*
*/
#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
  public:
  std::vector<int> FindthreesortedarraysIntersection(std::vector<std::vector<int>> arrays) {
    std::vector<int> result;
    if (arrays.size() < 3) return result;
    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < arrays[0].size() && p2 < arrays[1].size() && p3 < arrays[2].size()) {
      if (arrays[0][p1] == arrays[1][p2] && arrays[1][p2] == arrays[2][p3]) {
        result.push_back(arrays[0][p1]);
        p1++;
        p2++;
        p3++;
      }
      else if (arrays[0][p1] < arrays[1][p2]) p1++;
      else if (arrays[1][p2] < arrays[2][p3]) p2++;
      else p3++;
    }
  }
  std::vector<int> FindthreeunsortedarraysIntersection(std::vector<std::vector<int>> arrays) {
    std::vector<int> result;
    if (arrays.empty()) return result;
  }
};
int main() {
  Solution s;
  std::vector<std::vector<int>> arrays = {
    {2, 6, 9, 11, 13, 17},
    {3, 6, 7, 11, 13, 17},
    {4, 5, 6, 9, 11, 13}
  };
  std::vector<int> result = s.FindthreesortedarraysIntersection(arrays);
  for (auto n : result) {
    std::cout << n << " ";
  }
}