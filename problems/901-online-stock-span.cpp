class StockSpanner {
    stack<pair<int, int>> stocks;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        
        while(!stocks.empty() && price >= stocks.top().first) {
            ans += stocks.top().second;
            stocks.pop();
        }
        
        stocks.push({price, ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */