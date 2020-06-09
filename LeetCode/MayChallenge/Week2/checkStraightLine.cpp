class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2)
            return true;
        
        int x1 = coordinates[1][0] - coordinates[0][0];
        int y1 = coordinates[1][1] - coordinates[0][1];
        
        // checking for cross product.
        for(int i=2; i<coordinates.size(); i++) {
            int x2 = coordinates[i][0]-coordinates[0][0];
            int y2 = coordinates[i][1] - coordinates[0][1];
            if(x1*y2 != y1*x2) {
                return false;
            }
        }
        
        return true;
        
    }
};

