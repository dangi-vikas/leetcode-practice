class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> slopeMap;
        int maxPoints = 1;
        
        for(int i=0; i<points.size()-maxPoints; i++) {
            int currMax = 0;
            
            for(int j=i+1; j<points.size(); j++) {
                double slope;
                
                if(points[j][0] - points[i][0] == 0) 
                    slope = DBL_MAX;
                
                else slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                
                if(slopeMap.find(slope) != slopeMap.end()) 
                    slopeMap[slope]++;
                
                else slopeMap[slope] = 2;
                
                currMax = max(currMax, slopeMap[slope]);
            }
            
            slopeMap.clear();
            maxPoints = max(maxPoints, currMax);
        }
        
        return maxPoints;
    }
};  