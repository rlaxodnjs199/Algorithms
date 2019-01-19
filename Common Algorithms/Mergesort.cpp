/*
Mergesort with merging in-place: Trade-off between performance and space complexity.
O(N^2logN) while O(1) space complexity.
Most common mergesort needs O(NlogN) time complexity and O(n) space complexity
to store temporary sorted data before copying.
1. Mergesort needs O(logN) splits and each split layer needs O(n) merge operation.
: Average and worst performance are both O(NlogN)
*/
#include <iostream>
#include <vector>
void mergeinplace(std::vector<int>& nums, int begin, int mid, int end) {
  for (int i = begin, j = mid+1; i <= mid && j <= end;) {
    if (nums[i] <= nums[j]) {
      i++;
    }
    else {
      int temp = nums[j];
      int temp_index = j;
      while (temp_index != i) {
        nums[temp_index] = nums[temp_index-1];
        temp_index--;
      }
      nums[i] = temp;
      i++;
      mid++;
      j++;
    }
  }
}
void merge(std::vector<int>& nums, int begin, int mid, int end) {
  std::vector<int> temp(end-begin+1);
  int index = 0;
  int i, j;
  for (i = begin, j = mid+1; i <= mid && j <= end;) {
    if (nums[i] <= nums[j]) {
      temp[index++] = nums[i++];
    }
    else {
      temp[index++] = nums[j++];
    }
  }
  while (i <= mid) {
    temp[index++] = nums[i++];
  }
  while (j <= end) {
    temp[index++] = nums[j++];
  }
  for (auto i : temp) {
    nums[begin++] = i;
  }
}
void divide(std::vector<int>& nums, int begin, int end) {
  if (begin < end) {
    int mid = begin + (end - begin) / 2;
    divide(nums, begin, mid);
    divide(nums, mid+1, end);
    merge(nums, begin, mid, end);
  }
}
void mergesort(std::vector<int>& nums) {
  divide(nums, 0, nums.size()-1);
}
int main() {
  std::vector<int> nums = {1, 5, 3, 7, 6, 4, 9, 0};
  mergesort(nums);
  for (int i : nums) {
    std::cout << i << " ";
  }
}

