/*
Problem:
Given a 32-bit integer, reverse digits of an integer

Idea: Divide x by 10 each time and append last digit of x
to result in a  loop. To check overflow happens or not,
we need to check if result is less than (INT_MAX-x%10)/10
before update.
*/
#include <iostream>
#include <climits>
class Solution {
  public:
    int reverse(int x) {
      if (x < 0) return -reverse(-x);
      int result = 0;
      while (x != 0) {
        if (result > (INT_MAX - x % 10) / 10) return 0;
        result = result * 10 + x % 10;
        x /= 10;
      }
      return result;
    }
};
int main() {
  Solution s;
  std::cout << s.reverse(321) << std::endl;
}