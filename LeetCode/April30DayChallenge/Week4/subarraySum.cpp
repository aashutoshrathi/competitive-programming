class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums; 
        int res = 0; 
        int cs = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++) { 
            cs += nums[i]; 

            if (cs == k)  
                res++;         

            if (sums.find(cs - k) != sums.end())  
                res += (sums[cs - k]); 

            sums[cs]++; 
        } 

        return res;
    }
};