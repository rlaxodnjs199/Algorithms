/*
1. Idea
It is like sliding a window.
We reset a size of window when sum of window
becomes negative that it is useless to maintain for
calculating maximum subarray.
When all the elements in the numbers array are negative,
maximum is the single negative number with highest value.
Second Method is to use DP Solution.
Lets define dp[i] as largest sum ends with nums[i].
This should be either dp[i-1] + nums[i] or nums[i].
After filling up the table, we iterate through table again
and pick the biggest element.
*/
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
    int MaximumSubarray2(std::vector<int> nums) {
      if (nums.empty()) return 0;
      int n = nums.size();
      std::vector<int> dp_array(n);
      dp_array[0] = nums[0];
      for (int i = 1; i < n; i++) {
        dp_array[i] = std::max(dp_array[i-1]+nums[i], nums[i]);
      }
      int max = nums[0];
      for (auto& i : dp_array) {
        if (i > max) max = i;
      }
      return max;
    }
};
int main() {
  std::vector<int> num = {-2, -5, 6, -2, -3, 1, 5, -6};
  Solution s;
  std::cout << s.MaximumSubarray1(num);
  std::cout << std::endl;
  std::cout << s.MaximumSubarray2(num);
}