#include <iostream>
#include <vector>
/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
 public:
  static int eDist(vector<int> p) { return p[0] * p[0] + p[1] * p[1]; }

  struct CompareDistance {
    bool operator()(vector<int> const& p1, vector<int> const& p2) {
      return eDist(p1) > eDist(p2);
    }
  };

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, CompareDistance> Q(
        points.begin(), points.end());
    vector<vector<int>> res;

    while (!Q.empty() && k--) {
      res.push_back(Q.top());
      Q.pop();
    }
    return res;
  }
};
// @lc code=end
