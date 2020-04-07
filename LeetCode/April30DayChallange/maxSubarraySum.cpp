// April 3

int maxSubArray(vector<int>& nums) {
    int mmax = nums[0];
    int sum = nums[0];
    for(int i=1; i<nums.size(); ++i) {
        sum = max(sum + nums[i], nums[i]);
        mmax = max(mmax, sum);
    }
    return mmax;
}