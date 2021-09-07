#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    m[0] = -1;
    int res = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i] == 0 ? -1 : 1;
      if (m.find(sum) != m.end())
        res = max(res, i - m[sum]);
      else
        m[sum] = i;
    }
    return res;
  }
};
// @lc code=end
