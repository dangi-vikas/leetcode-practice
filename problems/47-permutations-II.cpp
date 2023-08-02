class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        permuteRec(nums, 0, ans);
        
        return ans;
    }
    
    void permuteRec(vector<int> nums, int ind, vector<vector<int>>& ans){
        
        //base condition: if the ind reaches the nums size
        if(ind == nums.size()-1){
            
            //pushing the permutation in the ans array
            ans.push_back(nums);
            
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            
            //for skipping the repeated number
            if(i!=ind && nums[ind]==nums[i]) continue;

            //swapping the numbers to get different permutations
            swap(nums[i], nums[ind]);

            //incrementing the ind to make permutation with next number
            permuteRec(nums, ind+1, ans);
        }
    }
};