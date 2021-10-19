class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
		vector<int> container;

		subsetsRec(ans, nums, container, 0);

		return ans;
    }
    
	void subsetsRec(vector<vector<int>>& ans, vector<int>& nums,
                 vector<int>& container, int index) {
        
        //pushing the subset in the ans array
		ans.push_back(container);
        
		for (int i = index; i < nums.size(); ++i) {
            
            //pushing the numbers in the temporary container
			container.push_back(nums[i]);

            //recursively traversing the nums for the next element
			subsetsRec(ans, nums, container, i + 1);

            //backtracking step
			container.pop_back();
        }
    }
};