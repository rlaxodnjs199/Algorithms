#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
class Solution {
  public:
    int threeSumClosest(std::vector<int>& nums, int target) {
      int n = nums.size();
      if (n < 3) return 0;
      std::sort(nums.begin(), nums.end());
      int res;
      int diff = INT_MAX;
      for (int pivot = 0; pivot < n-2; pivot++) {
        for (int p1 = pivot+1, p2 = n-1; p1 < p2;) {
          int sum = nums[pivot]+nums[p1]+nums[p2];
          int currentdiff = std::abs(target-sum);
          if (sum == target) {
            return sum;
          }
          else if (sum < target) {
            p1++;
          }
          else {
            p2--;
          }
          if (currentdiff < diff) {
            diff = currentdiff;
            res = sum;
          }
        }
      }
      return res;
    }
};
int main() {
  std::vector<int> nums = {-1, 2, 1, -4};
  Solution s;
  std::cout << s.threeSumClosest(nums, 1) << std::endl;
}

/*
1. Idea
This is similar to 3sum problem that I solved yesterday.
One difference is that the return type is int and the problem requires
to return the closest sum. Also, they allowed us to assume that there
are only one valid solution. We can't know if the closest sum is bigger
or smaller than the target. Therefore we should a variable to update
a difference between sum and the target. We only update the answer when
the difference is smaller than the previous one.
*/