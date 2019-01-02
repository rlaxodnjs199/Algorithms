#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int MaximumChainNumber(std::vector<std::vector<int>>& pairs) {
      int n = pairs.size();
      if (n == 0) return 0;
      int size = 1;
      std::sort(pairs.begin(), pairs.end(), [](std::vector<int>& a, std::vector<int>& b) {return a[0] < b[0];});
      std::vector<int> lastpair = pairs[0];
      for (int i = 1; i < n; i++) {
        if (pairs[i][1] < lastpair[1]) {
          lastpair = pairs[i];
        }
        else if (pairs[i][0] > lastpair[1]) {
          lastpair = pairs[i];
          size++;
        }
      }
      return size;
    }
};
int main() {
  std::vector<std::vector<int>> pairs = {{1, 2}, {3, 4}, {2, 3}};
  Solution s;
  std::cout << s.MaximumChainNumber(pairs);
}