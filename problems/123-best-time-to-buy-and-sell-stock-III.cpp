class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(5, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=3; j>=0; j--) {
                if(j%2 == 0)
                    next[j] = max((-prices[i] + next[j+1]), next[j]);
                                          
                else next[j] = max((prices[i] + next[j+1]), next[j]);
            }
        }
        
        return next[0];
    }
};