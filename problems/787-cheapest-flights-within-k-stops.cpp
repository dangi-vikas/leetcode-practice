class Solution {
    int minPrice = INT_MAX;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int>(n));
        queue<pair<int, int>> q;
        vector<int> visited(n, INT_MAX);

        for(auto flight : flights) 
            dp[flight[0]][flight[1]] = flight[2];
        
        q.push({src, 0});

        while(k >= 0 && !q.empty()) {
            int size = q.size();
            k--;

            for(int i=0; i<size; i++) {
                int source = q.front().first;
                int price = q.front().second;
                vector<int> nbrs = dp[source];

                q.pop();

                for(int node=0; node<n; node++) {
                    if(nbrs[node]) {
                        int dis = nbrs[node] + price;

                        if(node != dst && visited[node] > dis) {
                            q.push({node, dis});
                            visited[node] = dis;
                        }

                        else if(node == dst) 
                            minPrice = min(minPrice, dis);
                    }
                }
            }
        }

        return minPrice == INT_MAX ? -1 : minPrice;
    }
};