#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        int res = 0;
        int hi = n-1;
        int lo = 0;
        int loMax = INT_MIN;
        int hiMax = INT_MIN;
        while(lo <= hi) {
            if(height[lo] < height[hi]) {
                if(height[lo] > loMax)
                    loMax = height[lo];
                else
                    res += loMax - height[lo];
                lo++;    
            } else {
                if(height[hi] > hiMax)
                    hiMax = height[hi];
                else
                    res += hiMax - height[hi];
                hi--;
            }          
        }
        
        return res;
    }
};