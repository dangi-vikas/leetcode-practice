class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = ((double) (coordinates[1][1] - coordinates[0][1]) / (double) (coordinates[1][0] - coordinates[0][0]));

        int dx0 = (coordinates[1][0] - coordinates[0][0]);
        
        for(int i=2; i<coordinates.size(); i++) {
            int dx = (coordinates[i][0] - coordinates[i-1][0]);
            int dy = (coordinates[i][1] - coordinates[i-1][1]);

            if(dx == 0 && dx0 == 0) continue;
            if(((double) dy / (double) dx) != slope) return false;
        }

        return true;
    }
};