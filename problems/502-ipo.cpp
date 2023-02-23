class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        int j = 0;
        priority_queue<int> maxProfit;

        for(int i=0; i<n; i++)
            projects[i] = {capital[i], profits[i]};
        
        sort(projects.begin(), projects.end());

        while(k--) {
            while(j < n && projects[j].first <= w) {
                maxProfit.push(projects[j].second);
                j++;
            }

            if(maxProfit.empty()) break;

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};