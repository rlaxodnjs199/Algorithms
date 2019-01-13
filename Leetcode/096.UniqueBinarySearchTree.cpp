/*
Given integer n, return number of all possible unique binary search tree
composed of integer 1 ~ n. 
*/
#include <iostream>
class Solution {
  public:
    int UniqueBinarySearchTree(int n) {
      int dp[n+1];
      dp[0] = 1; // {}
      dp[1] = 1; // {1}
      for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
          dp[i] += dp[j-1] * dp[i-j];
        }
      }
      return dp[n];
    }
};