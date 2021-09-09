#include <iostream>
#include <string>
#include <vector>
/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.size(); i++) {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']--;
    }
    cnt[t[s.size()] - 'a']--;

    for (int i = 0; i < 26; i++) {
      if (cnt[i]) return 'a' + i;
    }
    return 'a';
  }
};
// @lc code=end
