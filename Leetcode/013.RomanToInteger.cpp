#include <iostream>
#include <string>
class Solution {
  public:
    int romanToInt(std::string s) {
      std::string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
      int ans = 0;
      for (int i = 0; i < 13 && !s.empty(); i++) {
        while (s.substr(0, roman[i].size()) == roman[i]) {
          ans += values[i];
          s = s.substr(roman[i].size());
        }
      }
      return ans;
    }
};
int main() {
  Solution s;
  std::cout << s.romanToInt("IV") << std::endl;
}

/*
1. Idea
It is reverse of what I did in 012.IntegerToRoman.
We look roman[i].size() of characters at once
and check if that is equal to substring of s of equal length.
Modify s when the comparison matches until it becomes empty string.
One thing I learned here is that I need to initialize int variable to be 0.
Not writing a value doesn't mean it always be initialized to 0.
*/