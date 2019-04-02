/*
Problem:
Given a set of integers, return indices of two numbers sum up the target. Assume there is only one
answer exists.

Idea:
While iterating a vector, we store [value, index]
pair in an unordered_map. When we find target-value
exists in the map, we return indices of value(i) and 
target-value(map[target-value]).

Things I learned:
I had two choices to check if target - nums[i] exists
before or not. One is using 'find' and the other is
using 'count'. In this case, 'find' is more preferable
because after we check whether it exists or not,
we have to access the content of it. Using find and
return an iterator helps us avoid going through the 
hashing process twice(check existence, access contents).
Also, if I push nums[i] to the map before checking
target - nums[i] exists, I might fail to come up with
correct answer when same two elements consists an answer.
*/
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
        /*
        if (hash.count(target - nums[i])) {
          return {i, hashmap[target - nums[i]]};
        }
        */
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