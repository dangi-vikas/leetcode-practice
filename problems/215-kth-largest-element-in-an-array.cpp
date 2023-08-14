//1st Approach
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());             //sorting the array
        
        //returning the kth last element from sorted array
        return nums[nums.size()-k];
    }
};

//2nd Approach
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        
        for(int num : nums) q.push(num);
        k--;
        while(k--) q.pop();

        return q.top();
    }
};