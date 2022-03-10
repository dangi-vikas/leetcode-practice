class Solution {
    map<vector<int>, int> dp;
    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffersRec(price, special, needs);
    }
    
    int shoppingOffersRec(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp.find(needs) != dp.end())
            return dp[needs];
        
        int ans = INT_MAX;
        
        for(auto offer : special) {
            bool flag = true;
            
            for(int i=0; i<needs.size(); i++) {
                needs[i] -= offer[i];
                if(needs[i] < 0) flag = false;
            }
            
            if(flag) 
                ans = min(ans, offer[needs.size()] + shoppingOffersRec(price, special, needs));
            
            for(int i=0; i<needs.size(); i++) 
                needs[i] += offer[i];
            
        } 
        
        int temp = 0;
        
        for(int i=0; i<needs.size(); i++)
            temp += needs[i] * price[i];

        ans = min(ans, temp);
        
        return dp[needs] = ans;
    }
};