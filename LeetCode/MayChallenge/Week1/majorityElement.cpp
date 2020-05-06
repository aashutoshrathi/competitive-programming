class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int res;
        for(auto i: nums) {
            m[i]++;
            if(m[i] > nums.size()/2) {
                res = i;
                break;
            }
        }
        return res;
    }
};

