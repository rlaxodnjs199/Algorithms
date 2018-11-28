#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int MaximumSubarray1(std::vector<int> nums) {
      if (nums.empty()) return 0;
      int maxsum = nums[0];
      int tempsum = 0;
      int left = 0;
      int right = 0;
      while (right < nums.size()) {
        tempsum += nums[right];
        maxsum = std::max(tempsum, maxsum);
        if (tempsum < 0) {
          left = right+1;
          tempsum = 0;
        }
        right++;
      }
      return maxsum;
    }
};
int main() {
  std::vector<int> num = {-2, -5, 6, -2, -3, 1, 5, -6};
  Solution s;
  std::cout << s.MaximumSubarray1(num);
}