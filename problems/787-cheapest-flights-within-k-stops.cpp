    class Solution {
    int minPrice = INT_MAX;
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(auto flight : flights)
            dp[flight[0]][flight[1]] = flight[2];
        
        queue<vector<int>> q;
        q.push({src, 0});
        
        vector<int> visited(n, minPrice);
        
        while(k>=0 && !q.empty()) {
            k--;
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                vector<int> pair = q.front();
                q.pop();
                int source = pair[0];
                int price = pair[1];
                vector<int> next = dp[source];
                
                for(int d=0; d<n; d++) {
                    if(next[d]) {
                        int p = next[d] + price;
                        if(d != dst && visited[d] > p) {
                            q.push({d, p});
                            visited[d] = p;
                        }
                        
                        else if(d == dst) minPrice = min(minPrice, p);
                    }    
                }
            }
        }
        
        return minPrice == INT_MAX ? -1 : minPrice;
    }
};