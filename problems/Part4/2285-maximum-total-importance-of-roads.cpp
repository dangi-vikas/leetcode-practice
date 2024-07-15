class Solution {
    typedef long long ll;
    
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> degree(n, 0);
        ll ans = 0;

        for(auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        sort(degree.begin(), degree.end());
        
        for(ll i=0; i<n; i++) {
            ans += ((i+1) * degree[i]);
        }
        
        return ans;
    }
};
