#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<=1)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> ans;
        vector<int> parent(nums.size());
        parent[0] = 0;
        
        int countMax=1;
        int ansIndex = 0;
        
        for(int i=1; i<nums.size(); i++) {
            int val=0;
            int num = nums[i];
            parent[i] = i;
            for(int j=0; j<i; j++) {
                if(num%nums[j]==0) {
                    if(val<dp[j]) {
                        val = dp[j];
                        parent[i] = j;
                        if(countMax < val+1) {
                            countMax = val+1;
                            ansIndex = i;
                        }
                    }
                }
            }
            dp[i] = val+1;
        }
        
        for(int i=0; i< countMax; i++) {
            ans.push_back(nums[ansIndex]);
            ansIndex = parent[ansIndex];
        }
        
        return ans;
        
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> res = sol->largestDivisibleSubset(v);
    for(auto i: res)
        cout << i << " ";
}