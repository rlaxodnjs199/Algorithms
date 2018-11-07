/*
1. Idea
The amount of water in the bowl can be determined by height of two end of the bowl.
When one edge is deeper than the other edge, water can be filled based on the depth
of much swallow edge. Therefore, we need to keep update left end and right end.
When height[left] is smaller than height[right], it means that water can be filled
based on height[left]. We increment left by 1 and leave right because there is
a possibility that height[right] can be filled with water when we meet more longer
edge from the left side of it while there is no possibility that height[left] can
be filled additionally.
*/

#include <iostream>
#include <vector>
class Solution {
  public:
    int trapWater(std::vector<int>& heights) {
      int leftmax = 0, rightmax = 0, water = 0;
      int n = heights.size();
      for (int left = 0, right = n-1; left < right;) {
        if (heights[left] < heights[right]) {
          if (heights[left] < leftmax) {
            water += leftmax - heights[left];
          }
          else {
            leftmax = heights[left];
          }
          left++;
        }
        else {
          if (heights[right] < rightmax) {
            water += rightmax - heights[right];
          }
          else {
            rightmax = heights[right];
          }
          right--;
        }
      }
      return water;
    }
};
int main() {
  Solution s;
  std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
  std::cout << s.trapWater(heights) << std::endl;
}