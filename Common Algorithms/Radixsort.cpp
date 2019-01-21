#include <iostream>
#include <unordered_map>
#include <vector>
void Countsort(std::vector<int>& nums, int expo) {
  std::vector<int> countmap(10, 0);
  for (int i = 0; i < nums.size(); i++) {
    countmap[(nums[i]/expo)%10]++;
  }
  int prev_sum = -1;
  for (int i = 0; i < 10; i++) {
    if (countmap[i] != 0) {
      countmap[i] += prev_sum;
      prev_sum = countmap[i];
    }
  }
  std::vector<int> temp_vector(nums.size());
  for (int i = nums.size()-1; i >= 0; i--) {
    temp_vector[countmap[(nums[i]/expo)%10]--] = nums[i];
  }
  nums = std::vector<int>(temp_vector.begin(), temp_vector.end());
}
void Radixsort(std::vector<int>& nums) {
  int max_num = nums[0];
  for (int i : nums) {
    if (i > max_num) max_num = i;
  }
  for (int expo = 1; max_num/expo >= 1; expo *= 10) {
    Countsort(nums, expo);
  }
}
int main() {
  std::vector<int> nums = {170, 45, 75, 90, 802, 24, 2, 66};
  Radixsort(nums);
  for (int i : nums) {
    std::cout << i << " ";
  }
}