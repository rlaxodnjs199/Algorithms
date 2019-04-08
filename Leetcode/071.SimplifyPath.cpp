/*
Problem:
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
*/
#include <iostream>
#include <string>
#include <queue>
std::string simplifyPath(std::string path) {
  path.append('/');
  std::queue<std::string> q;
  std::string result = "";
  std::string temp = "";
  for (auto& c : path) {
    if (c == '/') {
      if (temp == "..") {
        if (!q.empty()) q.pop();
      }
      else if (temp != "." && temp != "") {
        q.push(temp);
      }
      temp = "";
    }
    else {
      temp.append(c);
    }
  }
  while (!q.empty()) {
    result.append('/');
    result.append(q.front());
    q.pop();
  }
  return result.size() == 0? "/" : result;
}