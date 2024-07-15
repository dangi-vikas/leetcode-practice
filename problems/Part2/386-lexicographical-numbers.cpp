class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int i;
        
        for(i=1; i<10; i++)
            dfs(i, n, ans);
            
        return ans;
    }
    
    void dfs(int i, int n, vector<int>& ans){
        if(i>n) return;
        
        ans.push_back(i);
        
        for(int j=0; j<10; j++)
            dfs((i*10) + j, n, ans);
    }
};