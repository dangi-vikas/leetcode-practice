class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> container;
        
        sort(candidates.begin(), candidates.end());
       
        combinationSum2Rec(0, target, candidates, ans, container);
        
        return ans;
    }
    
    //helper function to check combination recursively
    void combinationSum2Rec(int index, int target, vector<int>& candidates, 
                           vector<vector<int>>& ans, vector<int>& container) {
        
        //if the target is reached
        if(target == 0) {
            ans.push_back(container);
            return;
        }
        
        //iterating for all the numbers in the array 
        for(int i=index; i<candidates.size(); i++) {
            
            //ignoring the repeatition of the numbers
            if(i>index && candidates[i]==candidates[i-1]) continue;
            
            //if the number is already greater than the target then breaking out of the loop
            if(candidates[i]>target) break;
            
            //pushing in the temporary container
            container.push_back(candidates[i]);

            //recursively checking for the next distinct number if it is selectable
            combinationSum2Rec(i+1, target-candidates[i], candidates, ans, container);
            
            //backtracking step: if the number is non selectable popping it back
            container.pop_back();
        }   
    }
};