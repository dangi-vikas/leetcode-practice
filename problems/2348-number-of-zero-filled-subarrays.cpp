class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long ans = 0, subarrayAtIdx = 0;

        for(int num : nums) {
            if(num == 0) ans += ++subarrayAtIdx;
            else subarrayAtIdx = 0;
        }

        return ans;
    }
};