#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int fb = INT_MAX;
    int sb = INT_MAX;
    int fs = 0;
    int ss = 0;

    for (int i = 0; i < n; i++) {
      fb = min(fb, prices[i]);
      fs = max(fs, prices[i] - fb);

      sb = min(sb, prices[i] - fs);
      ss = max(ss, prices[i] - sb);
    }

    return ss;
  };
};
// @lc code=end
