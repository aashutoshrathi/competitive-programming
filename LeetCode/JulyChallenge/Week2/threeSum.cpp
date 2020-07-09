class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) 
            return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < n-2; ++i){
            if(i && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(!sum) {
                    vector<int> curr = { nums[i], nums[j], nums[k] };
                    res.push_back(curr);

                    while(j < k && nums[j] == curr[1]) {
                        j += nums[j] == curr[1];
                        k -= nums[k] == curr[2];
                    }

                }
                else if (sum < 0) 
                    j++;
                else 
                    k--;
            }
        }
        return res;
    }
};
