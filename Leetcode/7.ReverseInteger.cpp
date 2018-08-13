#include <iostream>
class Solution {
  public:
    int reverse(int x) {
      int result = 0;
      while (x != 0) {
        int newresult = result*10 + x%10;
        if ((newresult-x%10)/10 != result) {
          return 0;
        }
        x /= 10;
        result = newresult;
      }
      return result;
    }
};
int main() {
  Solution s;
  std::cout << s.reverse(321) << std::endl;
}
/*
1. Idea
How to reverse 32bit integer?
Store the current update in "newresult" variable.
Caculate backward and check if the "newresult" can possibly
return back to the "result". Since overflow loses 1-bit amount of data
it prevents going back to the original value.
*/