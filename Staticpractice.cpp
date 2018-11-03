#include <iostream>
class Solution {
  public:
    static int x, y;
    static void Print() {
      std::cout << x << "," << y << std::endl;
    }
    static void setx(int a) {
      x = a;
    }
    static void sety(int b) {
      y = b;
    }
};
int Solution::x;
int Solution::y;
int main() {
  //When x, y are not private
  Solution::x = 5;
  Solution::y = 8;
  Solution::Print();
  //When x, y are private: Declare setter function
  Solution::setx(2);
  Solution::sety(3);
  Solution::Print();
  std::cin.get();
}