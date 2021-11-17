class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> container;
        
        combinationSum3Rec(1, k, n, ans, container);

        return ans;
    }
    
    //helper function to check combination recursively
    void combinationSum3Rec(int index, int k, int n, vector<vector<int>>& ans, vector<int>& container){
        
        //if the target is reached
        if(n == 0 && container.size()==k){
            ans.push_back(container);
            return;
        }
        
        //selecting the number from 1 to 9
        for(int i=index; i<=9; i++){
            
            //if the number is already greater than the target then breaking out of the loop
            if(i>n) break;

            //pushing in the temporary container
            container.push_back(i);

            //recursively checking for the next number if it is selectable
            combinationSum3Rec(i+1, k, n-i, ans, container);

            //backtracking step
            container.pop_back();
        }   
    }
};