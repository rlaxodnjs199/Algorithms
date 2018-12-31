#include <iostream>
#include <vector>
class Solution1 {
  public:
    int lengthofLIS(std::vector<int>& nums) {
      int n = nums.size();
      if (n == 0) return 0;
      int dp[n];
      dp[0] = 1;
      int result = 1;
      for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = i-1; j >= 0; j--) {
          if (nums[i] > nums[j]) {
            dp[i] = std::max(dp[i], dp[j] + 1);
            result = std::max(result, dp[i]);
          }
        }
      }
      return result;
    }
};
class Solution2 {
  public:
    int binarysearch(int nums[], int left, int right, int key) {
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= key) right = mid;
        else left = mid + 1;
      }
      return right;
    }
    int lengthofLIS(std::vector<int>& nums) {
      if (nums.empty()) return 0;
      int LISarray[nums.size()];
      int size = 0;
      for (int i = 0; i < nums.size(); i++) {
        int index = binarysearch(LISarray, 0, i, nums[i]);
        std::cout << i << " " << index << std::endl;
        LISarray[index] = nums[i];
        if (index == size) size++;
      }
      return size;
    }
};
int main() {
  Solution1 s;
  std::vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
  std::cout << s.lengthofLIS(nums) << std::endl;
  Solution2 t;
  std::cout << t.lengthofLIS(nums) << std::endl;
}