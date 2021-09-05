#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
 public:
  int getDays(vector<int>& weights, int capacity) {
    int days = 1, bucket = 0;
    for (auto w : weights) {
      bucket += w;
      if (bucket > capacity) {
        days++;
        bucket = w;
      }
    }
    return days;
  }

  int shipWithinDays(vector<int>& weights, int d) {
    int r = 0, l = 0;
    for (auto w : weights) {
      r += w;
      l = max(l, w);
    }
    l = max(l, r / d);  // i.e max(maxElement, avgOverD-Days);

    // Binary Search
    while (l < r) {
      int m = (l + r) / 2;
      if (getDays(weights, m) <= d)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
// @lc code=end
