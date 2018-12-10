/*
1. Idea
How to calculate next permutation?
First, we need to find index n1 such that arr[n1] < arr[n1+1].
Important part is that we need to start from n1 = arr.size()-2 to ensure that
next permutation can be executed following lexico something order.
If we can't find n1, that means that the arr as a whole is in reverse order,
and we can simply return sorted array.
When we find n1, next we need to find n2 such that arr[n2] > arr[n1].
Again, we need to start from n2 = arr.size()-1 to ensure the execution follows
lexical something order.
Now we find n1 and n2. We swap arr[n1] and arr[n2].
The last step is reversing arr[n1+1]~arr[end].
because arr[n1+1]~arr[end] is in descending order, we need to initiate this part
to ascending order to ensure next permutation is computed in right way.
*/
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    std::vector<int> nextpermutation (std::vector<int>& nums){
      int n = nums.size();
      int n1, n2;
      for (n1 = n-2; n1 >= 0; n1--) {
        if (nums[n1] < nums[n1+1]) break;
      }
      if (n1 < 0) {
        std::sort(nums.begin(), nums.end());
        return nums;
      }
      else {
        for (n2 = n-1; n2 > n1; n2--) {
          if (nums[n2] > nums[n1]) {
            std::swap(nums[n1], nums[n2]);
            std::reverse(nums.begin()+n1+1, nums.end());
            break;
          }
        }
      }
      return nums;
    }
};
int main() {
  std::vector<int> nums = {1, 2, 5, 4, 3};
  Solution s;
  std::vector<int> result = s.nextpermutation(nums);
  for (auto& n : result) {
    std::cout << n << " ";
  }
}