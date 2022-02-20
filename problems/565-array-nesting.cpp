class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int ans=0, currMax=0;
        
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                currMax = dfs(visited, nums, nums[i]);
                ans = max(ans,currMax);
            }
        }
        
        return ans;
    }
    
    int dfs(vector<bool>& visited, vector<int>& nums, int num) {
        if(visited[num]) return 0;
        visited[num] = true;
        return 1 + dfs(visited, nums, nums[num]);
    }
};