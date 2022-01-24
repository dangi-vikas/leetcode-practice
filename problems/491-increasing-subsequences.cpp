class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> container;
        
        findSubsequencesRec(nums, ans, container, 0);
        
        return ans;
    }
    
    void findSubsequencesRec(vector<int>& nums, vector<vector<int>>& ans, vector<int>& container, int index){
        if(container.size() > 1)
            ans.push_back(container);
        
        unordered_set<int> track;
        
        for(int i=index; i<nums.size(); i++){
            if((container.empty() || container.back() <= nums[i]) && track.find(nums[i]) == track.end()) {
                container.push_back(nums[i]);
                findSubsequencesRec(nums, ans, container, i+1);
                container.pop_back();
                track.insert(nums[i]);
            }   
        }
    }
};