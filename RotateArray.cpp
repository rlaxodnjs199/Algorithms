/*
1.Idea
Rotate array with starting point at given index:
The easier method is to declare new array and copy
original array element in the right place.
By using %, we can get a simple rotation functionally.
When we think about a way to not use any extra memory space,
we need to modify elements in place. To do this, we keep
replacing element with (original index + rotate point index)%length.
However, there is two cases: 
1)swapping continues until the end so that
all the elements are placed in right position,
2)still need to swap elements with +1 original index in another loop
To satisfy all these two cases, we set total number of swap that we need.
for both cases, we need total array.length - 1 swap.
Therefore, we use this counting logic to finish the loop at right moment.
*/
#include <iostream>
#include <vector>
class Solution {
  public:
  std::vector<int> rotatedArray1(std::vector<int> nums, int index) {
    std::vector<int> result(nums.size());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      result[i] = nums[(i+index)%n];
    }
    return result;
  }
  std::vector<int> rotatedArray2(std::vector<int> nums, int index) {
    std::vector<int> result(nums.size());
    int n = nums.size();
    int count = 1;
    for (int start = 0; count < n; start++) {
      for (int current = start, next = (current + index) % n; next != start && count < n;) {
        std::swap(nums[current], nums[next]);
        current = next;
        next = (next + index) % n;
        count++;
      }
    }
    return nums;
  }
};
int main() {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  Solution s;
  std::vector<int> result1 = s.rotatedArray1(input, 3);
  std::vector<int> result2 = s.rotatedArray2(input, 3);
  for (auto& i : result1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (auto& i : result2) {
    std::cout << i << " ";
  }
}