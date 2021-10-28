class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        //starting conditions
        int buy = prices.front();
        int sell = prices[1];
        
        int currProfit = INT_MIN;
        int maxProfitPrice = max(INT_MIN, sell - buy);
        
        //iterating through the prices vector
        for (int i = 1; i < prices.size(); i++) {
            
            //finding the minimum buying price
            if (prices[i] < buy) {
                buy = prices[i];
                sell = buy;
            } 

            else sell = prices[i];
            
            currProfit = sell - buy;

            //getting the maximum profit
            maxProfitPrice = max(maxProfitPrice, currProfit);
        }
        
        return maxProfitPrice;
    }
};