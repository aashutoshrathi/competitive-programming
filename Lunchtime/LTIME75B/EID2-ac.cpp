#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define fj(a) for (int j = 0; j < a; ++j)

string solve(int a[], int c[]) {
    for(int i=0; i<3; i++) {
        fj(3) {
            if(a[i] == a[j]) {
                if(c[i] != c[j]) {
                    return "NOT FAIR";
                }
            }
            else if(a[i] > a[j]) {
                if(c[i] <= c[j]) {
                    return "NOT FAIR";
                }
            }

            else if(a[i] < a[j]) {
                if(c[i] >= c[j]) {
                    return "NOT FAIR";
                }
            }
        }
    }
    return "FAIR";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a[3], c[3];
        for(int i=0; i<3; i++)
            cin >> a[i];
        for(int i=0; i<3; i++)
            cin >> c[i];
        cout << solve(a ,c) << endl;       
    }

    return 0;
}