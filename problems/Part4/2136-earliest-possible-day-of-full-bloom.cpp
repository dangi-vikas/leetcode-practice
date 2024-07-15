class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> times;
        int ans = INT_MIN, time = 0;
        
        for(int i=0; i<plantTime.size(); i++)
            times.push_back({growTime[i], plantTime[i]});
        
        sort(times.begin(), times.end(), greater<pair<int, int>>());
        
        for(int i=0; i<times.size(); i++) {
            time += times[i].second;
            ans = max(ans, time + times[i].first);
        }
        
        return ans;
    }
};