class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());             //sorting the array
        
        //returning the kth last element from sorted array
        return nums[nums.size()-k];
    }
};