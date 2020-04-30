class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = nums.size()-1;
        for(int i=res-1; i>=0; i--) {
            if(i+nums[i] >= res) {
                res = i;
            }
        }
        return res == 0;
    }
};