#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    double findMedian(std::vector<int>& nums1, std::vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();
      if (m > n) {
        return findMedian(nums2, nums1);
      }
      int si = 0, ei = m-1;
      int half_len = (m + n + 1) / 2;
      double maxl, minr;
      while (si <= ei) {
        int mid1 = (si + ei) / 2;
        int mid2 = half_len - mid1;
        if (mid1 > 0 && nums1[mid1-1] > nums2[mid2]) {
          ei = mid1 - 1;
        }
        else if (mid1 < m && nums2[mid2-1] > nums1[mid1]) {
          si = mid1 + 1;
        }
        else {
          if (mid1 == 0) {
            maxl = nums2[mid2 - 1];
          }
          else if (mid2 == 0) {
            maxl = nums1[mid1 - 1];
          }
          else {
            maxl = std::max(nums1[mid1 - 1], nums2[mid2 - 1])
          }
          if ((m + n) % 2) {
            return maxl;
          }
          if (mid1 == m) {
            minr = nums2[mid2];
          }
          else if (mid2 == n) {
            minr = nums1[mid1];
          }
          else {
            minr = std::min(nums1[mid1], nums2[mid2]);
          }
          return (maxl + minr) / 2.0;
        }
      }
    }
};

/*
1. Idea
By definition, median has middle index in an array (or average between two middle indices when a size of array is even). Therefore, median of an array as a result of merging two sorted array needs to separate the array by equal length. Now we apply this concept to two sorted array before merging them. In the first sorted array, some elements will be placed in the lefthand side of the merged array while rest of the elements will be placed in the righthand side of the merged array(possibly 0 element). Same applies for the second sorted array.
Therefore, we can define index i and j separate each arrays.
A[0.....i-1] A[i....m-1]
B[0.....j-1] B[j....n-1]
This i and j need to satisfy following 3 properties.
1. i+j = (m+n-1)/2 (-1 to ensure left part has 1 more element when a size of merged array is odd)
2. A[i-1] <= B[j]
3. B[j-1] <= A[i]
Then median is
max(A[i-1], B[j-1]) when a size of merged array is odd,
(max(A[i-1], B[j-1]) + min(A[i], B[j]))/2 when a size of merged array is even.

2. How to ensure size of array1 is always smaller or equal to array2?
int m = array1.size();
int n = array2.size();
if (m > n) {
  return findMedian(array2, array1);
}

3. How to achieve O(log(m+n)) ?
Halves the length of array1 every iteration.
To achieve this, we set first_index, last_index variables, and update them each time based on measurement.
*/