#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> res(32, 0);
        int num = 0;
        
        for(int i: nums)
            for(int j=31; j>=0; j--)
                res[j] += ((i & (1<<j)) != 0 );
        
        for(int i=31; i>=0; i--)
            num += (res[i]%3)*(1<<i);

        return num;
    }
};

int main() {
    Solution* obj = new Solution();
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    cout << obj->singleNumber(arr) << endl;
}