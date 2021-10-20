class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
		vector<int> container;

        sort(nums.begin(), nums.end());

		subsetsWithDupRec(ans, nums, container, 0);

		return ans;
    }
    
	void subsetsWithDupRec(vector<vector<int>>& ans, vector<int>& nums,
                 vector<int>& container, int index) {
        
        //pushing the subset in the ans array
		ans.push_back(container);
        
		for (int i = index; i < nums.size(); ++i) {
            
            //avoiding duplicates by not choosing the same number
            if(i!=index && (nums[i] == nums[i-1])) continue;

            //pushing the numbers in the temporary container
			container.push_back(nums[i]);

            //recursively traversing the nums for the next element
			subsetsWithDupRec(ans, nums, container, i + 1);

            //backtracking step
			container.pop_back();
        }
    }
};