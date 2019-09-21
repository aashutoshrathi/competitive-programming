#include <iostream>
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;

int maxLen(int arr[], int n){
    int sum = 0;
    int len = INT_MIN;
    unordered_map<int ,int> mp;
    
    for(int i=0; i< n; i++) {
        sum += (arr[i] == 0) ? -1 : 1;
        if(sum==0) {
            len = max(len, i+1);
        }
        if(mp.find(sum) != mp.end()) {
            len = max(len, i-mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    if(len == INT_MIN)
        return 0;
    return len;
    
}