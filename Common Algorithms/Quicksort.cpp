/*
1. Idea
Quick sort picks a pivot to compare with other elements.
In this implementation, partitionIndex puts elements
smaller than pivot to the left of the wall and the others
to the right of the wall. Only pivot is in the right place
after this function call. we repeat this process again 
and again until all the pivots are placed in the right place.
dividing array to two parts help increasing algorithm speed by
working like a heap data structure.
2. Through this algorithm, I reminded that every recursive call
algorithm has to have a certain condition statement to stop the
call at a certain moment. Should not forget to give them
a condition!
3. There are on average O(logN) splits since we split array to two halves.
There are three worst scenarios that make quicksort O(n^2) runtime.
1) Array is sorted: when we choose 'end' as a pivot, size of second half of
the array chosen by partition is always 1.
2) Array is reverse sorted: when we choose 'end' as a pivot, size of first half of
the array chosen by partition is always 1.
3) All elements are same: when we choose 'end' as a pivot, size of first half of
the array chosen by partition is always 1.
4. Worst space complexity is O(logN) from stack frame.
5. How to improve quicksort to avoid worst case?
Choosing optimal pivot: Use median value between array[low], array[high], and array[mid]
mid = low + (hi - low) / 2;
if (A[mid] < A[low]) swap;
if (A[low] > A[hi]) swap;
if (A[mid] < A[hi]) swap;
choose A[hi] as pivot
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