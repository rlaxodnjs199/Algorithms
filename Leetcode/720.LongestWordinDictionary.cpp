/*
1. Idea
First, we sort a vector of strings to ensure shortest length
element comes first and arranged in alphabetical order.
We need hashset to build up dictionary with only valid words.
When length of string is 1 or substring of it with length-1 is
already in the dictionary, we put it into the dictionary and
update answer.
O(nlogn) runtime, O(nk) space where k is average length of words.
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
class Solution1 {
  public:
  std::string LongestWordinDictionary(std::vector<std::string> words) {
    std::string result;
    std::unordered_set<std::string> hashset;
    std::sort(words.begin(), words.end());
    for (std::string s : words) {
      if (s.size() == 1 || hashset.count(s.substr(0, s.size()-1))) {
        hashset.insert(s);
        result = result.size() < s.size() ? s : result;
      }
    }
    return result;
  }
};

struct comparison {
  bool operator()(const std::string& s1, const std::string& s2) {
    if (s1.size() == s2.size()) {
      return s1 < s2;
    }
    return s1.size() > s2.size();
  }
};
class Solution2 {
  public:
  std::string LongestWordinDictionary(std::vector<std::string> words) {
    std::string result;
    std::sort(words.begin(), words.end(), comparison());
    std::unordered_set<std::string> hashset;
    for (std::string s : words) {
      hashset.insert(s);
    }
    for (std::string s : words) {
      if (result.size() < s.size()) {
        if (isValid(hashset, s)) {
          result = s;
        }
      }
      else {
        return result;
      }
    }
    return result;
  }
  bool isValid(const std::unordered_set<std::string>& hashset, std::string s) {
    for (int i = s.size()-1; i > 0; i--) {
      if (hashset.find(s.substr(0, i)) == hashset.end()) {
        return false;
      }
    }
    return true;
  }
};
int main() {
  Solution1 s1;
  std::vector<std::string> words = {"w", "wo", "wor", "worl", "world"};
  std::cout << s1.LongestWordinDictionary(words);
  Solution2 s2;
  std::cout << s2.LongestWordinDictionary(words);
}
