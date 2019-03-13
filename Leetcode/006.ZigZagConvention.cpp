/*
Problem:
Convert given string to zigzag pattern

Idea:
We declare vector of string of size Numrow to store
each character in correct order. Declare to for loop
to traverse string and store in vector in ascending
order first then in descending order next.
*/
#include <iostream>
#include <vector>
class Solution {
  public:
    std::string convert(std::string s, int numRows) {
      std::vector<std::string> array(numRows, "");
      if (numRows <= 1) {
        return s;
      }
      int i = 0;
      while (i < s.size()) {
        for (int j = 0; i < s.size() && j < numRows-1; j++) {
          array[j] += s[i++];
        }
        for (int k = numRows-1; i < s.size() && k > 0; k--) {
          array[k] += s[i++];
        }
      }
      std::string result = "";
      for (int n = 0; n < numRows; n++) {
        result.append(array[n]);
      }
      return result;
    }
};
int main() {
  Solution ans;
  std::string s = "ABB";
  std::cout << ans.convert(s, 1) << std::endl;
}

/*
1. Idea
Is there any method we can achieve result without using extra space?
I don't think so. Maybe we can achieve this for certain "numRows" values by
hardcoding the rule but it's difficult to find a mathematical formula that
applies to all "numRows" values.
Instead, we can declare "numRows" of strings and put every character in right order.
At the end, we can combine those strings to reach the result.

2.
while (i < s.size()) {
  for (int j = 0; i < s.size() && j < numRows-1; j++) {
    array[j] += s[i++];
  }
  for (int k = numRows-1; i < s.size() && k > 0; k--) {
    array[k] += s[i++];
  }
}

This doesn't work when numRows == 1 because j < 0 so for loop
doesn't work at all and goes to the infinite loop.
We can prevent this by dealing with special cases:
When numRows <= 1, we can simply return the input string.
*/