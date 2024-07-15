class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> numsPairs(n, vector<int>(2));
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, totalSum = 0;

        for(int i=0; i<n; i++) {
            numsPairs[i][0] = nums2[i];
            numsPairs[i][1] = nums1[i];
        }

        sort(numsPairs.begin(), numsPairs.end(), [](const vector<int>&a, const vector<int>&b) { return b[0] < a[0]; });

        for(vector<int>& pair : numsPairs) {
            pq.push(pair[1]);
            totalSum += pair[1];

            if(pq.size() > k) {
                totalSum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) ans = max(ans, (totalSum * pair[0]));
        }

        return ans;
    }
};