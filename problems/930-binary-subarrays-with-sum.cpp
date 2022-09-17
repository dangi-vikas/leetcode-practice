class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, currSum = 0;
        unordered_map<int, int> sums;

        sums[0] = 1;

        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            ans += sums[currSum - goal];
            sums[currSum]++;
        }

        return ans;
    }
};
