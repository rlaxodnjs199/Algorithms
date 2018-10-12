/*
1. Idea
In a given array, if we want to return a
smallest postive integer not in array,
one thing we can do is sort the whole
array and search from the beginning.
This requires O(n logn + n) for sorting
and passing once through the array.
To improve this, we can modify the array
elements in place. To be more specific,
we are sending array elements to the 
right place, to the index that matches
its value. When array elemnt is negative
or bigger than the size of the array,
we can simply ignore it because that
doesn't involve in deriving an answer.
If we don't want to modify the array,
we should declare an extra space to
store elements. The most effective way
in this case is declaring a boolean
array of same size. When we encounter an
index with 'false' value, that's the answer.
*/

#include <iostream>
#include <vector>
class Solution {
  public:
    int smallestpositiveInteger(std::vector<int>& nums) {
      int size = nums.size();
      if (size == 0) return 1;
      for (int i = 0; i < size; i++) {
        while (nums[i] <= size && nums[i] > 0 && nums[i] != i+1) {
          if (nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
          }
          else {
            break;
          }
        }
      }
      for (int i = 0; i < size; i++) {
        if (nums[i] != i+1) return i+1;
      }
    }
};
int main() {
  Solution s;
  std::vector<int> nums = {1, 3, 4, 20, 3, 6};
  std::cout << s.smallestpositiveInteger(nums) << 
  std::endl;
}