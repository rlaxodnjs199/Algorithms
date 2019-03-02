/*
Given a triangle structure, find the minimum path sum from 
top to bottom. Each step you may move to adjacent numbers
on the row below.
*/
#include <iostream>
#include <algorithm>
#include <vector>
int triangle(std::vector<std::vector<int>> triangle) {
  std::vector<int> pathsum(triangle.size());
  pathsum = triangle.back();
  for (int i = triangle.size()-2; i >= 0; i--) {
    for (int j = 0; j < triangle[i].size(); j++) {
      pathsum[j] = std::min(pathsum[j], pathsum[j+1]) + triangle[i][j];
    }
  }
  return pathsum[0];
}