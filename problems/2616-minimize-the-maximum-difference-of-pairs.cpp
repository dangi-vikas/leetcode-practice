class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[nums.size()-1] - nums[0];

        while (low < high) {
            int midDiff = low + ((high - low) >> 1);

            if (isFeasible(nums, p, midDiff)) high = midDiff;
            else low = midDiff + 1;
        }

        return low;
    }

    bool isFeasible(vector<int>& nums, int p, int diff) {
        int count = 0;
        int i = 0;

        while (i < nums.size()-1 && count < p) {
            if (nums[i+1] - nums[i] <= diff) {
                count++;
                i += 2;
            } 
            
            else i++;
        }

        return count >= p;
    }
};