class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int rc = 0;
        for(vector<int> i: shift) {
            rc += (i[0] == 1 ? i[1] : -1*i[1]);
        }
        int x = s.size();
        if(rc > 0)
            x = s.size() - (rc)%s.size();
        else if(rc < 0)
            x = (-1*rc)%s.size();
        return s.substr(x) + s.substr(0, x); 
    }
};

// abcd -> cdab