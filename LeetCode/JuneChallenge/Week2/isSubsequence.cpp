class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i=0, j=0;
        // Traverse through both strings
        // and always increase iterator for bigger one
        // but only increase smaller one's iterator
        // if a charachter matches
        while(i<n && j<m) {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == n;
    }
};