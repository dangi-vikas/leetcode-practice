//Solution 1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            
            //finding the maximum profit by peak valley approach
            if(prices[i]>prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        
        return profit;
    }
};

//Solution 2

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3,0));
      
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<3; cap++){
                    int profit = 0;

                    if(buy == 1)
                       profit= max(-prices[idx] + next[0][cap], next[1][cap]);
                    
                    if(buy==0)
                        profit= max(prices[idx] + next[1][cap-1], next[0][cap]);
                    
                     next[buy][cap]= profit;
                }
            }
        }
        
        return next[1][2];
    }
};