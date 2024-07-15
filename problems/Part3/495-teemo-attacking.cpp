class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = duration;
        
        for(int i=1; i<timeSeries.size(); i++)
            count += min(duration, timeSeries[i] - timeSeries[i-1]);
        
        return count;
    }
};