#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
  public:
    std::vector<int> powerfulIntegers(int x, int y, int bound) {
      std::unordered_set<int> result;
      for (int i = x? 1 : 0; i <= bound; i *= x) {
        for (int j = y? 1 : 0; i + j <= bound; j *= y) {
          result.insert(i + j);
          if (y <= 1) break;
        }
        if (x <= 1) break;
      }
      return std::vector<int>(result.begin(), result.end());
    }
};