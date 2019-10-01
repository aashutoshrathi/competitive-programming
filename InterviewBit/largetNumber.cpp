string largestNumber(const vector<int> &A) {
    unordered_map<long long, int> m;
    string s;
    for(int i=0; i<A.size(); i++) {
        long long rev = 0;
        long long temp = A[i];
        int j = 18;
        while(j--) {
            rev = rev*10 + temp%10;
            temp/=10;
        }
        m[rev] = A[i];
    }
    for(auto i: m) {
        s += to_string(i.second);
    }
    return s;
}
