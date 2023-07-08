class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1) return 0;

        vector<long long> costs;
        long long left = 0, right = 0;

        for(int i=1; i<weights.size(); i++) 
            costs.emplace_back(weights[i-1] + weights[i]);

        sort(costs.begin(), costs.end());

        for(int i=0; i<k-1; i++) {
            left += costs[i];
            right += costs[costs.size()-i-1];
        }

        return (right - left);
    }
};