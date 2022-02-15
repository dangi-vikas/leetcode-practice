class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvince = 0;
        
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j] == 1) {
                    numProvince++;
                    dfs(isConnected, i, j);
                }
            }
        }
        
        return numProvince;
    }
    
    void dfs(vector<vector<int>>& isConnected, int& i, int& j) {
        isConnected[i][j] = 0;
        
        for(int k=0; k<isConnected.size(); k++) 
            if(isConnected[j][k] == 1)
                dfs(isConnected, j, k);
    }
};