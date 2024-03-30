class Solution {
public:
    int slidingWindow(vector<int>&nums, int k){
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        unordered_map<int,int> counts;

        while(j < n) {
            counts[nums[j]]++;
            while(counts.size() > k) {
                counts[nums[i]]--;

                if(counts[nums[i]] == 0)
                    counts.erase(nums[i]);

                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};
