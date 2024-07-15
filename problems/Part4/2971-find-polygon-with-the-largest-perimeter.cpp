class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(auto num : nums) sum += num;
        
        for(int i=n-1; i>=2; i--){
            sum -= nums[i];
            
            if(sum > nums[i])
                return sum + nums[i];
        }
        
        return -1;
    }
};
