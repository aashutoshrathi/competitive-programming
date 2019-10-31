#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> ss; 
        for(int i=0; i<nums.size(); i++) {
            int x = target-nums[i];
            if(ss.count(x)) {
                res.push_back(ss[x]);
                res.push_back(i);
                break;
            }
            ss[nums[i]] = i;
        }
        return res;
    }
};