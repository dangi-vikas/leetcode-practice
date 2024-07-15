class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        unordered_map<int, int> s;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++) s[dist(points[i], points[j])]++; 
            for (auto x : s) ans += (x.second) * (x.second-1);  
            s.clear();
        }
        
        return ans;
    }
    
    int dist (vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
};