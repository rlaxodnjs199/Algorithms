/*
1. Idea
We need to make buy - sell to be maximum to make a
maximum profit. Setting maxprice = minprice = prices[0],
we have some choices while iterating through prices.
when we meet prices[i] > maxprice, than we can calculate
new profit corresponds to that certain minprice value.
when we meet prices[i] < minprice, we need to update both
minprice and maxprice because there is a possibility that
new minprice will generate a maximum profit with having
selling value less than maxprice.
All the maxprice has meaning correlated with its minprice pair.
*/
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
  public:
    int maxProfit(std::vector<int>& prices) {
      if (prices.size() < 2) return 0;
      int profit = 0;
      int minprice = prices[0];
      int maxprice = prices[0];
      for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > maxprice) {
          profit = std::max(profit, maxprice-minprice);
          maxprice = prices[i];
        }
        if (prices[i] < minprice) {
          minprice = prices[i];
          maxprice = prices[i];
        }
      }
      return profit;
    }
};