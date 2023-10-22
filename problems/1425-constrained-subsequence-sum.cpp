class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        vector<int> maxSum = nums;
        priority_queue<pair<int, int>> pq;

        pq.push({maxSum[0], 0});

        for(int i=1; i<n; i++){
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            maxSum[i] = max(maxSum[i], nums[i] + pq.top().first);
            pq.push({maxSum[i], i});
            ans = max(ans, maxSum[i]);
        }

        return ans;
    }
};