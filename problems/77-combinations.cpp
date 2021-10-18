class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> container;

        combineRec(ans, container, 1, n, k);

        return ans;
    }
    
    void combineRec(vector<vector<int>>& ans, vector<int>& container, int index, 
                    int n, int k){
        
        //if the temporary container is of size k
        if(container.size()==k){

            //pushing it in the ans vector of vectors
            ans.emplace_back(container);

            return;
        }
        
        //iterating for different combinations of numbers
        for(int i=index; i<n+1; i++){

            //pushing the numbers in the temporary container
            container.emplace_back(i);

            //recursively traversing the numbers greater than the current
            combineRec(ans, container, i+1, n, k);

            //backtracking step
            container.pop_back();
        }
    }
};