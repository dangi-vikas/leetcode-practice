class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1, p2, p3, p4};
        unordered_set<double>uset; 
        
        for(int i=0; i<4; ++i) {
            for(int j=i+1; j<4; ++j) {
                double length = distance(points[i], points[j]);
                if (length == 0) return false;
                uset.insert(length);
            }
        }
        
        return uset.size() == 2;
    }
    
    double distance(vector<int>& p1, vector<int>& p2) {
        return sqrt((p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]));
    }
};