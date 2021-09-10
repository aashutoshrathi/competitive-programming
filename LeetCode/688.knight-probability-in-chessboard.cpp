#include <iostream>
/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
typedef pair<int, int> ip;
int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                   {-2, 1},  {-1, 2},  {1, 2},  {2, 1}};
class Solution {
 public:
  double helper(int n, int k, int r, int c,
                vector<vector<vector<double>>> &probs) {
    // first reject one outside the board
    if (r >= n || c >= n || r < 0 || c < 0) return 0;

    // now check if moves are over
    if (k == 0) return 1;

    // check if already computed
    if (probs[r][c][k] != -1) return probs[r][c][k];

    double total = 0;
    for (int i = 0; i < 8; i++) {
      total += helper(n, k - 1, r + moves[i][0], c + moves[i][1], probs);
    }

    total = total / 8;
    return probs[r][c][k] = total;
  }

  double knightProbability(int n, int k, int r, int c) {
    vector<vector<vector<double>>> dp(
        n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
    return helper(n, k, r, c, dp);
  }
};
// @lc code=end
