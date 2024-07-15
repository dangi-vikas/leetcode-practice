class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        permuteRec(nums, 0, ans);

        return ans;
    }
    
    void permuteRec(vector<int>& nums, int index, vector<vector<int>>& ans){
        
        //base condition: if the index reaches the nums size
        if(index == nums.size()){
            
            //pushing the permutation in the ans array
            ans.push_back(nums);

            return;
        }
        
        for(int i=index; i<nums.size(); i++){

            //swapping the numbers to get different permutations
            swap(nums[i], nums[index]);

            //incrementing the index to make permutation with next number
            permuteRec(nums, index+1, ans);

            //Backtracking step
            swap(nums[i], nums[index]);
        }
    }
};