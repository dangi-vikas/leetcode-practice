class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans = INT_MAX, fin;

        for(int i=0; i<prices.size(); i++) {
            for(int j=0; j<prices.size(); j++) {
                if (i != j) {
                    int sum = prices[i] + prices[j];
                    ans = min(ans, sum);
                }
            }
        }
       
        fin = money - ans;
        
        return (fin >= 0) ? fin : money;
    }
};
