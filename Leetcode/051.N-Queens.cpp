/*
1. Idea
This is one of the most famous backtracking problem.
We use dfs to figure out possible answers.
we update vector<string> temp by recursion and only put it to the result
when (row == n) : row can reach n only when there is n queens in the temp.
when we place 1 queen in the certain row, we don't need to consider about
rest elements in the row, so we jump to the next row and save performance.
*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
  public:
    std::vector<std::vector<std::string>> SolveNQueen(int n) {
      std::vector<std::vector<std::string>> result;
      std::vector<std::string> temp(n, std::string(n, '.'));
      SolveNQueenUtil(result, temp, 0, n);
      return result;
    }
    void SolveNQueenUtil(std::vector<std::vector<std::string>>& result, std::vector<std::string>& temp, int row, int n) {
      if (row == n) {
        result.push_back(temp);
        return;
      }
      for (int col = 0; col < n; col++) {
        if (isValid(temp, row, col, n)) {
          temp[row][col] = 'Q';
          SolveNQueenUtil(result, temp, row+1, n);
          temp[row][col] = '.';
        }
      }
    }
    bool isValid(std::vector<std::string>& temp, int row, int col, int n) {
      for (int i = 0; i < row; i++) {
        if (temp[i][col] == 'Q') return false;
      }
      for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (temp[i][j] == 'Q') return false;
      }
      for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (temp[i][j] == 'Q') return false;
      }
      return true;
    }

    int SolveNQueenNumber(int n) {
      std::vector<std::string> temp(n, std::string(n, '.'));
      int count = 0;
      SolveNQueenUtil(temp, count, 0, n);
      return count;
    }
    void SolveNQueenUtil(std::vector<std::string>& temp, int& count, int row, int n) {
      if (row == n) {
        count++;
        return;
      }
      for (int col = 0; col < n; col++) {
        if (isValid(temp, row, col, n)) {
          temp[row][col] = 'Q';
          SolveNQueenUtil(temp, count, row+1, n);
          temp[row][col] = '.';
        }
      }
    }
    bool isValid(std::vector<std::string>& temp, int row, int col, int n) {
      for (int i = 0; i < row; i++) {
        if (temp[i][col] == 'Q') return false;
      }
      for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (temp[i][j] == 'Q') return false;
      }
      for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (temp[i][j] == 'Q') return false;
      }
      return true;
    }
};
int main() {
  Solution s;
  std::vector<std::vector<std::string>> result = s.SolveNQueen(4);
  for (auto& s : result) {
    for (auto& sr : s) {
      for (auto& sc : sr) {
        std::cout << sc << " ";
      }
      std::cout << std::endl;
    }
    std::cout<< std::endl;
  }
}