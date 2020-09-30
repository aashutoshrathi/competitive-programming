class Solution {
public:
    string reverseWords(string s) {
        string result = "", temp;
        stringstream fortyTwo(s);
        while(fortyTwo >> temp){
            result = temp + " " + result;
        }
        return result.substr(0, result.size()-1);
    }
};
