class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> container;
        
       
        combinationSumRec(0, target, candidates, ans, container);
        
        return ans;
    }

    //helper function to check combination recursively
    void combinationSumRec(int index, int target, vector<int>& candidates, 
                           vector<vector<int>>& ans, vector<int>& container){
        
        //if the index tries all possible number in array and target is reached 
        if(index==candidates.size()){
            if(target==0) ans.push_back(container);
            return;
        }
        
        //if the number is selectable 
        if(candidates[index] <= target){

            //pushing in the temporary container
            container.push_back(candidates[index]);

            //recursively checking for the same number if it is selectable
            combinationSumRec(index, target-candidates[index], candidates, ans, container);

            //backtracking step: if the number is non selectable popping it back
            container.pop_back();
        }
        
        //increasing the index for checking the next number
        combinationSumRec(index+1, target, candidates, ans, container);
    }
};