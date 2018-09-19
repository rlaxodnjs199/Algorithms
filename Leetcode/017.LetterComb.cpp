#include <iostream>
#include <vector>
#include <string>
class Solution {
  public:
    std::vector<std::string> lettercomb1(std::string digits) {
      std::vector<std::string> res;
      if (digits.empty()) return res;
      std::string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      res.push_back("");
      for (int i = 0; i < digits.size(); i++) {
        std::vector<std::string> temp;
        std::string letter = letters[digits[i]-'2'];
        for (int j = 0; j < letter.size(); j++) {
          for (int k = 0; k < res.size(); k++) {
            temp.push_back(res[k]+letter[j]);
          }
        }
        res = temp;
      }
    }
    
    std::vector<std::string> lettercomb2(std::string digits) {
      std::vector<std::string> res;
      std::string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      std::string temp = "";
        permutation(res, digits, letters, temp, 0);
      return res;
    }
    void permutation(std::vector<std::string>& res, std::string& digits, std::string letters[], std::string& temp, int index) {
      if (index == digits.size()) {
        res.push_back(temp);
        return;
      }
      std::string str = letters[digits[index]-'2'];
      for (int i = 0; i < str.size(); i++) {
        temp.push_back(str[i]);
        permutation(res, digits, letters, temp, index+1);
        temp.pop_back();
      }
    }
};
int main() {
  Solution s;
  std::string digits = "23";
  std::vector<std::string> res = s.lettercomb2(digits);
  std::cout << "[ ";
  for (const auto& i : res) {
    std::cout << i << " ";
  }
  std::cout << "]";
}

/*
1. Idea
Set a table which is needed to convert digit string to alphabet string.
I wrote iterative function and recursive function for this problem.
For iterative function, read one digit at a time 
and put all the possible alphabet combination to a result string vector. 
Each time when we update the result, 
we need to set a temporary string vector 
and then replace it with result to prevent result having a 'power set' of letter combinations.
For recursive function, we need a helper function to recursively call itself. 
As same as iterative way, we read one alphabet at a time, put it into the temp string, 
and then recursively call the function to read next alphabet. 
When the length of temp string reaches what we want, put it into the result string vector.
*/