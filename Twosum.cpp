#include <iostream>
#include <unordered_map>
#include <vector>
class solution {
  public:
    std::vector<int> twosum(std::vector<int>& nums, int target) {
      std::unordered_map <int, int> hash;
      for (int i = 0; i < nums.size(); i++) {
        auto it = hash.find(target - nums[i]);
        if (it != hash.end()) {
          return {i, it->second};
        }
        hash[nums[i]] = i;
      }
      return {0, 0};
    }
};
int main() {
  solution s;
  std::vector<int> array = {1,3,5,7};
  std::vector<int> ans = s.twosum(array, 4);
  for (auto i = ans.begin(); i != ans.end(); i++) {
    std::cout << *i << std::endl;
  }
}