class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<vector<int>> result(size / 3, vector<int>(3));
        int groupIndex = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<size; i+=3) {
            if (i + 2 < size && nums[i+2] - nums[i] <= k) {
                result[groupIndex] = { nums[i], nums[i+1], nums[i+2] };
                groupIndex++;
            }
            
            else return vector<vector<int>>();
        }

        return result;
    }
}; 


