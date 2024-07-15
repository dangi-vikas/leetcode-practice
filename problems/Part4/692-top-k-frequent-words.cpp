class Solution {
    struct compare{
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> freqs;
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        
        for(int i=0; i<n; ++i) freqs[words[i]]++;
        
        for(auto it : freqs) pq.push({it.second,it.first});
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};