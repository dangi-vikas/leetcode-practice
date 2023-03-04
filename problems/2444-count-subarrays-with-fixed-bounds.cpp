class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n = nums.size(), minI = -1, maxI =- 1, li =- 1;
        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                li = i;
                minI = -1;
                maxI = -1;
            }

            else {
                if(nums[i] == minK) minI = i;
                if(nums[i] == maxK) maxI = i;
                if(minI != -1 && maxI != -1) ans += min(minI, maxI) - li;
            }
        }

        return ans;
    }
};