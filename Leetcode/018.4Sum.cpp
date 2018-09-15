#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
  public:
    std::vector<std::vector<int>> foursum1(std::vector<int>& nums, int target) {
      std::vector<std::vector<int>> result;
      int n = nums.size();
      if (n < 4) return result;
      std::sort(nums.begin(), nums.end());
      for (int pivot1 = 0; pivot1 < n-3;) {
        int a = nums[pivot1];
        for (int pivot2 = pivot1+1; pivot2 < n-2;) {
          int b = nums[pivot2];
          for (int ptr1 = pivot2+1, ptr2 = n-1; ptr1 < ptr2;) {
            int c = nums[ptr1];
            int d = nums[ptr2];
            int sum = a+b+c+d;
            if (sum == target) {
              result.push_back({a,b,c,d});
              while (c == nums[++ptr1]);
              while (d == nums[--ptr2]);
            }
            else if (sum < target) {
              ptr1++;
            }
            else {
              ptr2--;
            }
          }
          while (b == nums[++pivot2]);
        }
        while (a == nums[++pivot1]);
      }
      return result;
    }

    std::vector<std::vector<int>> foursum2(std::vector<int>& nums, int target) {
      std::vector<std::vector<int>> result;
      std::unordered_map<int, std::vector<std::pair<int, int>>> hash;
      std::sort(nums.begin(), nums.end());
      int n = nums.size();
      for (int i = 0; i < n-1; i++) {
        int a = nums[i];
        for (int j = i+1; j < n; j++) {
          int b = nums[j];
          hash[nums[i]+nums[j]].push_back(std::make_pair(i, j));
        }
      }
      for (int i = 0; i < n-3;) {
        int a = nums[i];
        for (int j = i+1; j < n-2;) {
          int b = nums[j];
          int key = target-a-b;
          if (hash.count(key)) {
            for (auto it = hash[key].begin(); it != hash[key].end(); it++) {
              int k = (*it).first;
              int l = (*it).second;
              if (k > j) {
                if (!result.empty() && nums[k] == result.back()[2] && nums[l] == result.back()[3]) {
                  continue;
                }
                result.push_back({a,b,nums[k],nums[l]});
              }
            }
          }
          while (b == nums[++j]);
        }
        while (a == nums[++i]);
      }
      return result;
    }
};
int main() {
  std::vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
  Solution s;
  std::vector<std::vector<int>> result = s.foursum2(nums, 0);
  for (const auto& row : result) {
    std::cout << "[ ";
    for (const auto& n : row) {
      std::cout << n << " ";
    }
    std::cout << "]" << std::endl;
  }
}

/*
1. Idea
This is a slight modification of 3sum problem. Now instead of setting one pivot, we set two pivots and place two pointers at the left and right end after that. Running time is basically O(n^3).
Another way to do this is using a hashmap.
By scanning two entries at a time, we fill out the hashmap which has sum of two entries as their key and vector of pair of indices as their value. We should not check duplicates at this time because the index matters later on. For example, even though nums[3] + nums[4] == nums[2] + nums[4] == 3, storing only one of two pairs result wrong answer since one of nums[2] and nums[3] can be used by other pivot among i, j, k, l. After filling out the hashmap, now we scan entire array again. At this time we should check duplicates for all the four pivots. We can easily do this by two for loops for first two pivots. For k & l, we only approach them when hash.count(nums[i]+nums[j]) != 0. At this time, two conditions should be used to prevent duplicates. One is k > j, which prevents a combination of index {0 3 2 4}... After that, we should check if the answer already exists. To do this, we only need to check the latest vector that we put in to the result vector because the array has already been sorted and two identical answers always occur continuously.
*/