#include <iostream>
#include <vector>
class Solution {
  public:
    int numIslands(std::vector<std::vector<char>>& grid) {
      if (grid.empty()) return 0;
      int grid_row_size = grid.size();
      int grid_col_size = grid[0].size();
      int num_islands = 0;
      for (int grid_row = 0; grid_row < grid.size(); grid_row++) {
        for (int grid_col = 0; grid_col < grid[0].size(); grid_col++) {
          if (grid[grid_row][grid_col] == '1') {
            isIslands(grid, grid_row, grid_col, grid_row_size, grid_col_size);
            num_islands++;
          }
        }
      }
      return num_islands;
    }
    void isIslands(std::vector<std::vector<char>>& grid, int grid_row, int grid_col, int grid_row_size, int grid_col_size) {
      grid[grid_row][grid_col] = '0';
      if (grid_row-1 >= 0 && grid[grid_row-1][grid_col] == '1') {
        isIslands(grid, grid_row-1, grid_col, grid_row_size, grid_col_size);
      }
      if (grid_row+1 < grid_row_size && grid[grid_row+1][grid_col] == '1') {
        isIslands(grid, grid_row+1, grid_col, grid_row_size, grid_col_size);
      }
      if (grid_col-1 >= 0 && grid[grid_row][grid_col-1] == '1') {
        isIslands(grid, grid_row, grid_col-1, grid_row_size, grid_col_size);
      }
      if (grid_col+1 < grid_col_size && grid[grid_row][grid_col+1] == '1') {
        isIslands(grid, grid_row, grid_col+1, grid_row_size, grid_col_size);
      }
    }
};
int main() {
  Solution s;
  std::vector<std::vector<char>> grid = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
  int result = s.numIslands(grid);
  std::cout << result << std::endl;
}

/*
1. Idea
When I first saw this problem, I was thinking about establishing
new 2D boolean array which matches the grid.
When we see grid[x][y] == '1' and it is not marked as visited yet,
we mark all the island area that we can reach 
from grid[x][y] in boolean array.
This is possible way of solving this problem but not optimized.
We need extra O(n) space for boolean array.
The more neat way of solving this problem is using DFS technique.
Rather than establishing boolean array, we can simply mark
visited grid area by modifying value to '0'.
In this way this area can only be visited once.
*/