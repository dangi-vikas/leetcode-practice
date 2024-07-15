class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int num : nums) freq[num]++;

        for(auto el : freq) {
            pq.push({el.second, el.first});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};