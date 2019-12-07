#include <bits/stdc++.h>
using namespace std;
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(11)<<(x)
int main(){
    int t;
    cin >> t;
    while(t--){
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double x[4], y[4];
        x[0] = x1 + r1;
        y[0] = y1;
        x[1] = x1 - r1;
        y[1] = y1;
        x[2] = x1;
        y[2] = y1 + r1;
        x[3] = x1;
        y[3] = y1 - r1;
        bool check = false;
        for (int i=0; i<4; i++){
            double tatti = pow((x[i] - x2), 2) + pow((y[i] - y2), 2) - pow(r2, 2);
            if (tatti > 0){
                cout << "YES" <<endl;
                check = true;
                cout << fixed << setprecision(6) << x[i] << " " << y[i] << endl;
                break;
            }
        }
        if(!check) {
            cout << "NO" << endl;
        }
    }
}