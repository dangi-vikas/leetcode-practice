class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vecA;
        vector<pair<int, int>> vecB;
        int ans = 0;
        map<pair<int, int>, int> mp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1) vecA.push_back({i,j});
                if(img2[i][j] == 1) vecB.push_back({i,j});
            }
        }
        
        
        for(auto [i1, j1] : vecA){
            for(auto [i2,j2] : vecB){
                mp[{i1-i2, j1-j2}]++;
                ans = max(ans, mp[{i1-i2, j1-j2}]);
            }
        }
        
        return ans;
    }
};