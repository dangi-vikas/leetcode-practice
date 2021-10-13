class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        permuteRec(nums, 0, ans);
        
        return ans;
    }
    
    void permuteRec(vector<int> nums, int index, vector<vector<int>>& ans){
        
        //base condition: if the index reaches the nums size
        if(index == nums.size()-1){
            
            //pushing the permutation in the ans array
            ans.push_back(nums);
            
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            
            //for skipping the repeated number
            if(i!=index && nums[index]==nums[i]) continue;

            //swapping the numbers to get different permutations
            swap(nums[i], nums[index]);

            //incrementing the index to make permutation with next number
            permuteRec(nums, index+1, ans);
        }
    }
};