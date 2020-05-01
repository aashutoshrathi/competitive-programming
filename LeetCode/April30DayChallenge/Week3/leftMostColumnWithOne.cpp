/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int a = size[0], b = size[1];
        int sol = b;
        for(int i=0; i<a; i++) {
            int lo = 0, hi = b-1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(binaryMatrix.get(i, mid) == 1) {
                    sol = min(sol, mid);
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return sol == b ? -1 : sol;
    }
};