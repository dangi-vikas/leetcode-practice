class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> ratio;
        int n = quality.size();
        
        for(int i=0; i<n; i++) 
            ratio.emplace_back((double)(wage[i]) / quality[i], i);
            
        sort(begin(ratio), end(ratio));
        
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double maxRate = 0.0;
        
        for(int i=0; i<k; i++) {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);
        }

        double ans = maxRate * qualitySum;
        
        for(int i=k; i<n; i++) {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= maxHeap.top(); 
            maxHeap.pop();

            qualitySum += quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);
            ans = min(ans, maxRate * qualitySum);
        }

        return ans;
    }
};
