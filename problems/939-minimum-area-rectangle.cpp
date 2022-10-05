class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, unordered_map<int>> m;
        
        for(vector<int> p : points) m[p[0]].insert(p[1]);
        
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                int x1 = points[i][0];  
                int y1 = points[i][1];  
                int x2 = points[j][0];  
                int y2 = points[j][1];
            }
            
            if((x != x2) && (y2 != y1))
                if(m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x2].end())
                    ans = min(ans, abs(x1-x2) * abs(y1-y2));
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};