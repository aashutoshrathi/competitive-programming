class Solution {
public:
    void sortColors(vector<int>& nums) {
        int oneStart = 0;
        int oneEnd = nums.size()-1;
        for(int i=0; i<=oneEnd;) {
            if(!nums[i]) {
                swap(nums[i++], nums[oneStart++]);
            } else if(nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[oneEnd--]);
            }
        }
        
    }
};

