#include <iostream>
#include <vector>
#include <string>
class Solution {
  public:
    std::vector<std::string> gp(int n) {
      std::vector<std::string> result;
      std::string temp;
      gphelper(result, temp, 0, 0, n);
      return result;
    }
    void gphelper(std::vector<std::string>& result, std::string& temp, int open, int close, int n) {
      if (open == n && close == n) {
        result.push_back(temp);
        return;
      }
      if (open < n) {
        temp.push_back('(');
        gphelper(result, temp, open+1, close, n);
        temp.pop_back();
      }
      if (open > close) {
        temp.push_back(')');
        gphelper(result, temp, open, close+1, n);
        temp.pop_back();
      }
    }
};
int main() {
  Solution s;
  std::vector<std::string> result = s.gp(5);
  for (auto& str : result) {
    std::cout << str << std::endl;
  }
}

/*
1. Idea
To generate all the combinations of valid pairs of parentheses,
we need to consider some restriction on placing open parentheses
and close parentheses. We can place open parentheses at any place when
the number of open parentheses is smaller than n.
We can place close parentheses when the number of close parentheses is smaller than n
and it is smaller than the number of open parentheses.
Therefore, we can write a backtracking recursive function to place '(' and ')'
in a right space.
*/