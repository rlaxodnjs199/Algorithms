#include <iostream>
std::vector<std::vector<int>> generateMatrix(int n) {
  std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
  std::vector<int> step = {n, n-1};
  std::vector<std::vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int num = 1;
  int row = 0;
  int col = -1;
  int idir = 0;
  while (step[idir%2]) {
    for (int i = 0; i < step[idir%2], i++) {
      row += dir[idir%4][0];
      col += dir[idir%4][1];
      result[row][col] = num++;
    }
    step[idir%2]--;
    idir++;
  }
  return result;
}