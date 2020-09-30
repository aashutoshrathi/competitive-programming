#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;
// A A A B B C, n = 2

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        for(char i: tasks) {
            freq[i-'A']++;
            maxFreq = max(maxFreq, freq[i-'A']);
        }
        maxFreq--;

        int res = maxFreq*(n + 1);

        for(int f: freq)
            res -= min(maxFreq, f);
        return tasks.size() + max(0, res);
    }
};

int main() {
    vector<char> tasks;
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('A');
    tasks.push_back('B');
    tasks.push_back('B');
    tasks.push_back('B');
    int n = 0;
    Solution* sol = new Solution();
    cout << sol->leastInterval(tasks, n) << endl;
    return 0;
}