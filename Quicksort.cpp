/*
1. Idea
Quick sort picks a pivot to compare with other elements.
In this implementation, partitionIndex puts elements
smaller than pivot to the left of the wall and the others
to the right of the wall. Only pivot is in the right place
after this function call. We repeat process again and again
*/

#include <iostream>
#include <vector>
void quicksort(std::vector<int> nums, int start_index, int end_index) {
  if (start_index < end_index) {
    int partition_index = partitionIndex(nums, start_index, end_index);
    quicksort(nums, start_index, partition_index-1);
    quicksort(nums, partition_index+1, end_index);
  }
}
int partitionIndex(std::vector<int> nums, int start_index, int end_index) {
  int pivot = nums[end_index];
  int wall = start_index-1;
  for (int i = start_index; i < end_index; i++) {
    if (nums[i] < nums[pivot]) {
      wall++;
      std::swap(nums[i], nums[wall]);
    }
  }
  std::swap(nums[pivot], nums[wall+1]);
  return wall+1;
}