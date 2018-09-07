#include <iostream>
#include <string>
class Solution {
  public:
    std::string intToRoman(int num) {
      std::string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
      std::string ans = "";
      for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
          ans += roman[i];
          num -= values[i];
        }
      }
      return ans;
    }
};
int main() {
  Solution s;
  std::cout << s.intToRoman(1894) << std::endl;
}

/*
1. Idea
At first, I was thinking of hard coding all the possibilites, for example
if (num >= 1000) {
  ans += "M";
  num -= 1000;
}
However, this is so unefficient, spend me lots of time
and would be an extremely long code.
Instead, I decide to initialize arrays of Romans and corresponding integers
so that I can take off num gradually and at the same time convert it to the Romans
*/