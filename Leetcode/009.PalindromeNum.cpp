#include <iostream>
class Solution {
  public:
    bool ispalin(int x) {
      if (x < 0) {
        return false;
      }
      int result;
      for (int temp = x; temp != 0; temp /= 10) {
        result = result*10 + temp%10;
      }
      if (result != x) {
        return false;
      }
      return true;
    }
};
int main() {
  Solution ans;
  int n = 121;
  if (ans.ispalin(n)) {
    std::cout << n << " is a Palindrome Number" << std::endl;
  }
  else {
    std::cout << n << " is not a Palindrome Number" << std::endl;
  }
}