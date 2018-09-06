#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int maxArea(std::vector<int>& heights) {
      int maxArea = 0;
      int l = 0;
      int r = heights.size()-1;
      while (l < r) {
        int currentArea = (r-l) * std::min(heights[l], heights[r]);
        maxArea = std::max(maxArea, currentArea);
        if (heights[l] > heights[r]) {
          r--;
        }
        else {
          l++;
        }
      }
      return maxArea;
    }
};
int main() {
  class Solution s;
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << s.maxArea(heights) << std::endl;
  //std::cin.get();
}

/*
1. Idea
Brute force: Calculate all the possibilites: O(m^2)

Use two pointers, one starting from the left and the other starting from the right.
We should go through all the individual elements at least once, and using two pointers
can maximize the efficiency.
Calculate and update maxArea when needed
When to move pointers?
Move smaller one by 1 to ensure that new area has a chance to be bigger than the previous area
*/