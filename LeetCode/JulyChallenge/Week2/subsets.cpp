class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        // Since the subsets will be 2^n
        // It will be basically bitmasks from 2^n to 2^n+1
        for (int i = (1 << n); i < (1 << n+1); i++) {
          vector<int> tmp;
          for (int j = 0; j < n; j++) {
            if (i & (1 << j)) 
                tmp.push_back(nums[j]);
          }
          res.push_back(tmp);
        }
        return res;
    }
};
