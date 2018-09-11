#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    std::vector<std::vector<int>> threesum(std::vector<int>& nums) {
      std::vector<std::vector<int>> res;
      int n = nums.size();
      if (n < 3) return res;
      std::sort(nums.begin(), nums.end());
      for (int pivot = 0; pivot < n-2; pivot++) {
        int a = nums[pivot];
        if (a > 0) break;
        if (pivot > 0 && a == nums[pivot-1]) continue;
        for (int p1 = pivot+1, p2 = n-1; p1 < p2;) {
          int b = nums[p1];
          int c = nums[p2];
          int sum = a+b+c;
          if (sum == 0) {
            res.push_back({a, b, c});
            while (b == nums[++p1]);
            while (c == nums[--p2]);
          }
          else if (sum < 0) {
            p1++;
          }
          else {
            p2--;
          }
        }
      }
      return res;
    }
};
int main() {
  Solution s;
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> ans = s.threesum(nums);
  for (auto &v : ans) {
    std::cout << "[";
    for (auto &num : v) {
      std::cout << " " << num << " ";
    }
    std::cout << "]" << std::endl;
  }
}

/*
1. Idea
First, we can look through all the possible combinations of three values
with three for loops, which will be O(n^3) running time algorithm.
This is bad performance.
Three sum: Let's pick one number at the beginning of the array.
This works as a starting point of three number combinations.
Now we are dealing with remaining two numbers to make desirable sum.
We place that two numbers at the beginning and end of the array
which starts right after the starting pivot.
This continues until the starting pivot reaches nums.size()-2
and the loops will be terminated.
One thing we have to keep in mind is that we have to check if the answer
contains duplicates. To prevent this, for each three indices, we have to
check if the updated indices are equal to previous value that they pointed.
Now it is O(n^2) running time and O(1) space algorithm.
2. How to use sort? Use iterator + built in function or possibly lambda function
std::sort(nums.begin(), nums.end()); -----> ascending order(default)
std::sort(nums.begin(), nums.end(), greater<int>()); -----> descending order
std::sort(nums.begin(), nums.end(), [](const int& a, const int& b) {return a > b;}); dorder
3. How to find certain value inside of the vector?
if (std::find(vec.begin(), vec.end(), value) != vec.end()) {
  we find it
} else {
  we couldn't find it
}
4. How to initialize vector?
vector<int> vec;
vector<int> vec(3, 10) -> size 3 with value 10 on each of elements
vector<int> vec{10, 20, 30};
vector<int>vec = {10, 20, 30};
5. How to print 2D vector? ex) vector<vector<int>>
for (const auto &row : vec) {
  for (const auto &col : row) {
    cout << col << endl;
  }
}

*/