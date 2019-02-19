/*
Problem:
Given a string containing only digits, restore it by
returning all possible combinations of IP address.
*/
#include <iostream>
#include <vector>
#include <string>
void restoreIP_helper(std::vector<std::string>& result, std::string temp, std::string& s, int begin, int partition) {
  if (begin == s.size()) {
    if (partition == 4) {
      temp.pop_back();
      result.push_back(temp);
    }
    return;
  }
  if (s.size() - begin > (4-partition)*3) return;
  for (int i = begin, num = 0; i < begin + 3; i++) {
    num = num * 10 + (s[i] - '0');
    if (num <= 255) {
      temp.push_back(s[i]);
      restoreIP_helper(result, temp + '.', s, i + 1, partition + 1);
    }
    if (num == 0) break;
  }
}
std::vector<std::string> restoreIP(std::string s) {
  std::vector<std::string> result;
  std::string temp;
  restoreIP_helper(result, temp, s, 0, 0);
  return result;
}
int main() {
  std::string s = "25525511135";
  std::vector<std::string> result = restoreIP(s);
  for (auto s : result) {
    std::cout << s << std::endl;
  }
}