class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        
        int noStock=0, inHand=-prices[0], sold=0;
        
        for(int i=1; i<n; i++){
            int temp1=noStock, temp2=inHand;
            
            noStock = max(noStock, sold);
            inHand = max(inHand, temp1-prices[i]);
            sold = temp2 + prices[i];
        }
        
        return max(noStock, sold);
    }
};