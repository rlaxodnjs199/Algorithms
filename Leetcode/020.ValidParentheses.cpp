#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
class Solution {
  public:
    bool isValid(std::string s) {
      std::stack<char> stk;
      std::unordered_map<char, char> table;
      table[']'] = '[';
      table[')'] = '(';
      table['}'] = '{';
      if (s.empty()) return true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
          stk.push(s[i]);
        }
        else {
          if (!stk.empty() && stk.top() == table[s[i]]) {
            stk.pop();
          }
          else {
            return false;
          }
        }
      }
      return stk.empty();
    }
};
int main() {
  Solution s;
  std::string str = "(){}[]";
  if (s.isValid(str)) {
    std::cout << "Valid" << std::endl;
  }
  else {
    std::cout << "Invalid" << std::endl;
  }
}

/*
1. Idea
To be a valid parentheses, they have to present in a right order.
Stack is a great way to store intermediate results since we need FILO structure.
I also used unordered_map to store valid pair of parentheses, one as a key and the other as a value.
We return true only when the string is empty at the beginning or successfully becomes empty after passing through the string.
2. Special case
When the string is empty at the beginning, we can return true.
When the string is size of 1 at the beginning, we can return false.
However there is more neat way to do this other than writing one more if statement.
That is (!stk.empty() && stk.top() == table[s[i]]) condition statement.
Because of !stk.empty(), when any of invalid single char is left in the stack, it can return false. 
*/ 