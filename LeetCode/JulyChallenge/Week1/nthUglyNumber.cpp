class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums = { 1 };
        int iTwo = 0, iThree = 0, iFive = 0;
        while(nums.size() < n) {
            int val = min({ 2*nums[iTwo], 3*nums[iThree], 5*nums[iFive] });
            
            nums.push_back(val);
            
            if(val == 2*nums[iTwo])
                iTwo++;
            if(val == 3*nums[iThree])
                iThree++;
            if(val == 5*nums[iFive])
                iFive++;
        }
        return nums[n-1];
    }
};
