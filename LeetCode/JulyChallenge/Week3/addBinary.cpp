#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size() - 1;
        int bLen = b.size() - 1;
        int k = 0;
        string res = "";
        bool carry = 0;
        while(k <= aLen || k <= bLen) {
            int val = (k <= aLen && a[aLen-k] == '1') + (k <= bLen && b[bLen-k] == '1') + carry;
            res = to_string(val%2) + res;
            carry = val >= 2;
            k++;
        }
        return (carry ? to_string(carry) : "") + res;
    }
};

int main() {
    Solution* s = new Solution();
    string a, b;
    cin >> a >> b;

    cout << s->addBinary(a, b) << endl;
    cout << "Correct: " << "110001" << endl;
    return 0;
}
