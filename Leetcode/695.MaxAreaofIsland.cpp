#include <iostream>
#include <vector>
#include <algorithm>
void DFS(std::vector<std::vector<int>>& grid, int row, int col, int& sum) {
  if (grid[row][col]) {
    grid[row][col] = 0;
    sum++;
    if (row <= grid.size()) DFS(grid, row + 1, col, sum);
    if (row > 0) DFS(grid, row - 1, col, sum);
    if (col <= grid[0].size()) DFS(grid, row, col + 1, sum);
    if (col > 0) DFS(grid, row, col - 1, sum);
  }
}
int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  if (grid.empty()) return 0;
  int result = 0;
  int sum;
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[0].size(); col++) {
      if (grid[row][col]) {
        sum = 0;
        DFS(grid, row, col, sum);
        result = std::max(result, sum);
      }
    }
  }
  return result;
}
