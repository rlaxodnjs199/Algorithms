#include <iostream>
#include <string>
#include <vector>
class Solution {
  public:
    std::string LCP(std::vector<std::string> &strs) {
      std::string ans;
      if (strs.empty()) return "";
      if (strs.size() == 1) return strs[0];
      for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++) {
          if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
            return ans;
          }
        }
        ans += strs[0][i];
      }
      return ans;
    }
};
int main() {
  Solution s;
  std::vector<std::string> strs = {"flowers", "flight", "flow"};
  std::cout << s.LCP(strs) << std::endl;
}